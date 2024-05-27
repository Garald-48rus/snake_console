#include "game.h"
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <algorithm>
#include <thread>
#include <ctime>


using namespace std::chrono_literals;




Game::Game() {}
//=======================================
void Game::getch()
{

    while (true) {
        struct termios old = {};
        if (tcgetattr(0, &old) < 0)
            perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
            perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
            perror ("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
            perror ("tcsetattr ~ICANON");
        //return (buf);
    }
}
//=============================================
void Game::get_point(std::pair<int, int> &point)
{

    //
     do {
          srand(time(0));

        point.first = std::rand() % (_field->get_rows() - 1) + 0;
        point.second = std::rand() % (_field->get_cols() - 1) + 0;
     }while(std::find(_snake->get_snake().begin(), _snake->get_snake().end(), point) != _snake->get_snake().end());

}
//=======================================================
const char& Game::get_buf() const
{
    return buf;
}
//=========================================================
const int& Game::get_speed()
{
    return speed;
}
//============================================
void Game::set_speed()
{
    speed -= 10;
}
//=============================================================
int Game::get_count()
{
   return _field->get_counter();
}
//=================================================================
void Game::game(){

    std::thread th{&Game::getch, this};
    std::pair<int, int> point{1,1};
    Snake::move tmp;


    while (_snake->gm) {
        tmp = _snake->mv;

        if(_field->fl == false){
            get_point(point);
            set_speed();
            _field->fl = true;
        }

        _snake->set_move(get_buf());

        switch (_snake->mv)
      {
        case Snake::move::rigth:{

            _snake->rigth(point, _field->fl, _field->get_cols());
            break;
        }
        case Snake::move::left:{
            _snake->left(point, _field->fl);
            break;

        }
        case Snake::move::down:{
            _snake->down(point, _field->fl, _field->get_rows());
            break;

        }
        case Snake::move::up:{
            _snake->up(point, _field->fl);
            break;

        }
        case Snake::move::pause:{

            while ((get_buf() != 'e') && (get_buf() != 'c')) {

                std::cout << "\033[H\033[2J\033[3J" ;
                _field->draw_field(point, *_snake);
                std::cout << "Нажмите клавишу 'движения 'c' для продолжения или 'e' для выхода " << std::endl ;

                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }

            if(get_buf() == 'e'){
                _snake->gm = false;

            }
            else if (get_buf() == 'c') {
                _snake->mv = tmp;
            }
            break;
        }
        case Snake::move::ext:{
             _snake->gm = false;
            break;
        }

      }
        std::cout << "\033[H\033[2J\033[3J" ;
        _field->draw_field(point, *_snake);
        std::this_thread::sleep_for(std::chrono::milliseconds(get_speed()));
    }
    th.detach();
}









