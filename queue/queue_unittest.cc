/*
 * =====================================================================================
 *
 *       Filename:  queue_unittest.cc
 *
 *    Description:  Unit Testing for Queue
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
#include "queue.hpp"
#include "gtest/gtest.h"


TEST(testQueue, init) {
    Queue t1;
    ASSERT_EQ(1, t1.isEmpty());
    ASSERT_EQ(0, t1.size());
    ASSERT_THROW(t1.top(), e_queue_empty);
    ASSERT_THROW(t1.dequeue(), e_queue_empty);
    ASSERT_NO_THROW(t1.enqueue(1));
}

TEST(testQueue, addOneItem) {
    Queue t1;
    ASSERT_NO_THROW(t1.enqueue(17));
    ASSERT_EQ(0, t1.isEmpty());
    ASSERT_EQ(1, t1.size());
    ASSERT_EQ(17, t1.top());
    ASSERT_EQ(17, t1.dequeue());
    ASSERT_EQ(1, t1.isEmpty());
    ASSERT_EQ(0, t1.size());
    ASSERT_THROW(t1.dequeue(), e_queue_empty);
}

TEST(testQueue, addFULL) {
    Queue t1;
    for (int i = 0; i < QUEUE_SIZE - 1; i++)
    {
        ASSERT_NO_THROW(t1.enqueue(i));
        ASSERT_EQ(0, t1.isEmpty());
        ASSERT_EQ(i+1, t1.size());
        ASSERT_EQ(0, t1.top());
    }
    ASSERT_THROW(t1.enqueue(QUEUE_SIZE), e_queue_full);
    ASSERT_EQ(0, t1.isEmpty());
    ASSERT_EQ(QUEUE_SIZE - 1, t1.size());
}

