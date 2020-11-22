include(FetchContent)

FetchContent_Declare(json
  GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
  GIT_TAG v3.7.0)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
  FetchContent_Populate(json)
  add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

add_library(jsonParsing)
target_sources(jsonParsing
        PRIVATE
        Configuration.cpp
        Constants.cpp
        Variables.cpp
        Loader.cpp
        Parser.cpp
        PlayerSetup.cpp)

target_include_directories(jsonParsing
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

target_link_libraries(jsonParsing PRIVATE nlohmann_json::nlohmann_json gameState ruleTree Players)
