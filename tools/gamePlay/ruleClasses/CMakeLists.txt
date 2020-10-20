add_library(ruleClasses)
target_sources(ruleClasses
  PRIVATE
    GlobalMessage.cpp
    Add.cpp
    Discard.cpp
    ForEachRule.cpp
    InputeChoice.cpp
    ParallelFor.cpp
    Extend.cpp
    WhenRule.cpp
    Scores.cpp
)
target_include_directories(ruleClasses
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(ruleClasses PRIVATE gameState Players)
