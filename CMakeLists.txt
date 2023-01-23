cmake_minimum_required(VERSION 2.8.12)
project(illumination-2)

if(CMAKE_VERSION VERSION_LESS 3.0.0)
    include(CheckCXXCompilerFlag)
    check_cxx_compiler_flag(-std=c++11 COMPILER_SUPPORTS_CXX20)
    check_cxx_compiler_flag(-std=c++0x COMPILER_SUPPORTS_CXX0X)
    if(COMPILER_SUPPORTS_CXX20)
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
    elseif(COMPILER_SUPPORTS_CXX0X)
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
    endif()
else()
    SET(CMAKE_CXX_STANDARD 20)
    SET(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

add_definitions("-std=c++20")

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(illumination-2 src/main.cpp src/Player.cpp src/MainMenuScreen.cpp src/SettingsScreen.cpp)
target_link_libraries(illumination-2 ${CONAN_LIBS})