#pragma once
#include "model/snake.h"
#include "model/board.h"
#include "model/food.h"

class Game{
    public:
    Game(int board_width, int board_height);
    void run_game(); 
    void read_keyboard(); 
    private:
    int m_board_width; 
    int m_board_height; 
    Snake m_snake;
    Food m_food;
    Board m_board; 
       
};