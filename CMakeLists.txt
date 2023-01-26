cmake_minimum_required(VERSION 2.8.12)
project(illumination-2)

SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions("-std=c++20")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(illumination-2 src/Bitmask.cpp src/Game.cpp src/Input.cpp src/main.cpp src/SceneGame.cpp src/SceneSplashScreen.cpp src/SceneStateMachine.cpp src/Window.cpp src/WorkingDirectory.cpp)

# target_compile_options(illumination-2 PUBLIC -fsanitize=address,leak,undefined)
target_link_libraries(illumination-2 ${CONAN_LIBS}) # -fsanitize=address,leak,undefined