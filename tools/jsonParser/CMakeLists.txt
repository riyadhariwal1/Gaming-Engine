find_package(nlohmann_json 3.2.0 REQUIRED)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/rockPaperScissors.json
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(jsonparser Loader.cpp Configuration.cpp)
target_link_libraries(jsonparser PRIVATE nlohmann_json::nlohmann_json)

set_target_properties(jsonparser
        PROPERTIES
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
        PREFIX ""
        )

install(TARGETS jsonparser
        RUNTIME DESTINATION bin)
