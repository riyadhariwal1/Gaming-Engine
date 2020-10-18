add_library(ruleClasses)
target_sources(ruleClasses
  PRIVATE
    GlobalMessage.cpp
)
target_include_directories(ruleClasses
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(ruleClasses PRIVATE gameState)
