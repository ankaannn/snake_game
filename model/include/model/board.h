#include <vector> 

class Board{
public:
    Board(int width, int height);
    void print_board();
private: 
    int m_width;
    int m_height;
    std::vector<std::vector<int>> m_board; 
};