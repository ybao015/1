#ifndef __CEIL_TEST_HPP__
#define __CEIL_TEST_HPP__

#include "gtest/gtest.h"

#include "ceil.hpp"
#include "op.hpp"

TEST(CeilTest, CeilEvaluate)
{
    Op *test1 = new Op(8.2);
    Ceil *test = new Ceil(test1);
    EXPECT_EQ(test->evaluate() , 9);
}

#endif //__ADD_TEST_HPP__
