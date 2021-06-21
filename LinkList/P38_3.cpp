#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

//初始化单链表
bool initLinkList03(LinkList& l) {
	l = (LNode*)malloc(sizeof(LNode));
	if (l == NULL) {
		return false;
	}
	l->next = NULL;
	return true;
}

//逆序输出带头指针单链表
void printfHeadLinkListReverse(LinkList l) {
	if (l->next == NULL) {
		return;
	}
	LNode* temp = l->next;

	if (temp->next == NULL) {
		printf("%d", temp->data);
		return;
	}
	while (temp->next->next != NULL) {
		temp = temp->next;
	}
	
	LNode* n = temp->next;
	printf("%d", n->data);
	temp->next = NULL;
	free(n);
	printfHeadLinkListReverse(l);
}

int main020203() {

	LinkList l;
	initLinkList03(l);

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

	l->next = n1;

	printfHeadLinkListReverse(l);

	return 0;
}