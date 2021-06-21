#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

//��ʼ��������
bool initLinkList14(LinkList& l) {
	l = (LinkList)malloc(sizeof(LinkList));
	if (l == NULL) {
		return false;
	}
	l->next = NULL;
	return true;
}

//ʹ��������������������ͬԪ�طŵ�һ���µĵ�������
LinkList mergeAscLinkListTheSame(LinkList a, LinkList b) {
	//p��q��ָ��ͷ���
	LNode* p = a->next, * q = b->next, * r, *n;
	r = (LNode*)malloc(sizeof(LNode));
	if (r == NULL) {
		return r;
	}
	//��rΪ������ͷ���
	r->next = NULL;

	//����������
	//�ҹ�ͬ��㣬�����һ����������ǿ϶�û��
	while (p != NULL && q != NULL) {
		if (p->data < q->data) {
			//��Ϊ������С���������ƶ���������һλ�Ƿ���q���
			p = p->next;
		}
		else if (p->data > q->data) {
			q = q->next;
		}
		else {
			n = p;
			p = p->next;
			q = q->next;
			//ͷ�巨
			n->next = r->next;
			r->next = n;
		}
	}
	return r;
}

int main020214() {
	LinkList a;
	initLinkList14(a);

	LNode* n1 = (LNode*)malloc(sizeof(LNode));
	if (n1 != NULL) {
		a->next = n1;
		n1->data = 5;
	}
	LNode* n2 = (LNode*)malloc(sizeof(LNode));
	if (n1 != NULL && n2 != NULL) {
		n2->data = 7;
		n1->next = n2;
	}
	LNode* n3 = (LNode*)malloc(sizeof(LNode));
	if (n2 != NULL && n3 != NULL) {
		n3->data = 11;
		n2->next = n3;
	}
	LNode* n4 = (LNode*)malloc(sizeof(LNode));
	if (n3 != NULL && n4 != NULL) {
		n4->data = 12;
		n3->next = n4;
		n4->next = NULL;
	}

	

	LinkList b;
	initLinkList14(b);

	LNode* n5 = (LNode*)malloc(sizeof(LNode));
	if (n5 != NULL) {
		b->next = n5;
		n5->data = 4;
	}
	LNode* n6 = (LNode*)malloc(sizeof(LNode));
	if (n5 != NULL && n6 != NULL) {
		n6->data = 8;
		n5->next = n6;
	}
	LNode* n7 = (LNode*)malloc(sizeof(LNode));
	if (n6 != NULL && n7 != NULL) {
		n7->data = 12;
		n6->next = n7;
	}
	LNode* n8 = (LNode*)malloc(sizeof(LNode));
	if (n7 != NULL && n8 != NULL) {
		n8->data = 20;
		n7->next = n8;
		n8->next = NULL;
	}

	

	LNode* p = mergeAscLinkListTheSame(a, b)->next;
	while (p != NULL) {
		printf("%d", p->data);
		puts("");
		p = p->next;
	}



	return 0;
}