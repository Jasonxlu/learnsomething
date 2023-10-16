//
// Created by Ethan on 9/13/2023.
//

#include <vector>
#include "action.h"

#ifndef LEARNSOMETHING_HACKATHONBOT_H
#define LEARNSOMETHING_HACKATHONBOT_H

class HackathonBot
{
public:
    HackathonBot();
    void takeAction(float price);
    double getBalance();
    bool isHolding();

private:
    double balance;
    bool holding;
    double initialCost;
    std::vector<Action> actions;
    std::vector<double> prices;
    std::vector<double> delt;
    int sign;
    int count;
    int five_p;
};

#endif // LEARNSOMETHING_HACKATHONBOT_H
