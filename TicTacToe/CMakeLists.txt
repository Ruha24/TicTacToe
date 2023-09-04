# CMakeList.txt: проект CMake для TicTacToe; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (TicTacToe   "Board.h" "Board.cpp" "main.cpp" "Player.h" "Player.cpp" "Game.h" "Game.cpp" "Computer.h" "Computer.cpp" "Gamers.h" "Gamers.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TicTacToe PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
