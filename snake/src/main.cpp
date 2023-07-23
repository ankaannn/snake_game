#include <iostream> 
#include "model/board.h"
#include "model/food.h"
#include "game/game_loop.h"

int main(){
    std::cout << "hej" << std::endl;
    // Snake snake;
    // Food food(2, 2); 
    // Board board(10, 10, snake, food);
    // for(int i = 0; i < 6; i++){
    //     board.update_board(); 
    //     board.print_board();        
    // }
    Game game(10, 10); 
    game.run_game();
    
}