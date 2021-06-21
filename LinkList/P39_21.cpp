#include <iostream>
#include <cstdlib>
#include "LinkList.h"
using namespace std;

//��ʼ��������
bool initLinkList21(LinkList& l) {
	l = (LNode*)malloc(sizeof(LNode));
	if (l == NULL) {
		return false;
	}
	l->next = NULL;
	return true;
}

//һ��ѭ�����ҳ���������k��Ԫ�ز�������ɹ�����1��ʧ�ܷ���0
//�㷨˼�룺�������p��qָ������ĵ�һ��Ԫ�أ��Ƚ�p�����ƶ���kλ�ã���ʱp��q���Ԫ���ܺ�Ϊk��
//�ٰ�p��qͬʱ�����ƶ�ֱ��qָ��ָ���β����ʱpλ�ü�Ϊ������k��Ԫ��
//�ռ临�Ӷ�O��1��ʱ�临�Ӷ�O��n��
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
	//����ѭ���껹δ�ƶ���kλ��
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