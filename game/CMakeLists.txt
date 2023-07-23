project(game)

add_library(game
    src/game_loop.cpp 
    include/game/game_loop.h
)

target_include_directories(game
PUBLIC
    include
)

target_link_libraries(game
    model    
)