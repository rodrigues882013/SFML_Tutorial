cmake_minimum_required(VERSION 3.9)
project(SFML_Tutorial)

set(CMAKE_CXX_STANDARD 11)
add_executable(SFML_Tutorial src/main.cpp include/Game.hpp src/Game.cpp include/State.hpp src/StateMachine.cpp include/StateMachine.hpp src/AssetManager.cpp include/AssetManager.hpp src/InputManager.cpp include/InputManager.hpp include/Definitions.hpp src/SplashState.cpp include/SplashState.hpp src/MainMenuState.cpp include/MainMenuState.hpp)

# SFML config
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(SFML_Tutorial ${SFML_LIBRARIES})
endif()

