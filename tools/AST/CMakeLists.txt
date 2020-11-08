add_library(AST)
target_sources(AST
        PRIVATE
        test.cpp
        )
target_include_directories(AST
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        )
target_link_libraries(AST PRIVATE ruleClasses)