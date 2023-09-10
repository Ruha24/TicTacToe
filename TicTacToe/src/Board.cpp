#include "../include/Board.h"
#include <algorithm>

template <class T>
TicTacToe<T>::TicTacToe(std::size_t rows, std::size_t cols, T emptySpace)
    : _rows{ rows },
    _cols{ cols },
    _emptySpace{ emptySpace }
{
    _cells.resize(rows * cols, emptySpace);
}                                                       

template <class T>
TicTacToe<T>::TicTacToe()
    : _rows(0),
    _cols(0),
    _emptySpace(' ')
{
}

template <class T>
T& TicTacToe<T>::cell(std::size_t row, std::size_t col) {
    return _cells[col + row * _cols];
}

template <class T>
const std::vector<T> TicTacToe<T>::getCol(std::size_t col) {
    std::vector<T> v(_rows);
    for (std::size_t row = 0; row < _rows; row++)
        v[row] = cell(row, col);
    return v;
}

template <class T>
const std::vector<T> TicTacToe<T>::getRow(std::size_t row) {
    std::vector<T> v(_cols);
    for (std::size_t col = 0; col < _cols; col++)
        v[col] = cell(row, col);
    return v;
}

template <class T>
const std::vector<T> TicTacToe<T>::getDiagonal(Diagonal d) {
    std::vector<T> v;
    for (std::size_t col = 0; col < _cols; col++) {
        if (col < _rows) {
            v.push_back(cell(col, d == Diagonal::Principle ? col : _rows - col - 1));
        }
    }
    return v;
}

template <class T>
bool TicTacToe<T>::check_done() {
    return std::count(_cells.begin(), _cells.end(), _emptySpace) == 0;
}

template <class T>
bool TicTacToe<T>::check_equal(std::vector<T> v, T move) {
    return v[0] == move && std::equal(v.begin() + 1, v.end(), v.begin());
}

template <class T>
bool TicTacToe<T>::check_win(T move) {
    // check rows
    for (std::size_t r = 0; r < _rows; r++) {
        if (check_equal(getRow(r), move))
            return true;
    }
    // check columns
    for (std::size_t c = 0; c < _cols; c++) {
        if (check_equal(getCol(c), move))
            return true;
    }
    // check diagonals
    for (int d = 0; d < 2; d++) {
        if (check_equal(getDiagonal(d == 0 ? Diagonal::Principle : Diagonal::Secondary), move))
            return true;
    }
    return false;
}

template <class T>
void TicTacToe<T>::print() {
    std::cout << std::endl;
    for (std::size_t row = 0; row < _rows; row++) {
        for (std::size_t col = 0; col < _cols; col++) {
            std::cout << " " << cell(row, col);
            if (col < _cols - 1)
                std::cout << " |";
        }
        if (row < _rows - 1) {
            std::cout << std::endl;
            for (std::size_t col = 0; col < _cols; col++) {
                std::cout << (col < _cols - 1 ? "----" : "---");
            }
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

// Explicit template instantiation for supported types (e.g., char)
template class TicTacToe<char>;
