#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

//初始化单链表
bool initLinkList02(LinkList& l) {
	l = (LNode*)malloc(sizeof(LNode));
	if (l == NULL) {
		return false;
	}
	l->next = NULL;
	return true;
}

//在带头结点的单链表删除值为x的元素
void deleteElemHeadLinkList(LinkList& l, int x) {
	if (l->next == NULL) {
		return;
	}
	LNode* temp = l->next;
	
	if (temp->data == x) {
		l->next = temp->next;
		free(temp);
		deleteElemHeadLinkList(l, x);
	}
	else {
		deleteElemHeadLinkList(l->next, x);
	}

}

int main020202() {

	LinkList l;
	initLinkList02(l);

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
	l ->next = n1;

	deleteElemHeadLinkList(l, 1);

	LNode* p = l->next;

	while (p != NULL) {
		printf("%d", p->data);
		puts("");
		p = p->next;
	}
	return 0;
}