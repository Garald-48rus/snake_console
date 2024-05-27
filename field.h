#ifndef FIELD_H
#define FIELD_H

#include "snake.h"
#include <utility>



class field
{
public:
    field();

private:
    const int ROWS{15};
    const int COLS{35};
    int counter{0};


public:
    void add_counter();
    int get_counter();
    void draw_field(std::pair<int, int> const &, Snake &);
    int get_rows();
    int get_cols();
    void end_game();
    bool fl{false};
};

#endif // FIELD_H
