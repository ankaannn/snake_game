#pragma once
#include <vector>

class Cell{
public:
    Cell(int x_value, int y_value);
    int get_x(); 
    int get_y(); 
private: 
    int m_x_value;
    int m_y_value;
};

enum Direction{
    Left = 0,
    Right,
    Up,
    Down
};

class Snake{
public: 
    Snake();
    std::vector<Cell> get_cells();
    void update_cells(); 
private:
    std::vector<Cell> m_cells;
    int m_current_direction; 
};