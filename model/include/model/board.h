#pragma once
#include <vector> 
#include "model/snake.h"
#include "model/food.h"

class Board{
public:
    Board(int width, int height, Snake snake, Food food);
    void print_board();
    void update_board(); 
    void reset_board();
    void add_snake_to_board(); 
    void add_food_to_board(); 
    bool check_for_food();
    void change_food_place(); 
    void delete_food();     
private: 
    int m_width;
    int m_height;
    std::vector<std::vector<int>> m_board; 
    Snake m_snake;
    Food m_food;
    bool m_has_eaten;
};