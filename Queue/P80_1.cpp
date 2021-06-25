#include <iostream>
#include <cstdlib>

using namespace std;

#define MaxSize 10
typedef struct SeqQueue {
	//数据存储空间
	int data[MaxSize];
	//队首
	int front;
	//队尾
	int rear;
	//入队出队标识符1入队0出队
	int tag;
}SeqQueue;

//初始化
bool init(SeqQueue& q) {
	q.front = q.rear = 0;
}

//入队
bool enQueue(SeqQueue& q, int x) {
	//队首队尾相等，上次操作为入队情况下，队列必然满
	if (q.rear == q.front && q.tag == 1) {
		return false;
	}
	q.data[q.rear] = x;
	q.rear = (q.rear + 1) % MaxSize;
	q.tag = 1;
	return true;
}
//出队
bool deQueue(SeqQueue& q, int& x) {
	//队首队尾相等，上次操作为出队情况下，队列必然空
	if (q.front == q.rear && q.tag == 0) {
		return false;
	}
	x = q.data[q.front];
	q.front = (q.front + 1) % MaxSize;
	q.tag = 0;
	return true;
}
