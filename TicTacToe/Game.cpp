#include "Game.h"


Game::Game() : player(nullptr),
computer(nullptr),
turn(' ')
{
}

int Game::start()
{
    unsigned int a, b;
    std::string playerName;

    std::cout << "Enter your name: ";
    std::cin >> playerName;

    player = new Player(playerName);

    char playerSymbol = player->getMoveSymbol();
    char computerSymbol = (playerSymbol == 'X') ? 'O' : 'X';

    computer = new Computer();

    std::cout << "You are playing as: " << playerSymbol << std::endl;

    std::cout << "Enter the dimensions of the board (rows, cols): ";
    std::cin >> a >> b;

    if ((a >= 3) && (b >= 3)) {

        TicTacToe<char> ttt(a, b, ' ');

        ttt.print();

        while (!ttt.check_done() && !ttt.check_win(playerSymbol) && !ttt.check_win(computerSymbol)) {

            player_turn(playerSymbol, ttt);

            if (ttt.check_win(playerSymbol)) {
                std::cout << playerName << " wins!" << std::endl;
                break;
            }

            computer_turn(computerSymbol, ttt);
            ttt.print();

            if (ttt.check_win(computerSymbol)) {
                std::cout << "Computer wins!" << std::endl;
                break;
            }

            if (ttt.check_done()) {
                std::cout << "It's a draw!" << std::endl;
                break;
            }
        }
    }
    else {
        std::cout << "Invalid dimensions." << std::endl;
        return 1;
    }

    delete player;
    delete computer;

    return 0;
}


void Game::player_turn(char playerSymbol, TicTacToe<char>& ttt)
{
    std::cout << player->getName() << " turn : ";

    int row, col;
    std::cout << "Enter row and column (e.g 1,2) : ";
    std::cin >> row >> col;

    std::size_t numRows = ttt.getCol(0).size();
    std::size_t numCols = ttt.getRow(0).size();

    row--;
    col--;

    // Check if cell is occupied or coordinates are occupied
    while (row < 0 || row >= numRows || col < 0 || col >= numCols || ttt.cell(row, col) != ' ') {
        std::cout << "Invalid move. Try again." << std::endl;
        std::cout << "Enter row and column (e.g 1,2) : ";
        std::cin >> row >> col;

        row--;
        col--;
    }

    // If the coordinates are valid and the cell is free, make the player's move
    ttt.cell(row, col) = playerSymbol;
    ttt.print();

}


void Game::computer_turn(char computerSymbol, TicTacToe<char>& ttt)
{
    std::size_t numRows = ttt.getCol(0).size();
    std::size_t numCols = ttt.getRow(0).size();


    std::vector<std::pair<std::size_t, std::size_t>> emptyCells;

    for (std::size_t row = 0; row < numRows; row++) {
        for (std::size_t col = 0; col < numCols; col++) {
            if (ttt.cell(row, col) == ' ') {
                emptyCells.push_back(std::make_pair(row, col));
            }
        }
    }

    // Checking if the computer wins on the next move
    for (auto& cell : emptyCells) {
        ttt.cell(cell.first, cell.second) = computerSymbol;
        if (ttt.check_win(computerSymbol)) {
            std::cout << "Computer chooses: " << cell.first + 1 << "," << cell.second + 1 << std::endl;
            return;
        }
        ttt.cell(cell.first, cell.second) = ' ';
    }

    // Checking whether to block the player's win on the next move
    char playerSymbol = (computerSymbol == 'X') ? 'O' : 'X';
    for (auto& cell : emptyCells) {
        ttt.cell(cell.first, cell.second) = playerSymbol;
        if (ttt.check_win(playerSymbol)) {
            std::cout << "Computer chooses: " << cell.first + 1 << "," << cell.second + 1 << std::endl;
            ttt.cell(cell.first, cell.second) = computerSymbol;
            return;
        }
        ttt.cell(cell.first, cell.second) = ' ';
    }

    // If there is no way to win or block, choose a random empty cell
    if (!emptyCells.empty()) {
        int randomIndex = rand() % emptyCells.size();
        auto& selectedCell = emptyCells[randomIndex];
        std::cout << "Computer chooses: " << selectedCell.first + 1 << "," << selectedCell.second + 1 << std::endl;
        ttt.cell(selectedCell.first, selectedCell.second) = computerSymbol;
    }
}
