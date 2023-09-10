#pragma once

#include <string>

class Gamers
{
public:
    virtual ~Gamers() {}

    // Function to get the symbol used by the player for their moves (X or O)
    virtual char getMoveSymbol() const = 0;

    // Function to get the name of the player
    virtual std::string getName() const = 0;
};

