cmake_minimum_required (VERSION 3.8)

enable_testing()
add_subdirectory(googletest)
add_executable(test_app test_main.cpp "../TicTacToe/Player.cpp")
target_compile_options(test_app PRIVATE /MTd)

target_include_directories(test_app PRIVATE 
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/googletest/googlemock/include"
)
target_link_libraries(test_app gtest_main GTest::gmock_main)
