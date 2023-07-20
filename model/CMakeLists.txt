project(model)

add_library(model
    src/board.cpp
    include/model/board.h
    src/snake.cpp
    include/model/snake.h
    src/food.cpp 
    include/model/food.h
)

target_include_directories(model
PUBLIC
    include
)