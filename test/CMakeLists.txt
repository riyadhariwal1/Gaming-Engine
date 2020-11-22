add_subdirectory(gtest)
enable_testing()

add_executable(test
  TEST_State.cpp
)

target_link_libraries(test
  gmock gtest gtest_main jsonParsing gameState ruleTree Players
)

add_test(NAME AllTests COMMAND test)

set_target_properties(test
  PROPERTIES
  LINK_FLAGS "${CXX_COVERAGE_FLAGS}"
)
