project(arkanoid)

cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB SOURCES 
    src/Ball.cpp  
    src/Ball.hpp
    src/Bounce.cpp
    src/Bounce.hpp
    src/GameInput.cpp
    src/GameInput.hpp
    src/GameScreen.cpp
    src/GameScreen.hpp
    src/main.cpp
    src/Pad.cpp
    src/Pad.hpp
    src/Sprite.cpp
    src/Sprite.hpp
    src/Timer.cpp
    src/Timer.hpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

include(FindPkgConfig)

pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
pkg_search_module(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)
pkg_search_module(SDL2MIXER REQUIRED SDL2_mixer>=2.0.0)

include_directories(
  ${SDL2_INCLUDE_DIRS}
  ${SDL2IMAGE_INCLUDE_DIRS}
  ${SDL2TTF_INCLUDE_DIRS}
  ${SDL2MIXER_INCLUDE_DIRS}
  )

target_link_libraries(${PROJECT_NAME}
  ${SDL2_LIBRARIES}
  ${SDL2IMAGE_LIBRARIES}
  ${SDL2TTF_LIBRARIES}
  ${SDL2MIXER_LIBRARIES}
  )
