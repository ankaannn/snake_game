#include "model/board.h"
#include <iostream>

Board::Board(int width, int height, Snake snake, Food food):m_width(width), m_height(height), m_board(), m_snake(snake), m_food(food){
    for(int i = 0; i < height; i++){
        std::vector<int> row;
        for(int j = 0; j < width; j++){
            row.push_back(0);
        }
        m_board.push_back(row);
    }
    for(auto cell : snake.get_cells()){
        int x = cell.get_x();
        int y = cell.get_y(); 
        m_board[y][x] = 1; 
    }
}

void Board::print_board(){
    for(auto row : m_board){
        for(auto i : row){
            std::cout << i << " ";
        }
        std::cout << std::endl; 
    }
    std::cout << std::endl;
}

void Board::update_board(){
    reset_board(); 
    add_snake_to_board(); 
    add_food_to_board();

    m_snake.update_cells();   
}

void Board::reset_board(){
    for(int i = 0; i < m_height; i++){
        for(int j = 0; j < m_width; j++){
            m_board[i][j] = 0;
        }
    }
}

void Board::add_snake_to_board(){
    for(auto cell : m_snake.get_cells()){
        int y = cell.get_y(); 
        int x = cell.get_x(); 
        m_board[y][x] = 1; 
    }
}

void Board::add_food_to_board(){
    int y = m_food.get_y(); 
    int x = m_food.get_x(); 
    m_board[y][x] = 2;
} 