#pragma once
#include <vector> 

class Food{
public: 
    Food(int x_value, int y_value); 
    int get_x(); 
    int get_y();
    void set_x(int x); 
    void set_y(int y);  
private:
    int m_x_value; 
    int m_y_value;
};