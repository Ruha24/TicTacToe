#pragma once

#include "Gamers.h"
#include <string>

class Computer : public Gamers
{
public:
    Computer();

    char getMoveSymbol() const override;
    std::string getName() const override;
};
