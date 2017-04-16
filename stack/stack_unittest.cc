/*
 * =====================================================================================
 *
 *       Filename:  stack_unittest.cc
 *
 *    Description:  Unit Testing for Stack
 *
 *        Version:  1.0
 *        Created:  Sunday 16 April 2017 02:42:39  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Chinmay Hundekari (CH), chinmay.hundekari@gmail.com
 *   Organization:  Juggernaut Software
 *
 * =====================================================================================
 */
#include "stack.hpp"
#include "gtest/gtest.h"


TEST(testStack, init) {
    Stack t1;
    ASSERT_EQ(1, t1.isEmpty());
    ASSERT_EQ(0, t1.size());
    ASSERT_THROW(t1.top(), e_stack_empty);
    ASSERT_THROW(t1.pop(), e_stack_empty);
    ASSERT_NO_THROW(t1.push(1));
}

TEST(testStack, addOneItem) {
    Stack t1;
    ASSERT_NO_THROW(t1.push(17));
    ASSERT_EQ(0, t1.isEmpty());
    ASSERT_EQ(1, t1.size());
    ASSERT_EQ(17, t1.top());
    ASSERT_EQ(17, t1.pop());
    ASSERT_EQ(1, t1.isEmpty());
    ASSERT_EQ(0, t1.size());
    ASSERT_THROW(t1.pop(), e_stack_empty);
}

TEST(testStack, addFULL) {
    Stack t1;
    for (int i = 0; i < STACK_SIZE; i++)
    {
        ASSERT_NO_THROW(t1.push(i));
        ASSERT_EQ(0, t1.isEmpty());
        ASSERT_EQ(i+1, t1.size());
        ASSERT_EQ(i, t1.top());
    }
    ASSERT_THROW(t1.push(STACK_SIZE), e_stack_full);
    ASSERT_EQ(0, t1.isEmpty());
    ASSERT_EQ(STACK_SIZE, t1.size());
}

