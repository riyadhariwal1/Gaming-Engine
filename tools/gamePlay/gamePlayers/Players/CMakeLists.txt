add_library(Players)
target_sources(Players
  PRIVATE
    Player.cpp
)
target_include_directories(Players
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
target_link_libraries(Players jsonParsing)
