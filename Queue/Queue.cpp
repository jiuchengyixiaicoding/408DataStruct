#include <iostream>
#include <cstdlib>

using namespace std;

#define MaxSize 10
//���е�˳��洢�ṹ
typedef struct SeqQueue {
	int data[MaxSize];
	int front;
	int rear;
} SeqQueue;

//��ʼ��
bool initSeqQueue(SeqQueue &q) {
	q.front = 0;
	q.rear = 0;
	return true;
}
//��� �������෨��֤����ѭ������Ϊ���������ܴ���ģMaxSize�����rear + 1ΪMaxSize��Ϊ0
bool pushSeqQueue(SeqQueue &q, int x) {
	if ((q.rear + 1) % MaxSize == q.front) {
		return false;
	}
	q.data[q.rear] = x;
	q.rear = (q.rear + 1) % MaxSize;
	return true;
}
//����
bool popSeqQueue(SeqQueue& q, int &x) {
	if (q.front == q.rear) {
		return false;
	}
	x = q.data[q.front];
	q.front = (q.front + 1) % MaxSize;
	return true;
}

//���е���ʽ�洢�ṹ
typedef struct LNode{
	int data;
	struct LNode *next;
} LNode;

typedef struct LinkQueue {
	LNode* front, * rear;
}LinkQueue;
//��ʼ��
//��ͷ���
bool initHLinkQueue(LinkQueue &q) {
	q.front = (LNode*)malloc(sizeof(LNode));
	if (q.front == NULL) {
		return false;
	}
	q.rear = q.front;
	q.front->next = NULL;
	return true;
}
//��ͷ���
bool initLinkQueue(LinkQueue& q) {
	q.front = (LNode*)malloc(sizeof(LNode));
	if (q.front == NULL) {
		return false;
	}
	q.rear = q.front;
	q.front = NULL;
	return true;
}

//��ͷ���
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

//��ͷ���
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
//���� ��ͷ���
bool popLinkQueue(LinkQueue& q, int& x){
	if (q.front == q.rear) {
		return false;
	}
	LNode* p = q.front->next;
	q.front->next = p->next;
	//�������һ��Ԫ��
	if (p == q.rear) {
		q.rear = q.front;
	}
	free(p);
	return true;
}
//���� ��ͷ���
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