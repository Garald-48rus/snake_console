#include "field.h"
#include <iostream>
#include <algorithm>

field::field() {}
//===================================
void field::add_counter(){
    counter++;
}
//===============================================
int field::get_counter(){
    return counter;
}
//============================================
void field::draw_field(std::pair<int, int> const &pointer, Snake &snake){


    if(!fl){ add_counter();}

    std::cout << "Управление: 'w', 's', 'd', 'a', пауза 'p', выйти 'e'" << std::endl;
    std::cout  << "Очки: " << get_counter();
    std::cout << std::endl ;

    for (int rw = 0; rw <= ROWS; ++rw) {

        for (int cl = 0; cl <= COLS; ++cl) {

            if(cl == 0  || cl == COLS || rw == 0 || rw == ROWS ) {std::cout << "\033[0m"  << '#';}

            else if (std::find(snake.get_snake().begin() , snake.get_snake().end() , std::pair{rw,cl}) != snake.get_snake().end()) {
                std::cout  << "\033[1;32m" << '*' ;
            }
            else if(pointer == std::pair{rw, cl} && fl) {
                std::cout << "\033[1;34m" << '*';
            }
            else {
                std::cout << ' ';
            }


        }

        std::cout <<'\n';
    }

}
//==============================
int field::get_rows(){
    return ROWS;
}
//==============================
int field::get_cols(){
    return COLS;
}


