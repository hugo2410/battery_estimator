
# Test is the subproject name
project(Test)

#Adding the Google Test sources
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_subdirectory(lib/googletest)


# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(RunAllTests
        NaiveEstimation_test.cpp
        SimpleEstimation_test.cpp
        AdvancedEstimation_test.cpp)


add_executable(NaiveEstimation_test NaiveEstimation_test.cpp)
add_executable(SimpleEstimation_test SimpleEstimation_test.cpp)
add_executable(AdvancedEstimation_test AdvancedEstimation_test.cpp)

target_link_libraries(RunAllTests gtest gtest_main Modules)

target_link_libraries(NaiveEstimation_test gtest gtest_main Modules)
target_link_libraries(SimpleEstimation_test gtest gtest_main Modules)
target_link_libraries(AdvancedEstimation_test gtest gtest_main Modules)