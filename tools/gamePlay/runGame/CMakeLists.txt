add_library(runGame)
target_sources(runGame
  PRIVATE
    runGame.cpp
)
target_include_directories(runGame
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
target_link_libraries(runGame jsonParsing gameState Players ruleTree)
