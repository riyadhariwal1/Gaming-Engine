add_library(gameState)
target_sources(gameState
  PRIVATE
    Game.cpp State.cpp
)

target_include_directories(gameState
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        )

#error: fatal error: Player.h: No such file or directory
target_link_libraries(gameState ruleTree Players jsonParsing)
