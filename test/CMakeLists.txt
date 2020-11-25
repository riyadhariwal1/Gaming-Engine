add_subdirectory(gtest)
enable_testing()

add_executable(test
  TEST_interpreter.cpp
  TEST_State.cpp
)
add_executable(test_tree 
  TEST_AstTree.cpp
)
target_link_libraries(test_tree
  gmock gtest gtest_main jsonParsing gameState ruleTree Players
)
target_link_libraries(test
  gmock gtest gtest_main jsonParsing gameState ruleTree Players
)

add_test(NAME AllTests COMMAND test test_tree)

set_target_properties(test
  PROPERTIES
  LINK_FLAGS "${CXX_COVERAGE_FLAGS}"
)
