#include "snake.h"
#include <algorithm>



 Snake::Snake()
{
     mv = move::rigth;
    _snake.reserve(1000);
    _snake.push_back({1, 1});
    _snake.push_back({1, 2});
    _snake.push_back({1, 3});
}

//==========================================
void Snake::left(const std::pair<int, int> & p, bool &fl){


    auto tmp = _snake.back();
    tmp.second -= 1;

    if(tmp.second == 0){
        gm = false;
    }
    else if (std::find(_snake.begin(), _snake.end(), tmp) != _snake.end() &&
               tmp != _snake.front()) {
        gm = false;
    }


   else if(tmp == p){
        _snake.push_back(tmp);
        tmp = _snake.back();
        tmp.second -= 1;
        fl = false;
    }

    else {


        for (auto it = _snake.rbegin(); it != _snake.rend(); ++it) {

            it->swap(tmp);

        }
    }
}
//=======================================
void Snake::rigth(const std::pair<int, int> & p, bool &fl, int const & col)
{

    auto tmp = _snake.back();
    tmp.second += 1;
    if(tmp.second == col){
        gm = false;
    }
    else if (std::find(_snake.begin(), _snake.end(), tmp) != _snake.end() &&
               tmp != _snake.front()) {
        gm =false;
    }
   else if(tmp == p){
        _snake.push_back(tmp);
        tmp = _snake.back();
        tmp.second += 1;
        fl = false;
    }
    else {
        for (auto it = _snake.rbegin(); it != _snake.rend(); ++it) {

            it->swap(tmp);

        }
    }


}
//================================================
void Snake::up(const std::pair<int, int> & p, bool &fl){

    auto tmp = _snake.back();
    tmp.first -= 1;

    if(tmp.first == 0){
        gm = false;
    }
    else if (std::find(_snake.begin(), _snake.end(), tmp) != _snake.end() &&
               tmp != _snake.front()) {
        gm =false;
    }

   else if(tmp == p){
        _snake.push_back(tmp);
        tmp = _snake.back();
        tmp.first -= 1;
        fl = false;
    }

    else {
        for (auto it = _snake.rbegin(); it != _snake.rend(); ++it) {

            it->swap(tmp);

        }
    }


}
///================================================
void Snake::down(const std::pair<int, int> & p, bool &fl, int const& row){

    auto tmp = _snake.back();
    tmp.first += 1;

    if(tmp.first == row){
        gm = false;
    }
    else if (std::find(_snake.begin(), _snake.end(), tmp) != _snake.end() &&
               tmp != _snake.front()) {
        gm =false;
    }
    else if(tmp == p){
        _snake.push_back(tmp);
        tmp = _snake.back();
        tmp.first += 1;
        fl = false;
    }

    else {
        for (auto it = _snake.rbegin(); it != _snake.rend(); ++it) {

            it->swap(tmp);

        }
    }


}
//========================================
void Snake::add(std::pair<int, int> p){

    _snake.push_back(p);

}
//================================================
const std::vector <std::pair<int, int>>& Snake::get_snake()const {


    return  _snake;
}

//====================================================
void Snake::set_move(char const &ch){


    if(ch == 'd' && mv != move::left){
        mv = move::rigth;
    }
    else if (ch == 'a' && mv != move::rigth) {

        mv = move::left;
    }
    else if (ch == 'w' && mv != move::down) {
        mv = move::up;
    }
    else if(ch == 's' && mv != move::up) {
        mv = move::down;
    }
    else if(ch == 'p' ) {
        mv = move::pause;
    }
    else if(ch == 'e' ) {
        mv = move::ext;
    }
}
//=================================================





