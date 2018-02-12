cmake_minimum_required(VERSION 3.9)
project(SFML_Tutorial)

set(CMAKE_CXX_STANDARD 11)
add_executable(SFML_Tutorial main.cpp header/Game.hpp Game.cpp header/State.hpp StateMachine.cpp header/StateMachine.hpp AssetManager.cpp header/AssetManager.hpp InputManager.cpp header/InputManager.hpp header/Definitions.hpp SplashState.cpp header/SplashState.hpp)

# SFML config
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(SFML_Tutorial ${SFML_LIBRARIES})
endif()

