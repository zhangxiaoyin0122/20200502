#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
typedef int QType;

typedef struct QNode {
	struct QNode* _next;
	QType _value;
}QNode;

typedef struct Queue {
	QNode* _front;
	QNode* _rear;
	size_t _size;
}Queue;
//队列的初始化
void QueueInit(Queue* q) {
	q->_front = q->_rear = NULL;
	q->_size = 0;
}

//创造节点
QNode* creatQNode(QType data) {
	QNode* node = (QNode*)malloc(sizeof(QType));
	node->_next = NULL;
	node->_value = data;
	return node;
}
//尾插 队列入队
void QueuePushBack(Queue* q,QType data) {
	QNode* node = creatQNode(data);
	if (q->_front == NULL) {
		q->_front = q->_rear = node;
	}
	else {
		q->_rear->_next = node;
		q->_rear = node;
	}
	q->_size++;
}
//头删  队列出队
void QueuePopFront(Queue* q) {
	if (q->_front) {
		QNode* cur = q->_front;
		q->_front = cur->_next;
		free(cur);
		if (q->_front == NULL)
			q->_rear = NULL;
	}
	q->_size--;
}

int QueueSize(Queue* q) {
	return q->_size;
}
//获取队元素
QType QueueFront(Queue* q) {
	if(q->_front)
	return q->_front->_value;
}
QType QueueTail(Queue* q) {
	return q->_rear->_value;
}
int QueueEmpty(Queue* q) {
	if (q->_front)
		return 1;
	return 0;
}
//队列的销毁
void QueueDestory(Queue* q) {
	QNode* cur = q->_front;
	while (cur) {
		QNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
	q->_size = 0;
}