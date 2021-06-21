#include <iostream>
#include <cstdlib>

using namespace std;

#define MaxSize 10
//队列的顺序存储结构
typedef struct SeqQueue {
	int data[MaxSize];
	int front;
	int rear;
} SeqQueue;

//初始化
bool initSeqQueue(SeqQueue &q) {
	q.front = 0;
	q.rear = 0;
	return true;
}
//入队 利用求余法保证队列循环，因为余数不可能大于模MaxSize。如果rear + 1为MaxSize则为0
bool pushSeqQueue(SeqQueue &q, int x) {
	if ((q.rear + 1) % MaxSize == q.front) {
		return false;
	}
	q.data[q.rear] = x;
	q.rear = (q.rear + 1) % MaxSize;
	return true;
}
//出队
bool popSeqQueue(SeqQueue& q, int &x) {
	if (q.front == q.rear) {
		return false;
	}
	x = q.data[q.front];
	q.front = (q.front + 1) % MaxSize;
	return true;
}

//队列的链式存储结构
typedef struct LNode{
	int data;
	struct LNode *next;
} LNode;

typedef struct LinkQueue {
	LNode* front, * rear;
}LinkQueue;
//初始化
//带头结点
bool initHLinkQueue(LinkQueue &q) {
	q.front = (LNode*)malloc(sizeof(LNode));
	if (q.front == NULL) {
		return false;
	}
	q.rear = q.front;
	q.front->next = NULL;
	return true;
}
//无头结点
bool initLinkQueue(LinkQueue& q) {
	q.front = (LNode*)malloc(sizeof(LNode));
	if (q.front == NULL) {
		return false;
	}
	q.rear = q.front;
	q.front = NULL;
	return true;
}

//带头结点
bool pushHLinkQueue(LinkQueue &q, int x) {
	LNode* p = (LNode*)malloc(sizeof(LNode));
	if (p == NULL) {
		return false;
	}
	p->data = x;
	p->next = NULL;
	q.rear->next = p;
	q.rear = p;
}

//无头结点
bool pushLinkQueue(LinkQueue &q, int x) {
	LNode* p = (LNode*)malloc(sizeof(LNode));
	if (p == NULL) {
		return false;
	}
	p->data = x;
	p->next = NULL;
	if (q.front == NULL) {
		q.rear = p;
	}
	else {
		q.rear->next = p;
		q.rear = p;
	}
}
//出队 带头结点
bool popLinkQueue(LinkQueue& q, int& x){
	if (q.front == q.rear) {
		return false;
	}
	LNode* p = q.front->next;
	q.front->next = p->next;
	//队列最后一个元素
	if (p == q.rear) {
		q.rear = q.front;
	}
	free(p);
	return true;
}
//出队 无头结点
bool popLinkQueue(LinkQueue &q, int& x) {
	if(q.front == q.rear) {
		return false;
	}
	LNode* p = q.front;
	q.front = q.front->next;
	x = p->data;
	free(p);
	return true;
}