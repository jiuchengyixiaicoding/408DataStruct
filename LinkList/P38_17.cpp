#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct DNode {
	int data;
	struct DNode* pre;
	struct DNode* next;
}DNode, * DLinkList;

//初始化循环双链表
bool initLinkList17(DLinkList& l) {
	l = (DLinkList)malloc(sizeof(DLinkList));
	if (l == NULL) {
		return false;
	}
	l->pre = l;
	l->next = l;
	return true;
}


//判断带头结点双向循环链表是否对称
bool isSymmetryLink(DLinkList l) {
	//把双向循环链表折半比较，循环跳出条件：表长奇数p == q，表长偶数p->next == q
	DNode* p = l->next,* q = l->pre;
	//这里判断写成q->next != p的原因是在这里q和p已经错过了此时的q是p之前的位置，p是q之前的位置
	while (p != q && q->next != p) {
		if (p->data != q->data) {
			return false;
		}
		else {
			p = p->next;
			q = q->pre;
		}
	}
	
	return true;
}

int main020217() {
	DLinkList l;
	initLinkList17(l);

	DNode* n1 = (DNode*)malloc(sizeof(DNode));
	if (n1 != NULL) {
		n1->data = 5;
		l->next = n1;
		n1->pre = l;
	}
	DNode* n2 = (DNode*)malloc(sizeof(DNode));
	if (n1 != NULL && n2 != NULL) {
		n2->data = 4;
		n1->next = n2;
		n2->pre = n1;
	}
	DNode* n3 = (DNode*)malloc(sizeof(DNode));
	if (n2 != NULL && n3 != NULL) {
		n3->data = 3;
		n2->next = n3;
		n3->pre = n2;
	}
	DNode* n4 = (DNode*)malloc(sizeof(DNode));
	if (n3 != NULL && n4 != NULL) {
		n4->data = 4;
		n3->next = n4;
		n4->pre = n3;
	}
	DNode* n5 = (DNode*)malloc(sizeof(DNode));
	if (n4 != NULL && n5 != NULL) {
		n5->data = 5;
		n4->next = n5;
		n5->pre = n4;
		n5->next = l;
		l->pre = n5;
	}
	printf("%d", isSymmetryLink(l));

	return 0;
}