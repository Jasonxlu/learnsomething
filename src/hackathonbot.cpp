//
// Created by Ethan on 9/13/2023.
//

#include "hackathonbot.h"

#include <iostream>

#include <utility>

HackathonBot::HackathonBot() : balance(0), holding(true), initialCost(100), count(0)
{
    this->prices.push_back(initialCost);
    this->delt.push_back(0);
    this->sign = 0;
}

double HackathonBot::getBalance()
{
    return this->balance;
}

bool HackathonBot::isHolding()
{
    return this->holding;
}

void HackathonBot::takeAction(float price)
{

    // You can only have 1 stock at a time, and cannot short a stock (can't sell without having an explicit stock)
    // Assume the initial stock cost was 100
    // If the stock goes up in price for 52 windows, sell
    // If the stock goes down in price for 47 windows, sell
    // If the stock drops by over 62% from the purchase price bought, sell
    // If the stock raises by over 89% from the purchase price bought, sell
    // If (after buying) the stock raises by >= 20%, drops by <= 15%, raises again by >= 30% and the percent change in the 3 series window is up by >= 50% sell
    // If (after buying) the stock drops by <= 15%, raises by >= 15%, drops again by >= 25% and the percent change OVERALL is down by >= 45% sell
    // If stock stays +-5% for 10 cycles (after buying), sell
    // If the stock price is less than 52, buy
    // If the stock drops in price for 5 windows (after selling), buy

    double nextPrice = this->prices[this->prices.size() - 1];
    double newDelt = price - nextPrice;

    this->delt.push_back(newDelt);
    this->prices.push_back(price);

    double nextDelt = this->delt[this->delt.size() - 1];

    double fivePercentCalc = abs(price - initialCost) / initialCost;

    if (fivePercentCalc < 0.05)
    {
        this->five_p++;
    }
    else
    {
        this->five_p = 0;
    }

    if (newDelt == 0)
    {
        this->count = 0;
        this->sign = 0;
    }

    else if ((newDelt > 0 != nextDelt < 0) || nextDelt == 0)
    {
        this->count++;
        this->sign = newDelt > 0 ? 1 : -1;
    }
    else
    {
        this->count = 1;
        this->sign = newDelt > 0 ? 1 : -1;
    }

    if (this->holding)
    {
        if (price >= initialCost * 1.89 || price <= initialCost * 0.38)
        {
            this->holding = false;
            this->balance += price;
            return;
        }

        if ((count >= 52 && this->sign == 1) || (count >= 47 && sign == -1))
        {
            this->holding = false;
            this->balance += price;
            return;
        }

        if (five_p >= 10)
        {
            this->holding = false;
            this->balance += price;
            return;
        }
    }
    else
    {
        if (price < 52 || (count >= 5 && sign == -1))
        {
            this->holding = true;
            this->balance -= price;
            this->initialCost = price;
            return;
        }
    }
}
