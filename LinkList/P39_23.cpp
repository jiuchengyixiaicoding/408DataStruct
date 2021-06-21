#include <iostream>
#include <cstdlib>
#include "LinkList.h"
using namespace std;

//初始化单链表
bool initLinkList23(LinkList& l) {
	l = (LNode*)malloc(sizeof(LNode));
	if (l == NULL) {
		return false;
	}
	l->next = NULL;
	return true;
}

//返回绝对值
int absolute(int num) {
	if (num < 0) {
		return -num;
	}
	return num;
}

//存储m个整数的单链表，链表所有值|data|都小于等于正整数n。现要求删除单链表内所有绝对值相同的节点，保留第一次出现该值的节点
//利用辅助控件记录已经出现过的值，空间换时间，实现一遍循环解决问题
void deleteTheSameAbsolute(LinkList &l, int n) {
	if (l->next == NULL) {
		return;
	}
	LNode* p = l,* q;
	//申请n+1个内存空间以便可以取到temp[n]
	int* temp = (int*)malloc(sizeof(int) * (n + 1));
	int i = 0;
	if (temp == NULL) {
		return;
	}
	//把数组所有值初始为0
	while (i < n + 1) {
		*(temp + i) = 0;
		i++;
	}
	while (p->next != NULL) {
		//第一次出现把数组该位置值设置为1
		i = absolute(p->next->data);
		if (*(temp + i) == 0) {
			p = p->next;
			*(temp + i) = 1;
		}
		else {
			q = p->next;
			p->next = q->next;
			free(q);
		}
	}
	free(temp);
}

int main020223() {

	LinkList l;
	initLinkList23(l);
	LNode* n1 = (LNode*)malloc(sizeof(LNode));
	if (n1 != NULL) {
		l->next = n1;
		n1->data = 1;
	}
	LNode* n2 = (LNode*)malloc(sizeof(LNode));
	if (n1 != NULL && n2 != NULL) {
		n2->data = -1;
		n1->next = n2;
	}
	LNode* n3 = (LNode*)malloc(sizeof(LNode));
	if (n2 != NULL && n3 != NULL) {
		n3->data = -2;
		n2->next = n3;
	}
	LNode* n4 = (LNode*)malloc(sizeof(LNode));
	if (n3 != NULL && n4 != NULL) {
		n4->data = 2;
		n3->next = n4;
		n4->next = NULL;
	}

	deleteTheSameAbsolute(l, 2);

	LNode* p = l->next;

	while (p != NULL) {
		printf("%d", p->data);
		puts("");
		p = p->next;
	}

	free(l);
	return 0;
}