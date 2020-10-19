include(FetchContent)

FetchContent_Declare(json
  GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
  GIT_TAG v3.7.0)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
  FetchContent_Populate(json)
  add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

add_executable(jsonparser Loader.cpp Constants.cpp Configuration.cpp Variables.cpp)

target_include_directories(jsonparser
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(jsonparser PRIVATE nlohmann_json::nlohmann_json gameState ruleClasses Players)

set_target_properties(jsonparser
        PROPERTIES
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
        PREFIX ""
        )

install(TARGETS jsonparser
        RUNTIME DESTINATION bin)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/rockPaperScissors.json
        DESTINATION ${CMAKE_BINARY_DIR}/bin)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/rockPaperScissors.json
        DESTINATION ${CMAKE_BINARY_DIR})
