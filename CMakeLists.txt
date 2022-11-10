cmake_minimum_required(VERSION 3.10)
project(Battery_Estimator)

set(CMAKE_CXX_STANDARD 14)

include_directories(Modules)
add_subdirectory(Test)
add_subdirectory(Modules)
set(SOURCE_FILES main.cpp)
add_executable(Battery_Estimator ${SOURCE_FILES})

target_link_libraries(Battery_Estimator Modules)