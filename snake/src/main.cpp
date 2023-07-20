#include <iostream> 
#include "model/board.h"
#include "model/food.h"

int main(){
    std::cout << "hej" << std::endl;
    Snake snake;
    Food food(10, 10); 
    Board board(20, 20, snake, food);
    board.update_board(); 
    board.print_board(); 
    board.update_board();
    board.print_board(); 


}