#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

//初始化单链表
bool initLinkList12(LinkList& l) {
	l = (LinkList)malloc(sizeof(LinkList));
	if (l == NULL) {
		return false;
	}
	l->next = NULL;
	return true;
}

//使递增有序单链表中没有重复元素
bool makeListDistinct(LinkList& l) {
	if (l->next == NULL) {
		return false;
	}
	LNode* p = l->next, * n;
	while (p->next != NULL) {
		if (p->data == p->next->data) {
			n = p->next;
			p->next = n->next;
			free(n);
		}
		else {
			p = p->next;
		}
	}
	return true;
}

int main020212() {
	LinkList l;
	initLinkList12(l);

	LNode* n1 = (LNode*)malloc(sizeof(LNode));
	if (n1 != NULL) {
		l->next = n1;
		n1->data = 5;
	}
	LNode* n2 = (LNode*)malloc(sizeof(LNode));
	if (n1 != NULL && n2 != NULL) {
		n2->data = 5;
		n1->next = n2;
	}
	LNode* n3 = (LNode*)malloc(sizeof(LNode));
	if (n2 != NULL && n3 != NULL) {
		n3->data = 5;
		n2->next = n3;
	}
	LNode* n4 = (LNode*)malloc(sizeof(LNode));
	if (n3 != NULL && n4 != NULL) {
		n4->data = 8;
		n3->next = n4;
		n4->next = NULL;
	}

	

	if (makeListDistinct(l)) {
		LNode* p = l->next;
		while (p != NULL) {
			printf("%d", p->data);
			puts("");
			p = p->next;
		}
	}

	

	return 0;
}