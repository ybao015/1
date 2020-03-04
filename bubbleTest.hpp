#ifndef __BUBBLETEST_HPP__
#define __BUBBLETEST_HPP__

#include "gtest/gtest.h"
#include "BubbleSort.hpp"
#include "ListContainer.hpp"
#include "vectorContainer.hpp"
#include "op.hpp"
#include "add.hpp"
#include "mult.hpp"
#include "sub.hpp"

TEST(SortTestSet, BubbleSortTest)
{
    Op *seven = new Op(7);
    Op *four = new Op(4);
    Mult *TreeA = new Mult(seven, four);

    Op *three = new Op(3);
    Op *two = new Op(2);
    Add *TreeB = new Add(three, two);

    Op *ten = new Op(10);
    Op *six = new Op(6);
    Sub *TreeC = new Sub(ten, six);

    ListContainer *container = new ListContainer();
    container->add_element(TreeA);
    container->add_element(TreeB);
    container->add_element(TreeC);

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 28);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 4);

    container->set_sort_function(new BubbleSort());
    container->sort();

    ASSERT_EQ(container->size(), 3);
    EXPECT_EQ(container->at(0)->evaluate(), 4);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 28);
}
#endif
