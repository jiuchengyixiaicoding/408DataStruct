#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

//初始化单链表
bool initLinkList16(LinkList& l) {
	l = (LinkList)malloc(sizeof(LinkList));
	if (l == NULL) {
		return false;
	}
	l->next = NULL;
	return true;
}

//判断b链表是否为a链表里的一段子序列（即一段被包含且连续的部分）
bool isLinkBIncludeByLinkA(LinkList a, LinkList b) {
	//p，q都指向第一个结点
	LNode* p = a->next, * q = b->next;
	//a链表不为空，必须保证每次循环时q指向第一个节点
	while (p != NULL) {
		if (p->data != q->data) {
			p = p->next;
		}
		else {
			//情况一：未完成匹配p已经为空，q != NULL
			//情况二：两个节点值不相等，q != NULL
			//情况三：匹配完成q == NULL
			while (p != NULL && q != NULL && p->data == q->data) {
				p = p->next;
				q = q->next;
			}
			//经过刚才的循环后，只有b链表与a链表的某一段完全相同q才会是NULL，返回真，否则回退p到第一个节点
			if (q == NULL) {
				return true;
			}
			else {
				q = b->next;
			}
		}
	}
	//p为空还是没匹配到
	return false;
}

int main020216() {
	LinkList a;
	initLinkList16(a);

	LNode* n1 = (LNode*)malloc(sizeof(LNode));
	if (n1 != NULL) {
		a->next = n1;
		n1->data = 5;
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
		n4->next = NULL;
	}

	LinkList b;
	initLinkList16(b);

	LNode* n5 = (LNode*)malloc(sizeof(LNode));
	if (n5 != NULL) {
		b->next = n5;
		n5->data = 11;
	}
	LNode* n6 = (LNode*)malloc(sizeof(LNode));
	if (n5 != NULL && n6 != NULL) {
		n6->data = 12;
		n5->next = n6;
		n6->next = NULL;
	}

	printf("%d", isLinkBIncludeByLinkA(a, b));

	return 0;
}