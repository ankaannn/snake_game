#include "model/food.h"

Food::Food(int x_value, int y_value): m_x_value(x_value), m_y_value(y_value){

}

int Food::get_x(){
    return m_x_value; 
}

int Food::get_y(){
    return m_y_value; 
}

void Food::set_x(int x){
    m_x_value = x; 
}

void Food::set_y(int y){
    m_y_value = y; 
}