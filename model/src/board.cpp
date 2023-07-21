#include "model/board.h"
#include "model/food.h"
#include <iostream>

Board::Board(int width, int height, Snake snake, Food food):m_width(width), m_height(height), m_board(), m_snake(snake), m_food(food), m_has_eaten(false){
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
    if(!add_snake_to_board()){
        std::cout << "game over, crash into snake" << std::endl; 
    }; 
    if(check_for_outside_board()){
        std::cout << "game over, outside the board" << std::endl;
    }      
    add_food_to_board();

    m_snake.update_cells(m_has_eaten);
    m_has_eaten = false;
    if(check_for_food()){
        m_has_eaten = true;
        change_food_place(); 
    } 
   
}

void Board::reset_board(){
    for(int i = 0; i < m_height; i++){
        for(int j = 0; j < m_width; j++){
            m_board[i][j] = 0;
        }
    }
}

//returns true if the board was painted out correctly 
bool Board::add_snake_to_board(){
    for(auto cell : m_snake.get_cells()){
        int y = cell.get_y(); 
        int x = cell.get_x(); 
        if(check_for_duplicates_cells(x, y)){
            return false; 
        }
        else{
            m_board[y][x] = 1; 
        }
    }
    return true;
}


void Board::add_food_to_board(){
    int y = m_food.get_y(); 
    int x = m_food.get_x(); 
    m_board[y][x] = 2;
} 

bool Board::check_for_food(){
    Cell cell_head = m_snake.get_cells()[0];
    int x = cell_head.get_x();
    int y = cell_head.get_y(); 
    if(m_board[y][x] == 2){
        return true; 
    }
    else{
        return false;
    }
    
}

void Board::change_food_place(){
    while(true){
        int new_x = rand() % m_width; 
        int new_y = rand() % m_height; 
        if(m_board[new_y][new_x] == 1){
            continue; 
        }
        else{
            m_food.set_x(new_x);
            m_food.set_y(new_y);
            break; 
        }
    }
}

//return true if snake is outside board
bool Board::check_for_outside_board(){
    for(auto cell : m_snake.get_cells()){
        if(cell.get_x() < 0 || cell.get_x() > m_width -1 || cell.get_y() < 0 || cell.get_y() > m_height -1){
            return true; 
        }
    }
    return false;
}


//return true if snakes cells are the same
bool Board::check_for_duplicates_cells(int x, int y){
    if(m_board[y][x] == 1){
        return true;
    }
    else{
        return false;
    }
}