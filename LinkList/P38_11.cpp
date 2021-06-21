#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

//��ʼ��������
bool initLinkList11(LinkList& l) {
	l = (LinkList)malloc(sizeof(LinkList));
	if (l == NULL) {
		return false;
	}
	l->next = NULL;
	return true;
}

//�͵��㷨���ֽ�һ����ͷ�ڵ㵥����{a1,b1,a2,b2,...,...,an,bn}��������һ��ֻ��a��һ��ֻ��b
LinkList divideToAandB(LinkList& a) {
	LinkList b;
	initLinkList11(b);
	if (a->next == NULL) {
		return b;
	}
	LNode* p = a, * q, * r;
	//�������b��ԭ�����a
	
	//��ʱbΪ��
	q = b;

	//-------��ʼ���ֲ���--------
	//����ֻ��һλ
	if (p->next->next == NULL) {
		return b;
	}
	int i = 1;
	//���Ԫ�ز�Ϊ�գ�p��Ϊ���Ƿ�ֹ���һλ��b����b���ƶ�����һ��������p = p->next��pΪNULL���⣩
	while (p != NULL && p->next != NULL) {
		//���Ԫ��Ϊż��
		if (i % 2 == 0) {
			//��¼���Ԫ��
			r = p->next;
			//�Ͽ����Ԫ������
			p->next = p->next->next;

			//�Ѻ��Ԫ�����ӵ�b�����β
			r->next = q->next;
			q->next = r;

			//�ƶ�qָ�뵽b�����β
			q = q->next;
			i = i + 2;
		}
		else {
			
			i++;
		}
		p = p->next;
	}

	return b;
}

int main020211() {
	LinkList l;
	initLinkList11(l);

	LNode* n1 = (LNode*)malloc(sizeof(LNode));
	if (n1 != NULL) {
		l->next = n1;
		n1->data = 5;
	}
	LNode* n2 = (LNode*)malloc(sizeof(LNode));
	if (n1 != NULL && n2 != NULL) {
		n2->data = 1;
		n1->next = n2;
	}
	LNode* n3 = (LNode*)malloc(sizeof(LNode));
	if (n2 != NULL && n3 != NULL) {
		n3->data = 8;
		n2->next = n3;
	}
	LNode* n4 = (LNode*)malloc(sizeof(LNode));
	if (n3 != NULL && n4 != NULL) {
		n4->data = 3;
		n3->next = n4;
		n4->next = NULL;
	}

	LNode* p = divideToAandB(l)->next;
	printf("b");
	puts("");
	while (p != NULL) {
		printf("%d", p->data);
		puts("");
		p = p->next;
	}

	p = l->next;
	printf("a");
	puts("");
	while (p != NULL) {
		printf("%d", p->data);
		puts("");
		p = p->next;
	}

	return 0;
}