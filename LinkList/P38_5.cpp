#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

//��ʼ��������
bool initLinkList05(LinkList& l) {
	l = (LNode*)malloc(sizeof(LNode));
	if (l == NULL) {
		return false;
	}
	l->next = NULL;
	return true;
}

//n��Ԫ�صĵ�����ֻ��Ҫ�ƶ�������n-1��Ԫ�ص�ǰ��
void moveEndToHead(LinkList& l, LNode* p, LNode* q, int i, int j, int n) {
	if (i > n-1) {
		return;
	}
	while (p->next->next != NULL) {
		p = p->next;
	}
	while (j < i) {
		q = q->next;
		j++;
	}
	p->next->next = q->next;
	q->next = p->next;
	p->next = NULL;
	p = l;
	q = l;
	moveEndToHead(l, p, q, ++i, j, n);
}

//�͵����ô�ͷ���ĵ�����(�͵�������Ϊ���ռ临�Ӷ�Ϊo(1))
void localReserveHLList(LinkList& l) {
	//������Ϊ��
	if (l->next == NULL) {
		return;
	}
	//������ֻ��һλ
	if (l->next->next == NULL) {
		return;
	}
	LNode* p = l->next;
	//n��ʾ������
	int n = 0;
	while (p != NULL) {
		n++;
		p = p->next;
	}
	//��i����ƶ�β����ͷ��ִ���˼��Σ���һ����1
	int i = 1;
	p = l;
	LNode* q = l;
	int j = 1;
	moveEndToHead(l, p, q, i, j, n);
	
}

//�ο���
void ReserveHLList(LinkList& l) {
	LNode* p, * q;
	p = l->next;
	l->next = NULL;
	//ͷ�巨
	while (p != NULL) {
		q = p->next;
		p->next = l->next;
		l->next = p;
		p = q;
	}
}

int main020205() {

	LinkList l;
	initLinkList05(l);

	LNode* n1 = (LNode*)malloc(sizeof(LNode));
	if (n1 != NULL) {
		l->next = n1;
		n1->data = 1;
	}
	LNode* n2 = (LNode*)malloc(sizeof(LNode));
	if (n1 != NULL && n2 != NULL) {
		n2->data = 2;
		n1->next = n2;
	}
	LNode* n3 = (LNode*)malloc(sizeof(LNode));
	if (n2 != NULL && n3 != NULL) {
		n3->data = 3;
		n2->next = n3;
	}
	LNode* n4 = (LNode*)malloc(sizeof(LNode));
	if (n3 != NULL && n4 != NULL) {
		n4->data = 4;
		n3->next = n4;
		n4->next = NULL;
	}

	

	//localReserveHLList(l);
	ReserveHLList(l);

	LNode* p = l->next;

	while (p != NULL) {
		printf("%d", p->data);
		puts("");
		p = p->next;
	}
	return 0;
}