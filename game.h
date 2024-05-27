#ifndef GAME_H
#define GAME_H
#include "field.h"
#include <utility>
#include <memory>
#include <thread>


using namespace std::chrono_literals;

class Game
{
public:
    Game();
    void game();
    void getch();
    int get_count();

private:
    const int& get_speed();
    void set_speed();
    void get_point(std::pair<int, int> &);
    const char& get_buf() const;
    bool g{true};


private:
    char buf;
    int speed{800};
    std::unique_ptr<field> _field = std::make_unique<field>();
    std::unique_ptr<Snake> _snake = std::make_unique<Snake>();


};



#endif // GAME_H
