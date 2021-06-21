#include <iostream>
#include <cstdlib>
#include "LinkList.h"
using namespace std;

//初始化单链表
bool initLinkList25(LinkList& l) {
	l = (LNode*)malloc(sizeof(LNode));
	if (l == NULL) {
		return false;
	}
	l->next = NULL;
	return true;
}

void sortList(LinkList& l) {
	//数组为空或只有一位直接结束函数
	if (l->next == NULL || l->next->next == NULL) {
		return;
	}
	LNode* p = l, * q = l,* r, * z;
	//若表长偶数使p走一步，q走两步，这样q到最后p则在中间（偏左边）
	//若表长奇数使p走一步，q走两步，最后一次两个都只走一步，这样q到最后p则在正中间
	while (q->next != NULL) {
		p = p->next;
		q = q->next;
		if (q->next != NULL) {
			q = q->next;
		}
	}
	//此时划分开前半段和后半段，需要逆置的是p往后的后半段位置
	r = p->next;
	//切断前后段
	p->next = NULL;
	//此时要用q为后半段首节点，把后半段用头插法逆置
	while (r != q) {
		z = r->next;
		r->next = q->next;
		q->next = r;
		r = z;
	}
	//---------开始合并----------
	p = l->next;
	//这里q长度等于p或等于p-1，所以用q作判断
	while (q != NULL) {
		z = q->next;
		r = p->next;
		q->next = p->next;
		p->next = q;
		q = z;
		p = r;
	}
}

int main() {

	LinkList l;
	initLinkList25(l);
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

	sortList(l);

	LNode* p = l->next;

	while (p != NULL) {
		printf("%d", p->data);
		puts("");
		p = p->next;
	}

	free(l);
	return 0;
}