#ifndef __LISTCONTAINER_TEST_HPP__
#define __LISTCONTAINER_TEST_HPP__

#include "gtest/gtest.h"

#include "ListContainer.hpp"
#include "op.hpp"

TEST(ListContainerTestSet, AddTest)
{
    // Setup the elements under test
    Op *seven = new Op(7);
    ListContainer *test_container = new ListContainer();

    // Exercise some functionality of hte test elements
    test_container->add_element(seven);
    // Assert that the container has at least a single element
    // otherwise we are likely to cause a segfault when accessing
    EXPECT_EQ(test_container->at(0)->evaluate(), 7);
}


TEST(ListContainerTestSet, SwapTest)
{
    // Setup the elements under test
    Op *seven = new Op(7);
    Op *six = new Op(6);
    Op *five = new Op(5);
    Op *four = new Op(4);
    ListContainer *test_container = new ListContainer();

    // Exercise some functionality of hte test elements
    test_container->add_element(seven);
    test_container->add_element(six);
    test_container->add_element(five);
    test_container->add_element(four);
    test_container->swap(0, 3);
    // Assert that the container has at least a single element
    // otherwise we are likely to cause a segfault when accessing
    ASSERT_EQ(test_container->size(), 4);
    EXPECT_EQ(test_container->at(0)->evaluate(), 4);
    EXPECT_EQ(test_container->at(3)->evaluate(), 7);
}

#endif