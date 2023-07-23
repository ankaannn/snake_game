#include <iostream> 
#include "game/game_loop.h"
#include <windows.h> 
#include <thread> 
#include <chrono>
#include <conio.h> 

Game::Game(int board_width, int board_height)
: m_board_width(board_width), 
  m_board_height(board_height),
  m_snake(),
  m_food(5, 5),
  m_board(m_board_width, m_board_height, m_snake, m_food) {

}

void Game::run_game(){
    bool game_still_running = true;
    std::thread thread_one (read_keyboard, this);
    m_board.print_board(); 
    while(game_still_running){
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        game_still_running = m_board.update_board(); 
        if(game_still_running){
            m_board.print_board(); 
        }
        
    }
    std::cout << "Game over" << std::endl;
    thread_one.join(); 
}

void Game::read_keyboard(){
    std::string input; 
    while(true){
        //std::cin >> input;
        input = _getch(); 
        std::cout << input << std::endl; 
        if(input == std::string("w")){
            m_snake.set_current_direction(Up); 
        }
        else if (input == std::string("a")){
            m_snake.set_current_direction(Left);
        }
        else if(input == std::string("s")){
            m_snake.set_current_direction(Down);
        }
        else if(input == std::string("d")){
            m_snake.set_current_direction(Right);
        }
        else if(input == std::string("z")){
            break;
        }
        else{
            std::cout << "bbbbaah";
        }
    }
}