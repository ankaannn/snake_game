#include "model/snake.h"



Cell::Cell(int x_value, int y_value): m_x_value(x_value), m_y_value(y_value){

}

int Cell::get_x(){
    return m_x_value;
}

int Cell::get_y(){
    return m_y_value;
}



Snake::Snake():m_cells(), m_current_direction(Left){
    m_cells.push_back(Cell(5, 5)); 

}

std::vector<Cell> Snake::get_cells(){
    return m_cells; 
}

void Snake::update_cells(){
    Cell new_head(0, 0);
    if(m_current_direction == Left){
        new_head = Cell(m_cells[0].get_x()-1, m_cells[0].get_y());
    }
    else if(m_current_direction == Right){
        new_head = Cell(m_cells[0].get_x()+1, m_cells[0].get_y());
    }
    else if(m_current_direction == Up){
        new_head = Cell(m_cells[0].get_x(), m_cells[0].get_y()-1);
    }
    else if(m_current_direction == Down){
        new_head = Cell(m_cells[0].get_x(), m_cells[0].get_y()+1);
    }
    m_cells.insert(m_cells.begin(), new_head);
    m_cells.pop_back();
}