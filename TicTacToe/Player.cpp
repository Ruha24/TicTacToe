#include "Player.h"
#include <cstdlib>

Player::Player(const std::string& playerName) : name(playerName) {}

char Player::getMoveSymbol() const {
    return (std::rand() % 2 == 0) ? 'X' : 'O';
}

std::string Player::getName() const {
    return name;
}
