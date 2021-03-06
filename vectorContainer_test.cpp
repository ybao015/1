#ifndef __VECTORCONTAINER_TEST_HPP__
#define __VECTORCONTAINER_TEST_HPP__

#include "gtest/gtest.h"

#include "vectorContainer.hpp"
#include "op.hpp"

TEST(VectorContainerTestSet, AddTest)
{
    // Setup the elements under test
    Op *seven = new Op(7);
    VectorContainer *test_container = new VectorContainer();

    // Exercise some functionality of hte test elements
    test_container->add_element(seven);
    // Assert that the container has at least a single element
    // otherwise we are likely to cause a segfault when accessing
    EXPECT_EQ(test_container->at(0)->evaluate(), 7);
}

TEST(VectorContainerTestSet, SwapTest)
{
    // Setup the elements under test
    Op *seven = new Op(7);
    Op *six = new Op(6);
    Op *five = new Op(5);
    Op *four = new Op(4);
    VectorContainer *test_container = new VectorContainer();

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