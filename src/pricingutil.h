//
// Created by Ethan on 8/18/2023.
//

#ifndef LEARNSOMETHING_PRICINGUTIL_H
#define LEARNSOMETHING_PRICINGUTIL_H

class PricingUtil
{
public:
    PricingUtil();
    float formula(float previousPrice, float interestRate, float oleoConstant);
};

#endif // LEARNSOMETHING_PRICINGUTIL_H
