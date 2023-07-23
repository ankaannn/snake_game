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
    Board m_board; 
    Food m_food;   
};