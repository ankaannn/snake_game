project(snake)
add_executable(snake src/main.cpp)
target_link_libraries(snake
    model
    game    
)