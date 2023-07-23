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
    m_cells.push_back(Cell(4, 2)); 

}

std::vector<Cell> Snake::get_cells(){
    return m_cells; 
}

Cell Snake::get_head_cell(){
    return m_cells[0];
}

//if 0 --> cells moving forward and delete the last element
//if 1 --> snake have eating food --> do not delete the last element 
void Snake::update_cells(int flag){
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
    if(flag == 0){
        m_cells.pop_back();
    }
}

void Snake::set_current_direction(int direction){
    m_current_direction = direction;
}