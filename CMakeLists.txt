cmake_minimum_required(VERSION 3.22.1)

project(Physics VERSION 1.0)

#set(MAKE_BUILD_TYPE Debug ... FORCE)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

configure_file(PhysicsConfig.h.in PhysicsConfig.h)

set(SOURCE
   ${SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)
set(HEADERS
   ${HEADERS}
   ${CMAKE_CURRENT_SOURCE_DIR}/src/Mouse.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/src/Physics.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/src/Planets.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/src/Playground.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/src/Snooker.hpp
)

add_executable(Physics ${SOURCE} ${HEADERS})

if(WIN32)
set_target_properties(Physics PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS")
endif() 

target_include_directories(Physics PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_BINARY_DIR}/src"
)

if(WIN32)
target_include_directories(Physics PUBLIC
    "${PROJECT_SOURCE_DIR}/thirdparty/SFML/include"
)

target_link_directories(Physics PUBLIC
    "${PROJECT_SOURCE_DIR}/thirdparty/SFML/lib"
)
endif() 

target_link_libraries(Physics PUBLIC
    optimized sfml-graphics
    optimized sfml-system
    optimized sfml-window
    optimized sfml-network
    optimized sfml-audio
)

if(WIN32)
target_link_libraries(Physics PUBLIC
    debug sfml-main-d optimized sfml-main
    debug sfml-graphics-d
    debug sfml-system-d
    debug sfml-window-d
    debug sfml-network-d
    debug sfml-audio-d
)
endif() 

configure_file("${PROJECT_SOURCE_DIR}/fonts/arial.ttf" "${PROJECT_BINARY_DIR}/fonts/arial.ttf" COPYONLY)
file(COPY ${PROJECT_SOURCE_DIR}/sound/ DESTINATION ${PROJECT_BINARY_DIR}/sound/)
file(COPY ${PROJECT_SOURCE_DIR}/gfx/ DESTINATION ${PROJECT_BINARY_DIR}/gfx/)
if(WIN32)
file(COPY ${PROJECT_SOURCE_DIR}/thirdparty/SFML/bin/ DESTINATION ${PROJECT_BINARY_DIR})
endif() 

#install(TARGETS Physics DESTINATION bin)
#install(FILES "${PROJECT_SOURCE_DIR}/fonts/arial.ttf" DESTINATION bin/fonts)
#install(DIRECTORY "${PROJECT_SOURCE_DIR}/sound/" DESTINATION bin/sound)
#install(DIRECTORY "${PROJECT_SOURCE_DIR}/gfx/" DESTINATION bin/gfx)
#if(WIN32)
#install(DIRECTORY "${PROJECT_SOURCE_DIR}/thirdparty/SFML/bin/" DESTINATION bin/thirdparty)
#endif()

