project(model)

add_library(model
    src/board.cpp
    include/model/board.h
)

target_include_directories(model
PUBLIC
    include
)