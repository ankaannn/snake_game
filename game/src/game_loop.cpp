#include <iostream> 
#include "game/game_loop.h"
#include <windows.h> 

Game::Game(int board_width, int board_height)
: m_board_width(board_width), 
  m_board_height(board_height),
  m_snake(),
  m_food(5, 5),
  m_board(m_board_width, m_board_height, m_snake, m_food) {

}

void Game::run_game(){
    bool game_still_running = true;
    while(game_still_running){
        game_still_running = m_board.update_board(); 
        if(game_still_running){
            m_board.print_board(); 
        }
        Sleep(1);
    }
    std::cout << "Game over" << std::endl; 
}