#pragma once

#include <iostream>
#include <vector>

enum Diagonal
{
    Principle,
    Secondary
};

template <class T>
class TicTacToe
{
private:
    std::size_t _rows;
    std::size_t _cols;
    T _emptySpace;
    std::vector<T> _cells = {};

public:
    TicTacToe(std::size_t rows, std::size_t cols, T emptySpace);
    TicTacToe();
    T& cell(std::size_t row, std::size_t col);
    const std::vector<T> getCol(std::size_t col);
    const std::vector<T> getRow(std::size_t row);
    const std::vector<T> getDiagonal(Diagonal d);
    bool check_done();
    bool check_equal(std::vector<T> v, T move);
    bool check_win(T move);
    void print();
};
