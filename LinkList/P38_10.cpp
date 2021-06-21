#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

//��ʼ��������
bool initLinkList10(LinkList& l) {
	l = (LinkList)malloc(sizeof(LinkList));
	if (l == NULL) {
		return false;
	}
	l->next = NULL;
	return true;
}

//�ֽ�һ����ͷ�ڵ㵥�����������һ��ֻ��������һ��ֻ��ż��
//ԭ������ִ�������������������ֻҪ����һ��ż������
LinkList divideToSingleAndEven(LinkList& l) {
	LNode* p = l, * q, * r;
	//�������ż����ԭ���������
	LinkList even;
	initLinkList10(even);
	//��ʱż����Ϊ��
	q = even;

	//-------��ʼ���ֲ���--------
	
	//���Ԫ�ز�Ϊ�գ�p��Ϊ���Ƿ�ֹ���һλ��ż������ż�����ƶ�����һ��������p = p->next��pΪNULL���⣩
	while (p != NULL && p->next != NULL) {
		//���Ԫ��Ϊż��
		if (p->next->data % 2 == 0) {
			//��¼���Ԫ��
			r = p->next;
			//�Ͽ����Ԫ������
			p->next = p->next->next;

			//�Ѻ��Ԫ�����ӵ�ż�������β
			r->next = q->next;
			q->next = r;
			
			//�ƶ�qָ�뵽ż�������β
			q = q->next;
			
		}
		else {
			p = p->next;
		}

	}
	
	return even;
}

int main020210() {
	LinkList l;
	initLinkList10(l);

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

	

	LNode* p = divideToSingleAndEven(l)->next;
	printf("ż��");
	puts("");
	while (p != NULL) {
		printf("%d", p->data);
		puts("");
		p = p->next;
	}
	
	p = l->next;
	printf("����");
	puts("");
	while (p != NULL) {
		printf("%d", p->data);
		puts("");
		p = p->next;
	}

	return 0;
}