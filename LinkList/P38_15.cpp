#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

//��ʼ��������
bool initLinkList15(LinkList& l) {
	l = (LinkList)malloc(sizeof(LinkList));
	if (l == NULL) {
		return false;
	}
	l->next = NULL;
	return true;
}

//ʹ��������������������ͬԪ�طŵ�a��������
void mergeAscLinkListTheSame(LinkList &a, LinkList b) {
	//p��q��ָ��ͷ���
	LNode* p = a, * q = b, * n;

	//����������
	//�ҹ�ͬ��㣬�����һ����������ǿ϶�û��
	while (p->next != NULL && q->next != NULL) {
		if (p->next->data < q->next->data) {
			//��Ϊ������С����Ͽ�p->next���ͷ��ڴ�ռ䣬��ʱp->nextΪ�ղ�ִ�е�p->next��һλ��������һλ�Ƿ���q���
			n = p->next;
			p->next = n->next;
			free(n);
		}
		else if (p->next->data > q->next->data) {
			q = q->next;
		}
		else {
			p = p->next;
			q = q->next;
		}
	}
	
}

int main020215() {
	LinkList a;
	initLinkList15(a);

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
	initLinkList15(b);

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

	mergeAscLinkListTheSame(a, b);

	LNode* p = a->next;
	while (p != NULL) {
		printf("%d", p->data);
		puts("");
		p = p->next;
	}



	return 0;
}