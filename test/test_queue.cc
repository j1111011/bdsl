#include "../bdsl/queue.h"
#include <gtest/gtest.h>
TEST(QueueTest,testCreateQueue)
{
	pqueue que = new_queue();
	delete_queue(que);
}
TEST(QueueTest,testQueueCreate)
{
	pqueue que = new_queue();
	pqueuenode node = que->create();
	que->destory(node);
	delete_queue(que);
}

TEST(QueueTest,testQueueEmpty)
{
	pqueue que = new_queue();
	pqueuenode node = que->create();
	ASSERT_TRUE(que->empty(node));
	queueelem elem;
	elem.value = 33;
	que->push(node,&elem);
	ASSERT_TRUE(!que->empty(node));
	que->destory(node);
	delete_queue(que);
}


TEST(QueueTest,testQueueDestory)
{
	pqueue que = new_queue();
	pqueuenode node = que->create();
	queueelem elem;
	elem.value = 32;
	que->push(node,&elem);
	que->destory(node);
	delete_queue(que);
}

TEST(QueueTest,testQueueSize)
{
	pqueue que = new_queue();
	pqueuenode node = que->create();
	queueelem elem;
	elem.value = 32;
	que->push(node,&elem);
	elem.value = 488;
	que->push(node,&elem);
	GTEST_ASSERT_EQ(que->size(node),2);
	que->pop(node);
	GTEST_ASSERT_EQ(que->size(node),1);
	que->destory(node);
	delete_queue(que);
}

TEST(QueueTest,testQueueFront)
{
	pqueue que = new_queue();
	pqueuenode node = que->create();
	queueelem elem;
	elem.value = 32;
	que->push(node,&elem);
	elem.value = 488;
	que->push(node,&elem);
	GTEST_ASSERT_EQ(que->front(node)->value,32);
	que->pop(node);
	GTEST_ASSERT_EQ(que->front(node)->value,488);
	que->destory(node);
	delete_queue(que);
}