#include <iostream>
#include <cstdlib>

using namespace std;
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

//初始化循环单链表
bool initLinkList19(LinkList& l) {
	l = (LinkList)malloc(sizeof(LinkList));
	if (l == NULL) {
		return false;
	}
	l->next = l;
	return true;
}

//循环输出并删除链表的最小值，直到链表为空
void printfMinAndFree(LinkList& a) {
	//min表示最小值节点，minPre表示最小值节点的前一个节点
	LNode* n = a->next, * p, * min, * minPre = a;

	//n == a表示链表为空
	while (a->next != a) {
		//用p存储此时链表的第一个节点
		p = a->next;
		//暂令最小值为第一个节点
		min = p;
		//循环找出链表里最小值和最小值的前一个节点
		while (p->next != a) {
			if (min->data > p->next->data) {
				minPre = p;
				min = p->next;
			}
			p = p->next;
		}
		//从单链表断开min
		minPre->next = min->next;
		
		
		printf("%d", min->data);
		puts("");
		free(min);
		
	}
	
}

int main020219() {
	LinkList a;
	initLinkList19(a);

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
	printfMinAndFree(a);
	return 0;
}