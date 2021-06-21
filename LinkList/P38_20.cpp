#include <iostream>
#include <cstdlib>
#include "LinkList.h"
using namespace std;

//初始化非循环双链表
bool initDLinkList20(DLinkList& l) {
	l = (DLinkList)malloc(sizeof(DLinkList));
	if (l == NULL) {
		return false;
	}
	l->pred = NULL;
	l->next = NULL;
	l->freq = 0;
	return true;
}

//访问值为x的元素，使访问频度freq+1，并且把链表按访问频度递减排列（相等频度下，最新访问放最前），使访问频度高的元素保持在能较快访问的链表前部
DLinkList locate(DLinkList &l, int x) {
	
	DNode* p = l, * q, * r;
	DLinkList temp;
	if (!initDLinkList20(temp)) {
		return NULL;
	}
	q = temp;
	while (p->next != NULL) {
		if (p->next->data == x) {
			//增加访问频度
			p->next->freq++;
			//断开r链接
			r = p->next;
			p->next = r->next;
			//防止r为表尾的情况
			if(r->next != NULL)
				r->next->pred = p;

			//存r到临时带头结点链表（使用带头结点链表原因：表头插入与其他位置插入操作一致）
			//注意r->next = q->next不能漏保证表位的next位是NULL
			r->next = q->next;
			q->next = r;
			r->pred = q;
			//移动临时链表指针至表位
			q = q->next;
		}
		else {
			//无操作情况下把原链表指针往后移
			p = p->next;
		}
	}
	//----------上述操作完毕原链表值为x的节点都断开存放到临时链表-------------
	//此时q指向临时链表表尾
	p = l;
	//频度小于等于当前访问频度
	while (p->next != NULL && p->next->freq < q->freq) {
		p = p->next;
	}
	//插入临时表到频度小于q且大于或等于q的元素之间
	q->next = p->next;
	p->next = temp->next;
	
	return temp;
}

int main020220() {
	
	DLinkList l;
	if (initDLinkList20(l)) {

		DNode* n1 = (DNode*)malloc(sizeof(DNode));
		if (n1 != NULL) {
			n1->data = 5;
			n1->freq = 0;
			l->next = n1;
			n1->pred = l;
		}
		DNode* n2 = (DNode*)malloc(sizeof(DNode));
		if (n1 != NULL && n2 != NULL) {
			n2->data = 7;
			n2->freq = 0;
			n1->next = n2;
			n2->pred = n1;
		}
		DNode* n3 = (DNode*)malloc(sizeof(DNode));
		if (n2 != NULL && n3 != NULL) {
			n3->data = 11;
			n3->freq = 0;
			n2->next = n3;
			n3->pred = n2;
		}
		DNode* n4 = (DNode*)malloc(sizeof(DNode));
		if (n3 != NULL && n4 != NULL) {
			n4->data = 5;
			n4->freq = 0;
			n3->next = n4;
			n4->pred = n3;
			n4->next = NULL;
		}
		
		
		DNode* p = locate(l, 5)->next;
		while (p != NULL) {
			printf("%p", p);
			puts("");
			p = p->next;
		}
	}
	
	cout << "exit！" << endl;
	return 0;
}