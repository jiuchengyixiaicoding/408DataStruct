#include <iostream>
#include <cstdlib>
#include "LinkList.h"
using namespace std;

//��ʼ��������
bool initLinkList25(LinkList& l) {
	l = (LNode*)malloc(sizeof(LNode));
	if (l == NULL) {
		return false;
	}
	l->next = NULL;
	return true;
}

void sortList(LinkList& l) {
	//����Ϊ�ջ�ֻ��һλֱ�ӽ�������
	if (l->next == NULL || l->next->next == NULL) {
		return;
	}
	LNode* p = l, * q = l,* r, * z;
	//����ż��ʹp��һ����q������������q�����p�����м䣨ƫ��ߣ�
	//��������ʹp��һ����q�����������һ��������ֻ��һ��������q�����p�������м�
	while (q->next != NULL) {
		p = p->next;
		q = q->next;
		if (q->next != NULL) {
			q = q->next;
		}
	}
	//��ʱ���ֿ�ǰ��κͺ��Σ���Ҫ���õ���p����ĺ���λ��
	r = p->next;
	//�ж�ǰ���
	p->next = NULL;
	//��ʱҪ��qΪ�����׽ڵ㣬�Ѻ�����ͷ�巨����
	while (r != q) {
		z = r->next;
		r->next = q->next;
		q->next = r;
		r = z;
	}
	//---------��ʼ�ϲ�----------
	p = l->next;
	//����q���ȵ���p�����p-1��������q���ж�
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