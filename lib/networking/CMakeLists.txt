set(LLVM_ENABLE_RTTI ON)
set(LLVM_ENABLE_EH ON)

add_library(networking
  src/Server.cpp
  src/Client.cpp
  src/Room.cpp
  src/User.cpp
  src/Game.cpp
  src/GameManager.cpp
  src/Store.cpp
)

find_package(Boost 1.72 COMPONENTS system REQUIRED)

target_include_directories(networking
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${Boost_INCLUDE_DIR}
)

target_link_libraries(networking
  PRIVATE
    ${Boost_LIBRARIES}
)

set_target_properties(networking
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
)

install(TARGETS networking
  ARCHIVE DESTINATION lib
)

