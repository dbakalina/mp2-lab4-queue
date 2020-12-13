#include"gtest.h"
#include "../Queue/Queue.h"

TEST(Queue, can_create_queue)
{
    ASSERT_NO_THROW(TQueue<int> s(8));
}

TEST(Queue, cant_create_queue_with_negative_MaxSize)
{
    ASSERT_ANY_THROW(TQueue<int> s(-5));
}

TEST(Queue, can_get_size)
{
    TQueue<int> q(5);
    q.Push(5);
    ASSERT_NO_THROW(q.GetSize());
    EXPECT_EQ(1, q.GetSize());
}

TEST(Queue, can_copy_the_queue)
{
    TQueue<int> q(5);
    q.Push(5);
    ASSERT_NO_THROW(TQueue<int> copy(q));
}

TEST(Queue, the_copied_queue_is_the_same_as_the_original_one)
{
    TQueue<int> q(5);
    q.Push(5);
    TQueue<int> copy(q);
    EXPECT_EQ(q.GetSize(), copy.GetSize());
    EXPECT_EQ(q.GetHead(), copy.GetHead());
}

TEST(Queue, can_assign_queue_of_the_same_data_types_and_MaxSize)
{
    TQueue<int> q1(5);
    TQueue<int> q2(5);
    q1.Push(5);
    q1.Push(7);
    q2.Push(3);
    ASSERT_NO_THROW(q2 = q1);
    EXPECT_EQ(q1.GetSize(), q2.GetSize());
    EXPECT_EQ(q1.GetHead(), q2.GetHead());
}
TEST(Queue, can_assign_queue_of_the_same_data_types_and_different_MaxSize)
{
    TQueue<int> q1(8);
    TQueue<int> q2(5);
    q1.Push(5);
    q1.Push(7);
    q2.Push(3);
    ASSERT_NO_THROW(q2 = q1);
    EXPECT_EQ(q1.GetSize(), q2.GetSize());
    EXPECT_EQ(q1.GetHead(), q2.GetHead());
}

TEST(Queue, can_compare_queue)
{
    TQueue<int> q1(7);
    TQueue<int> q2(7);
    q1.Push(5);
    q2.Push(3);
    ASSERT_NO_THROW(q2 == q1);
}

TEST(Queue, can_compare_the_queue_with_itself)
{
    TQueue<int> q(7);
    EXPECT_EQ(true, q == q);
}

TEST(Queue, comparing_the_same_queue_gives_the_truth)
{
    TQueue<int> q1(3);
    TQueue<int> q2(3);
    q1.Push(3);
    q1.Push(3);
    q1.Push(5);
    q1.GetHead();
    q1.GetHead();
    q1.Push(3);
    q1.Push(5);
    q1.GetHead();
    q1.GetHead();
    q2.Push(5);
    EXPECT_EQ(true, q1 == q2);
}

TEST(Queue, comparing_different_queue_gives_the_lie)
{
    TQueue<int> q1(5);
    TQueue<int> q2(5);
    q1.Push(5);
    q1.Push(5);
    q2.Push(5);
    EXPECT_EQ(true, q1 != q2);
}
TEST(Queue, can_check_the_queue_for_emptiness)
{
    TQueue<int> q(5);
    ASSERT_NO_THROW(q.Empty());
}
TEST(Queue, initially_the_queue_is_empty)
{
    TQueue<int> q(5);
    EXPECT_EQ(true, q.Empty());
}
TEST(Queue, a_queue_with_a_size_greater_than_zero_is_not_empty)
{
    TQueue<int> q(5);
    q.Push(5);
    EXPECT_EQ(false, q.Empty());
}
TEST(Queue, can_check_the_queue_for_completeness)
{
    TQueue<int> q(5);
    ASSERT_NO_THROW(q.Full());
}
TEST(Queue, if_the_queue_size_is_equal_to_the_MaxSize_then_the_stack_is_full)
{
    int max_size = 2;
    TQueue<int> q(max_size);
    q.Push(1);
    q.Push(2);
    EXPECT_EQ(q.GetSize(), max_size);
    EXPECT_EQ(true, q.Full());
}
TEST(Queue, can_add_an_item_to_an_incomplete_queue)
{
    TQueue<int> q(5);
    ASSERT_NO_THROW(q.Push(5));
}
TEST(Queue, cant_add_an_item_to_the_full_queue)
{
    TQueue<int> q(1);
    q.Push(5);
    ASSERT_ANY_THROW(q.Push(5));
}
TEST(Queue, can_see_what_is_at_the_top_of_a_non_empty_queue)
{
    TQueue<int> q(5);
    q.Push(5);
    ASSERT_NO_THROW(q.SeeHead());
}
TEST(Queue, viewing_the_top_of_the_stack_does_not_change_the_state_of_the_queue)
{
    TQueue<int> q(5);
    q.Push(5);
    int size = q.GetSize();
    int a = q.SeeHead();
    EXPECT_EQ(size, q.GetSize());
    EXPECT_EQ(a, q.SeeHead());
}
TEST(Queue, cant_look_at_the_top_of_an_empty_queue)
{
    TQueue <int> q(5);
    ASSERT_ANY_THROW(q.GetHead());
}
TEST(Queue, can_take_an_element_from_a_non_empty_non_empty_queue)
{
    TQueue<int> q(5);
    q.Push(5);
    ASSERT_NO_THROW(q.GetHead());
}
TEST(Queue, taking_an_element_from_the_queue_reduces_its_size_by_one)
{
    TQueue<int> q(5);
    int a = 2, b = 3;
    q.Push(a);
    q.Push(b);
    int size = q.GetSize();
    int elem = q.GetHead();
    EXPECT_EQ(elem, a);
    EXPECT_EQ(size - 1, q.GetSize());
}
TEST(Queue, cant_take_an_element_from_an_empty_stack)
{
    TQueue<int> q(5);
    ASSERT_ANY_THROW(q.GetHead());
}
