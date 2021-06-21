#include <iostream>
#include <cstdlib>
#include "LinkList.h"
using namespace std;

//��ʼ��������
bool initLinkList24(LinkList& l) {
	l = (LNode*)malloc(sizeof(LNode));
	if (l == NULL) {
		return false;
	}
	l->next = NULL;
	return true;
}

//��������һ�ο�����ѭ���ģ��жϵ�����û��ѭ��������У��ҵ����ѭ������ʼ��
//����P57
LNode* getLoopStart(LinkList l) {
	LNode* slow = l, * fast = l;
	while (slow != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			break;
		}
	}
	if (slow == NULL || fast == NULL) {
		return NULL;
	}
	LNode* p = l;
	while (p != slow) {
		p = p->next;
		slow = slow->next;
	}
	return p;
}

int main020224() {

	LinkList l;
	initLinkList24(l);
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
	if (n2 != NULL && n3 != NULL && n4 != NULL) {
		n4->data = 2;
		n3->next = n4;
		n4->next = n2;
	}

	printf("%d", getLoopStart(l)->data);

	LNode* p = l->next;

	free(l);
	return 0;
}