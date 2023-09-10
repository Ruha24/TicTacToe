#pragma once

#include "Gamers.h"
#include <string>

class Player : public Gamers
{
public:
    Player(const std::string& playerName);

    char getMoveSymbol() const override;
    std::string getName() const override;

private:
    std::string name;
};
