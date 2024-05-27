#ifndef SNAKE_H
#define SNAKE_H

#include <utility>
#include <vector>

class Snake
{
public:
    Snake();


private:
    std::vector<std::pair<int ,int>> _snake;
public:
    enum class move{rigth = 0, left, up, down, pause, ext};
    bool gm{true};

public:
    void left(const std::pair<int, int> & p, bool &);
    void rigth(const std::pair<int, int> &, bool &, int const & );
    void up(const std::pair<int, int> & p, bool &);
    void down(const std::pair<int, int> & p, bool &, int const &);
    void add(std::pair<int , int>);


    void set_move(char const &);
    const std::vector <std::pair<int, int>>& get_snake() const;


    move mv;


};

#endif // SNAKE_H
