#include <iostream>

#include <game.h>

/*void getch(char &buf ) {
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
*/
int main()
{

    char ch{'y'};
    while (ch == 'y') {
        Game _game;
        _game.game();
        std::cout << "Ира окончена   Очки:  "<< _game.get_count() << std::endl;

        std::cout << "'y' - новая игра  'n' - выход" << std::endl;
        ch = std::getchar();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }





    return 0;
}
