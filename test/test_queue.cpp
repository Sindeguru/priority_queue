#include "queue.h"
#include "../gtest/gtest.h"
#include "queuelist.h"

TEST(TQueueList, can_create_steck_with_positive_length)
{
  ASSERT_NO_THROW(TQueueList<int> bf(3));
}

TEST(TQueueList, empty_true)
{
  TQueueList<int> A();
  ASSERT_EQ(A.IsEmpty(), true);
}

TEST(TQueueList, empty_false)
{
  TQueueList<int> A();
  A.Push(2);
  ASSERT_EQ(A.IsEmpty(), false);
}

TEST(TQueueList, pop_take_right_element)
{
  TQueueList<int> A(2);
  A.Push(31);
  A.Push(2);
  ASSERT_EQ(A.Pop(), 31);
  ASSERT_EQ(A.Pop(), 2);
}

TEST(TQueueList, push_without_problems)
{
  TQueueList<int> A(2);
  ASSERT_NO_THROW(A.Push(13124125));
}

TEST(TQueueList, create_queue_with_uncorrect_size)
{
  ASSERT_ANY_THROW(TQueueList<int> A(-1));
}

TEST(TQueueList, push_in_out_of_size)
{
  TQueueList<int> A(0);
  ASSERT_ANY_THROW(A.Push(13124125));
}

TEST(TQUeue, pop_in_empty_queue)
{
  TQueueList<int> A(2);
  ASSERT_ANY_THROW(A.Pop());
}
