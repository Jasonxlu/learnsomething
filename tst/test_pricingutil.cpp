#include <gtest/gtest.h>
#include "pricingutil.h"

TEST(PriceUtilTests, sample)
{
    EXPECT_EQ(4, 4);
}

TEST(PriceUtilTests, initialCalculation)
{
    PricingUtil pricingUtil;
    float res = pricingUtil.formula(2.0, 0.3, 4.0);
    EXPECT_NEAR(res, 9.6, 1e-4);
}

TEST(PriceUtilTests, negativesInCalculation)
{
    PricingUtil pricingUtil;
    float res = pricingUtil.formula(-2.0, 0.3, 4.0);
    EXPECT_NEAR(res, -9.6, 1e-4);
}

TEST(PriceUtilTests, zerosInCalculation)
{
    PricingUtil pricingUtil;
    float res = pricingUtil.formula(0.0, 0.3, 4.0);
    EXPECT_NEAR(res, 0, 1e-4);
}

TEST(PriceUtilTests, largeInterest)
{
    PricingUtil pricingUtil;
    float res = pricingUtil.formula(2.0, 9999, 4.0);
    EXPECT_NEAR(res, 79999.2, 1e-2);
}