#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

//初始化单链表
bool initLinkList01(LinkList& l) {
	l = (LNode*)malloc(sizeof(LNode));
	if (l == NULL) {
		return false;
	}
	l->next = NULL;
	return true;
}

//在不带头结点的单链表删除值为x的元素
void deleteElemNoHeadLinkList(LinkList &l, int x) {
	
	LNode* temp;
	if (l == NULL) {
		return;
	}
	if (l->data == x) {
		temp = l;
		l = l->next;
		free(temp);
		deleteElemNoHeadLinkList(l, x);
	}
	else {
		deleteElemNoHeadLinkList(l->next, x);
	}
	
	
}

int main020201() {

	LinkList l;
	initLinkList01(l);
	LNode* n1 = (LNode*)malloc(sizeof(LNode));
	if (n1 != NULL) {
		n1->data = 1;
	}
	LNode* n2 = (LNode*)malloc(sizeof(LNode));
	if (n1 != NULL && n2 != NULL) {
		n2->data = 1;
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

	l = n1;

	deleteElemNoHeadLinkList(l, 1);

	LNode* p = l;

	while (p != NULL) {
		printf("%d", p->data);
		puts("");
		p = p->next;
	}
	return 0;
}