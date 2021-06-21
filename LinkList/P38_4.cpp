#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

//初始化单链表
bool initLinkList04(LinkList& l) {
	l = (LNode*)malloc(sizeof(LNode));
	if (l == NULL) {
		return false;
	}
	l->next = NULL;
	return true;
}

//在带头结点的单链表删除最小值
void removeMinHLList(LinkList &l, int &e) {
	if (l->next == NULL) {
		return;
	}
	
	LNode* p = l->next;
	LNode* n = NULL;
	e = p->data;
	while (p != NULL) {
		p = p->next;
		if (p != NULL && e > p->data) {
			e = p->data;
			n = p;
		}
	}
	p = l->next;
	while (p->next != NULL) {
		if (p->next == n) {
			p->next = n->next;
			free(n);
			return;
		}
		p = p->next;
	}
}

int main020204() {

	LinkList l;
	initLinkList04(l);

	LNode* n1 = (LNode*)malloc(sizeof(LNode));
	if (n1 != NULL) {
		l->next = n1;
		n1->data = 4;
	}
	LNode* n2 = (LNode*)malloc(sizeof(LNode));
	if (n1 != NULL && n2 != NULL) {
		n2->data = 5;
		n1->next = n2;
	}
	LNode* n3 = (LNode*)malloc(sizeof(LNode));
	if (n2 != NULL && n3 != NULL) {
		n3->data = 2;
		n2->next = n3;
	}
	LNode* n4 = (LNode*)malloc(sizeof(LNode));
	if (n3 != NULL && n4 != NULL) {
		n4->data = 3;
		n3->next = n4;
		n4->next = NULL;
	}
	
	int e;
	removeMinHLList(l, e);
	printf("%d", e);
	puts("");

	LNode* p = l;
	p = l->next;

	while (p != NULL) {
		printf("%d", p->data);
		puts("");
		p = p->next;
	}
	return 0;
}