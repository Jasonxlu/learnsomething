//
// Created by Ethan on 8/18/2023.
//

#include "pricingutil.h"

float PricingUtil::formula(float previousPrice, float interestRate, float oleoConstant)
{
    return previousPrice * (0.9 + interestRate) * oleoConstant;
}