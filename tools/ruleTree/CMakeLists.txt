add_library(ruleTree)
target_sources(ruleTree PRIVATE
        GlobalMessage.cpp
       Add.cpp
       Discard.cpp
       ForEachRule.cpp
       InputChoice.cpp
       ParallelFor.cpp
       Extend.cpp
       WhenRule.cpp
       Scores.cpp
        )
target_include_directories(ruleTree
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        )
target_link_libraries(ruleTree PRIVATE gameState Players)