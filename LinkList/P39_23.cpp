#include <iostream>
#include <cstdlib>
#include "LinkList.h"
using namespace std;

//��ʼ��������
bool initLinkList23(LinkList& l) {
	l = (LNode*)malloc(sizeof(LNode));
	if (l == NULL) {
		return false;
	}
	l->next = NULL;
	return true;
}

//���ؾ���ֵ
int absolute(int num) {
	if (num < 0) {
		return -num;
	}
	return num;
}

//�洢m�������ĵ�������������ֵ|data|��С�ڵ���������n����Ҫ��ɾ�������������о���ֵ��ͬ�Ľڵ㣬������һ�γ��ָ�ֵ�Ľڵ�
//���ø����ؼ���¼�Ѿ����ֹ���ֵ���ռ任ʱ�䣬ʵ��һ��ѭ���������
void deleteTheSameAbsolute(LinkList &l, int n) {
	if (l->next == NULL) {
		return;
	}
	LNode* p = l,* q;
	//����n+1���ڴ�ռ��Ա����ȡ��temp[n]
	int* temp = (int*)malloc(sizeof(int) * (n + 1));
	int i = 0;
	if (temp == NULL) {
		return;
	}
	//����������ֵ��ʼΪ0
	while (i < n + 1) {
		*(temp + i) = 0;
		i++;
	}
	while (p->next != NULL) {
		//��һ�γ��ְ������λ��ֵ����Ϊ1
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