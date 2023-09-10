# CMakeList.txt: проект CMake для TicTacToe; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (TicTacToe "include/Board.h" "src/Board.cpp" "src/main.cpp" "include/Player.h" "src/Player.cpp" "include/Game.h" "src/Game.cpp" "include/Computer.h" "src/Computer.cpp" "include/Gamers.h" "src/Gamers.cpp" )
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TicTacToe PROPERTY CXX_STANDARD 20)
endif()


   