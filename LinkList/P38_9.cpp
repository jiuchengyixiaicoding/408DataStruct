#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

//��ʼ��������
bool initLinkList09(LinkList& l) {
	l = (LinkList)malloc(sizeof(LinkList));
	if (l == NULL) {
		return false;
	}
	l->next = NULL;
	return true;
}

//����С����˳�����������Ԫ�أ������ɾ����Ԫ��
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
		//���r��z��ֵ�ǳ�ʼֵ��˵���ǵ�һ��Ԫ�ؿ�����ǰ�ڵ�z���ӵ���̽ڵ�r�ĺ�̽ڵ�ɾ��r
		if (r != p) {
			z->next = r->next;
		}
		//��һ��Ԫ��ֱ���ƶ������λ����ʱr=p��free(r)
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