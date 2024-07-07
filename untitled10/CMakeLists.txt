cmake_minimum_required(VERSION 3.21)
project(untitled10)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled10 Game.cpp BodyObject.cpp BodyObject.h Player.cpp Player.h Global.h Platform.cpp Platform.h Animation.cpp Animation.h)

include_directories(c:/SFML/include)


set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(untitled10 ${SFML_LIBRARIES})
endif()

if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()

