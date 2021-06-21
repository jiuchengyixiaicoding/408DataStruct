#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

//初始化单链表
bool initLinkList13(LinkList& l) {
	l = (LinkList)malloc(sizeof(LinkList));
	if (l == NULL) {
		return false;
	}
	l->next = NULL;
	return true;
}

//使两个有序递增单链表合并为一个有序递减单链表
LinkList mergeAscLinkList(LinkList &a, LinkList &b) {
	//p，q都指向头结点
	LNode* p = a, * q = b, * r, * n;
	r = (LNode*)malloc(sizeof(LNode));
	if (r == NULL) {
		return r;
	}
	//设r为新链表头结点
	r->next = NULL;
	
	while (p->next != NULL || q->next != NULL) {
		//两链表都不空
		if (p->next != NULL && q->next != NULL) {
			//若p->next比q->next值大，把p->next加到新链表头结点后面，p->next的后续元素往前推一位，p->next比q->next则操作p->next
			if (p->next->data < q->next->data) {
				n = p->next;
				p->next = n->next;
				//把p->next用头插法加到新链表头结点后面（有序递减）
				n->next = r->next;
				r->next = n;
			}
			else {
				n = q->next;
				q->next = n->next;
				n->next = r->next;
				r->next = n;
			}
		}
		//有一个链表已经为空
		else if(p->next != NULL && q->next == NULL) {
			n = p->next;
			p = p->next;
			//把p->next用头插法加到新链表头结点后面（有序递减）
			n->next = r->next;
			r->next = n;
		}
		else {
			n = q->next;
			q->next = n->next;
			//把p->next用头插法加到新链表头结点后面（有序递减）
			n->next = r->next;
			r->next = n;
		}
	}
	return r;
}

int main02013() {
	LinkList a;
	initLinkList13(a);

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
	initLinkList13(b);

	LNode* n5 = (LNode*)malloc(sizeof(LNode));
	if (n5 != NULL) {
		b->next = n5;
		n5->data = 4;
	}
	LNode* n6 = (LNode*)malloc(sizeof(LNode));
	if (n5 != NULL && n6 != NULL) {
		n6->data = 8;
		n5->next = n6;
	}
	LNode* n7 = (LNode*)malloc(sizeof(LNode));
	if (n6 != NULL && n7 != NULL) {
		n7->data = 12;
		n6->next = n7;
	}
	LNode* n8 = (LNode*)malloc(sizeof(LNode));
	if (n7 != NULL && n8 != NULL) {
		n8->data = 20;
		n7->next = n8;
		n8->next = NULL;
	}

	LNode* p = mergeAscLinkList(a, b)->next;
	while (p != NULL) {
		printf("%d", p->data);
		puts("");
		p = p->next;
	}



	return 0;
}