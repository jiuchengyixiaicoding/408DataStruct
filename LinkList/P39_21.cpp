#include <iostream>
#include <cstdlib>
#include "LinkList.h"
using namespace std;

//初始化单链表
bool initLinkList21(LinkList& l) {
	l = (LNode*)malloc(sizeof(LNode));
	if (l == NULL) {
		return false;
	}
	l->next = NULL;
	return true;
}

//一遍循环查找出链表倒数第k个元素并输出，成功返回1，失败返回0
//算法思想：定义变量p和q指向链表的第一个元素，先将p往后移动到k位置，此时p与q间的元素总和为k。
//再把p，q同时往后移动直到q指针指向表尾，此时p位置即为倒数第k个元素
//空间复杂度O（1）时间复杂度O（n）
int findReciprocalKAndPrintf(LinkList l, int k) {
	if (l->next == NULL) {
		return 0;
	}
	LNode* p = l->next, * q = l->next;
	int i = 1;
	while (q->next != NULL) {
		if (i < k) {
			i++;
		}
		else {
			p = p->next;
		}
		q = q->next;
	}
	//链表循环完还未移动到k位置
	if (i < k) {
		return 0;
	}
	printf("%d", p->data);
	return 1;
}

int main020221() {

	LinkList l;
	initLinkList21(l);
	LNode* n1 = (LNode*)malloc(sizeof(LNode));
	if (n1 != NULL) {
		l = n1;
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

	printf("\n%d", findReciprocalKAndPrintf(l, 2));

	free(l);
	return 0;
}