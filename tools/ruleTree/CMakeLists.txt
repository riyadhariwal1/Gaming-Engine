add_library(ruleTree)
find_package(Threads REQUIRED)
target_sources(ruleTree PRIVATE
        GlobalMessage.cpp
        Add.cpp
        Discard.cpp
        Element.cpp
        Extend.cpp
        ForEachRule.cpp
        InputChoice.cpp
        List.cpp
        ParallelFor.cpp
        Scores.cpp
        WhenRule.cpp
        RuleAstVisitor.cpp
        MessageParser.cpp
        Interpreter.cpp
        Stack.cpp
        )
target_include_directories(ruleTree
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        )
target_link_libraries(ruleTree PRIVATE gameState Players Threads::Threads)
