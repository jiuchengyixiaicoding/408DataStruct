#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

//初始化单链表
bool initLinkList06(LinkList& l) {
	l = (LNode*)malloc(sizeof(LNode));
	if (l == NULL) {
		return false;
	}
	l->next = NULL;
	return true;
}

//使带头结点链表有序递增
void ascHLList(LinkList& l) {
	LNode* p = l->next;
	LNode* q = p->next;
	LNode* r;
	//使单链表分成两段：第一段 带头结点和第一个元素的链表 第二段 不带头结点的剩余元素
	p->next = NULL;

	//
	while (q != NULL) {
		//代表当前q中的值
		p = q;
		//记录第二段中剩余元素防止断链
		q = q->next;
		r = l;
		//两种情况，循环到最后，说明链表里所有元素都比q内的值小，插入末尾
		//未到最后，q的值在r中间就遇到比它的大的，则插入到这个值前面
		while (r->next != NULL && r->next->data < p->data) {
			r = r->next;
		}
		//插入p到r与r->next之间，这里的操作前面如果不做q=q->next会断链
		p->next = r->next;
		r->next = p;
	}
}

int main020206() {

	LinkList l;
	initLinkList06(l);

	LNode* n1 = (LNode*)malloc(sizeof(LNode));
	if (n1 != NULL) {
		l->next = n1;
		n1->data = 4;
	}
	LNode* n2 = (LNode*)malloc(sizeof(LNode));
	if (n1 != NULL && n2 != NULL) {
		n2->data = 3;
		n1->next = n2;
	}
	LNode* n3 = (LNode*)malloc(sizeof(LNode));
	if (n2 != NULL && n3 != NULL) {
		n3->data = 2;
		n2->next = n3;
	}
	LNode* n4 = (LNode*)malloc(sizeof(LNode));
	if (n3 != NULL && n4 != NULL) {
		n4->data = 1;
		n3->next = n4;
		n4->next = NULL;
	}

	

	ascHLList(l);

	LNode* p = l->next;

	while (p != NULL) {
		printf("%d", p->data);
		puts("");
		p = p->next;
	}
	return 0;
}