#include <iostream>
#include <cstdlib>

using namespace std;

#define MaxSize 10
typedef struct SeqQueue {
	//���ݴ洢�ռ�
	int data[MaxSize];
	//����
	int front;
	//��β
	int rear;
	//��ӳ��ӱ�ʶ��1���0����
	int tag;
}SeqQueue;

//��ʼ��
bool init(SeqQueue& q) {
	q.front = q.rear = 0;
}

//���
bool push(SeqQueue& q, int x) {
	//���׶�β��ȣ��ϴβ���Ϊ�������£����б�Ȼ��
	if (q.rear == q.front && q.tag == 1) {
		return false;
	}
	q.data[q.rear] = x;
	q.rear = (q.rear + 1) % MaxSize;
	q.tag = 1;
	return true;
}
//����
bool pop(SeqQueue& q, int& x) {
	//���׶�β��ȣ��ϴβ���Ϊ��������£����б�Ȼ��
	if (q.front == q.rear && q.tag == 0) {
		return false;
	}
	x = q.data[q.front];
	q.front = (q.front + 1) % MaxSize;
	q.tag = 0;
	return true;
}