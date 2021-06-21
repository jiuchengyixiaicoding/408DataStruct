#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

//初始化单链表
bool initLinkList05(LinkList& l) {
	l = (LNode*)malloc(sizeof(LNode));
	if (l == NULL) {
		return false;
	}
	l->next = NULL;
	return true;
}

//n个元素的单链表只需要移动后续的n-1个元素到前面
void moveEndToHead(LinkList& l, LNode* p, LNode* q, int i, int j, int n) {
	if (i > n-1) {
		return;
	}
	while (p->next->next != NULL) {
		p = p->next;
	}
	while (j < i) {
		q = q->next;
		j++;
	}
	p->next->next = q->next;
	q->next = p->next;
	p->next = NULL;
	p = l;
	q = l;
	moveEndToHead(l, p, q, ++i, j, n);
}

//就地逆置带头结点的单链表(就地逆置意为：空间复杂度为o(1))
void localReserveHLList(LinkList& l) {
	//单链表为空
	if (l->next == NULL) {
		return;
	}
	//单链表只有一位
	if (l->next->next == NULL) {
		return;
	}
	LNode* p = l->next;
	//n表示链表长度
	int n = 0;
	while (p != NULL) {
		n++;
		p = p->next;
	}
	//用i标记移动尾部到头部执行了几次，第一次是1
	int i = 1;
	p = l;
	LNode* q = l;
	int j = 1;
	moveEndToHead(l, p, q, i, j, n);
	
}

//参考答案
void ReserveHLList(LinkList& l) {
	LNode* p, * q;
	p = l->next;
	l->next = NULL;
	//头插法
	while (p != NULL) {
		q = p->next;
		p->next = l->next;
		l->next = p;
		p = q;
	}
}

int main020205() {

	LinkList l;
	initLinkList05(l);

	LNode* n1 = (LNode*)malloc(sizeof(LNode));
	if (n1 != NULL) {
		l->next = n1;
		n1->data = 1;
	}
	LNode* n2 = (LNode*)malloc(sizeof(LNode));
	if (n1 != NULL && n2 != NULL) {
		n2->data = 2;
		n1->next = n2;
	}
	LNode* n3 = (LNode*)malloc(sizeof(LNode));
	if (n2 != NULL && n3 != NULL) {
		n3->data = 3;
		n2->next = n3;
	}
	LNode* n4 = (LNode*)malloc(sizeof(LNode));
	if (n3 != NULL && n4 != NULL) {
		n4->data = 4;
		n3->next = n4;
		n4->next = NULL;
	}

	

	//localReserveHLList(l);
	ReserveHLList(l);

	LNode* p = l->next;

	while (p != NULL) {
		printf("%d", p->data);
		puts("");
		p = p->next;
	}
	return 0;
}