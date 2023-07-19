#include "model/board.h"
#include <iostream>

Board::Board(int width, int height):m_width(width), m_height(height), m_board(){
    for(int i = 0; i < height; i++){
        std::vector<int> row;
        for(int j = 0; j < width; j++){
            row.push_back(0);
        }
        m_board.push_back(row);
    }
}

void Board::print_board(){
    for(auto row : m_board){
        for(auto i : row){
            std::cout << i << " ";
        }
        std::cout << std::endl; 
    }
}

