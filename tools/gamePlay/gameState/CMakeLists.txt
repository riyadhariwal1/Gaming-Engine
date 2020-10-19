add_library(gameState)
target_sources(gameState
  PRIVATE
    GameState.cpp Game.cpp
)

target_include_directories(gameState
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        )

#target_link_libraries(gameState ruleClasses Players)