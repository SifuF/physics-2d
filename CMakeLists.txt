cmake_minimum_required(VERSION 3.28)

project(Physics VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(PhysicsConfig.h.in PhysicsConfig.h)

add_subdirectory("${CMAKE_SOURCE_DIR}/submodules/SFML")

set(SOURCE
   ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

set(HEADERS
   ${CMAKE_CURRENT_SOURCE_DIR}/src/Mouse.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/src/Physics.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/src/Planets.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/src/Playground.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/src/Snooker.hpp
)

add_executable(Physics ${SOURCE} ${HEADERS})

target_include_directories(Physics PUBLIC
    "${CMAKE_SOURCE_DIR}/submodules/SFML/include"
)

target_link_libraries(Physics PUBLIC
    sfml-graphics
    sfml-system
    sfml-window
    sfml-network
    sfml-audio
)

file(COPY ${PROJECT_SOURCE_DIR}/fonts/arial.ttf DESTINATION ${PROJECT_BINARY_DIR}/fonts/)
file(COPY ${PROJECT_SOURCE_DIR}/sound/ DESTINATION ${PROJECT_BINARY_DIR}/sound/)
file(COPY ${PROJECT_SOURCE_DIR}/gfx/ DESTINATION ${PROJECT_BINARY_DIR}/gfx/)
