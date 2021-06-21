#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

//初始化单链表
bool initLinkList09(LinkList& l) {
	l = (LinkList)malloc(sizeof(LinkList));
	if (l == NULL) {
		return false;
	}
	l->next = NULL;
	return true;
}

//按从小到大顺序输出链表内元素，输出后删除该元素
void printAndFreeOrderAsc(LinkList& l) {
	LNode* p = l->next, * q, * r, * z;

	while (p != NULL) {

		r = p;
		q = p;
		z = p;
		while (q->next != NULL) {
			if (q->next->data < r->data) {
				z = q;
				r = q->next;
			}
			q = q->next;
		}
		//如果r或z的值非初始值，说明非第一个元素可以用前节点z连接到后继节点r的后继节点删除r
		if (r != p) {
			z->next = r->next;
		}
		//第一个元素直接移动到后继位，此时r=p，free(r)
		else {
			p = p->next;
		}

		printf("%d", r->data);
		free(r);

	}
}

int main020209() {
	LinkList l;
	initLinkList09(l);

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

	

	printAndFreeOrderAsc(l);

	return 0;
}