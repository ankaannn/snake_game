#include <iostream> 
#include "model/board.h"
#include "model/food.h"

int main(){
    std::cout << "hej" << std::endl;
    Snake snake;
    Food food(2, 2); 
    Board board(10, 10, snake, food);
    for(int i = 0; i < 5; i++){
        board.update_board(); 
        board.print_board();        
    }
}