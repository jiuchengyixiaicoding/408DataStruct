#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

//初始化单链表
bool initLinkList10(LinkList& l) {
	l = (LinkList)malloc(sizeof(LinkList));
	if (l == NULL) {
		return false;
	}
	l->next = NULL;
	return true;
}

//分解一个带头节点单链表成两个，一个只有奇数，一个只有偶数
//原链表方法执行完后就是奇数链表，因此只要返回一个偶数链表
LinkList divideToSingleAndEven(LinkList& l) {
	LNode* p = l, * q, * r;
	//该链表存偶数，原链表存奇数
	LinkList even;
	initLinkList10(even);
	//此时偶数表为空
	q = even;

	//-------开始划分步骤--------
	
	//后继元素不为空（p不为空是防止最后一位是偶数，而偶数被移动到另一链表，导致p = p->next，p为NULL问题）
	while (p != NULL && p->next != NULL) {
		//后继元素为偶数
		if (p->next->data % 2 == 0) {
			//记录后继元素
			r = p->next;
			//断开后继元素连接
			p->next = p->next->next;

			//把后继元素增加到偶数链表表尾
			r->next = q->next;
			q->next = r;
			
			//移动q指针到偶数链表表尾
			q = q->next;
			
		}
		else {
			p = p->next;
		}

	}
	
	return even;
}

int main020210() {
	LinkList l;
	initLinkList10(l);

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

	

	LNode* p = divideToSingleAndEven(l)->next;
	printf("偶数");
	puts("");
	while (p != NULL) {
		printf("%d", p->data);
		puts("");
		p = p->next;
	}
	
	p = l->next;
	printf("奇数");
	puts("");
	while (p != NULL) {
		printf("%d", p->data);
		puts("");
		p = p->next;
	}

	return 0;
}