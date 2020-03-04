#ifndef __FACTORY_TEST_HPP__
#define __FACTORY_TEST_HPP__

#include "gtest/gtest.h"
#include "factory.hpp"

TEST(FactoryTest, Test1)
{
    char *a[5] = {"LOL", "1", "+", "5", NULL};
    int argc = 4;
    Factory *myFact = new Factory();
    Base *test = myFact->parse(a, argc);
    EXPECT_EQ(test->evaluate(), 6);
}

TEST(FactoryTest, Test2)
{
    char *a[7] = {"LOL", "5", "*", "5", "+", "7", NULL};
    int argc = 6;
    Factory *myFact = new Factory();
    Base *test = myFact->parse(a, argc);
    EXPECT_EQ(test->evaluate(), 32);
}

TEST(FactoryTest, Test3)
{
    char *a[7] = {"LOL", "5", "/", "5", "+", "1", NULL};
    int argc = 6;
    Factory *myFact = new Factory();
    Base *test = myFact->parse(a, argc);
    EXPECT_EQ(test->evaluate(), 2);
}

#endif