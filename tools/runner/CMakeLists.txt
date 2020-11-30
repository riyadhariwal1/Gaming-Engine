add_executable(runner main.cpp)
target_link_libraries(runner jsonParsing gameState ruleTree Players)


install(TARGETS runner
        RUNTIME DESTINATION bin)

set_target_properties(runner
        PROPERTIES
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
        PREFIX ""
        )

install(TARGETS runner
        RUNTIME DESTINATION bin)


file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/rockPaperScissors.json
        DESTINATION ${CMAKE_BINARY_DIR}/bin)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/players.json
        DESTINATION ${CMAKE_BINARY_DIR})