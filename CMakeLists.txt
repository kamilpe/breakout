project(breakout)

cmake_minimum_required(VERSION 3.0)

include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
pkg_search_module(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)
pkg_search_module(SDL2MIXER REQUIRED SDL2_mixer>=2.0.0)

file(GLOB SOURCES 
"src/*.c"
  )

include_directories(
  ${SDL2_INCLUDE_DIRS}
  ${SDL2IMAGE_INCLUDE_DIRS}
  ${SDL2TTF_INCLUDE_DIRS}
  ${SDL2MIXER_INCLUDE_DIRS}
  )

link_directories(
  ${SDL2_LIBRARY_DIRS}
  ${SDL2IMAGE_LIBRARY_DIRS}
  ${SDL2TTF_LIBRARY_DIRS}
  ${SDL2MIXER_LIBRARY_DIRS}
  )

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
  ${SDL2_LIBRARIES}
  ${SDL2IMAGE_LIBRARIES}
  ${SDL2TTF_LIBRARIES}
  ${SDL2MIXER_LIBRARIES}
  )

target_compile_options(${PROJECT_NAME} PUBLIC
  ${SDL2_CFLASGS_OTHER}
  ${SDL2IMAGE_CFLAGS_OTHER}
  ${SDL2TTF_CFLAGS_OTHER}
  ${SDL2MIXER_CFLAGS_OTHER}
  )

if (BUILD_TESTS)
  file(GLOB TESTS
    test/*.cpp
    )
  add_executable(ut_tests ${SOURCES} ${TESTS})
  target_link_libraries(ut_tests
    gtest gtest_main pthread
    ${SDL2_LIBRARIES}
    ${SDL2IMAGE_LIBRARIES}
    ${SDL2TTF_LIBRARIES}
    ${SDL2MIXER_LIBRARIES}
    )
endif(BUILD_TESTS)
