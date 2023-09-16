//
// Created by Ethan on 8/16/2023.
//

#include "risktracker.h"
#include <iostream>
#include <vector>

RiskTracker::RiskTracker(float x, std::vector<Trade> trades) : totalRisk(x), pendingTrades(trades){};

int RiskTracker::updateRisk()
{
    double runningSum = 0;
    for (const auto &x : this->pendingTrades)
    {
        if (x.side)
        {
            runningSum += (x.price * x.quantity);
        }
        else
        {
            runningSum -= (x.price * x.quantity);
        }
    }
    pendingTrades.erase(pendingTrades.begin(), pendingTrades.end());
    this->totalRisk += runningSum;
    return 0;
}

int RiskTracker::addTrade(Trade trade)
{
    this->pendingTrades.push_back(trade);
    return 0;
}

float RiskTracker::getRisk()
{
    return this->totalRisk;
}
