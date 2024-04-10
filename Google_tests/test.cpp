//
// Created by Max on 19.03.2024.
//

#include "gtest/gtest.h"
#include "../LongLong.h"

TEST(LongLongTestSuite, LongLongTest)
{
    LongLong num1(1, 1),
            num2(0, 715827883);
    EXPECT_DOUBLE_EQ(num1 / num2, 12884901882);

    ++num1;
    EXPECT_EQ(num1.getHighPart(), 2);
    --num1;
    /*EXPECT_EQ(num1.getHighPart(), 1)*//*;*/
    num1++;
    EXPECT_EQ(num1.getLowPart(), 2);
    num1--;
    EXPECT_EQ(num1.getLowPart(), 1);
}
