#include <gtest/gtest.h>
#include "math/Quaternion.hpp"

using namespace math;

TEST(Quaternion_test, set)
{
    double someVal = 1.0;
    Quaternion q(someVal, someVal, someVal, someVal);
    for (uint i = 0; i < 4; i++)
    {
        EXPECT_EQ(q[i], someVal);
    }

    Quaternion qCopy = q;
    for (uint i = 0; i < 4; i++)
    {
        EXPECT_EQ(qCopy[i], someVal);
        EXPECT_EQ(qCopy[i], q[i]);
    }
}
