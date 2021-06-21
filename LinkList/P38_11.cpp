#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

//初始化单链表
bool initLinkList11(LinkList& l) {
	l = (LinkList)malloc(sizeof(LinkList));
	if (l == NULL) {
		return false;
	}
	l->next = NULL;
	return true;
}

//就地算法：分解一个带头节点单链表{a1,b1,a2,b2,...,...,an,bn}成两个，一个只有a，一个只有b
LinkList divideToAandB(LinkList& a) {
	LinkList b;
	initLinkList11(b);
	if (a->next == NULL) {
		return b;
	}
	LNode* p = a, * q, * r;
	//该链表存b，原链表存a
	
	//此时b为空
	q = b;

	//-------开始划分步骤--------
	//链表只有一位
	if (p->next->next == NULL) {
		return b;
	}
	int i = 1;
	//后继元素不为空（p不为空是防止最后一位是b，而b被移动到另一链表，导致p = p->next，p为NULL问题）
	while (p != NULL && p->next != NULL) {
		//后继元素为偶数
		if (i % 2 == 0) {
			//记录后继元素
			r = p->next;
			//断开后继元素连接
			p->next = p->next->next;

			//把后继元素增加到b链表表尾
			r->next = q->next;
			q->next = r;

			//移动q指针到b链表表尾
			q = q->next;
			i = i + 2;
		}
		else {
			
			i++;
		}
		p = p->next;
	}

	return b;
}

int main020211() {
	LinkList l;
	initLinkList11(l);

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

	LNode* p = divideToAandB(l)->next;
	printf("b");
	puts("");
	while (p != NULL) {
		printf("%d", p->data);
		puts("");
		p = p->next;
	}

	p = l->next;
	printf("a");
	puts("");
	while (p != NULL) {
		printf("%d", p->data);
		puts("");
		p = p->next;
	}

	return 0;
}