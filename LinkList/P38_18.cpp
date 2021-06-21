#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

//初始化循环单链表
bool initLinkList18(LinkList& l) {
	l = (LinkList)malloc(sizeof(LinkList));
	if (l == NULL) {
		return false;
	}
	l->next = l;
	return true;
}

void mergeBToA(LinkList &a, LinkList &b) {
	LNode*p = a, * q = b;
	while (p->next != a) {
		p = p->next;
	}
	while (q->next != b) {
		q = q->next;
	}
	p->next = b;
	q->next = a;
}

int main020218() {
	LinkList a;
	initLinkList18(a);

	LNode* n1 = (LNode*)malloc(sizeof(LNode));
	if (n1 != NULL) {
		n1->data = 5;
		a->next = n1;
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
		n4->next = a;
	}

	

	LinkList b;
	initLinkList18(b);

	LNode* n5 = (LNode*)malloc(sizeof(LNode));
	if (n5 != NULL) {
		n5->data = 11;
		b->next = n5;
	}
	LNode* n6 = (LNode*)malloc(sizeof(LNode));
	if (n5 != NULL && n6 != NULL) {
		n6->data = 12;
		n5->next = n6;
		n6->next = b;
	}

	mergeBToA(a, b);

	LNode* p = a->next;
	while (p != a) {
		printf("%d", p->data);
		puts("");
		p = p->next;
	}

	return 0;
}