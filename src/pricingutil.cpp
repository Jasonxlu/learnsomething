#include "pricingutil.h"

//
// Created by Ethan on 8/18/2023.
//

PricingUtil::PricingUtil() {}

float PricingUtil::calcVal(float prevPrice, float interest, float oleoConstant)
{
    this->val = prevPrice * (0.9 + interest) * oleoConstant;
}

float PricingUtil::getVal()
{
    return this->val;
}