#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

//��ʼ��������
bool initLinkList13(LinkList& l) {
	l = (LinkList)malloc(sizeof(LinkList));
	if (l == NULL) {
		return false;
	}
	l->next = NULL;
	return true;
}

//ʹ�����������������ϲ�Ϊһ������ݼ�������
LinkList mergeAscLinkList(LinkList &a, LinkList &b) {
	//p��q��ָ��ͷ���
	LNode* p = a, * q = b, * r, * n;
	r = (LNode*)malloc(sizeof(LNode));
	if (r == NULL) {
		return r;
	}
	//��rΪ������ͷ���
	r->next = NULL;
	
	while (p->next != NULL || q->next != NULL) {
		//����������
		if (p->next != NULL && q->next != NULL) {
			//��p->next��q->nextֵ�󣬰�p->next�ӵ�������ͷ�����棬p->next�ĺ���Ԫ����ǰ��һλ��p->next��q->next�����p->next
			if (p->next->data < q->next->data) {
				n = p->next;
				p->next = n->next;
				//��p->next��ͷ�巨�ӵ�������ͷ�����棨����ݼ���
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
		//��һ�������Ѿ�Ϊ��
		else if(p->next != NULL && q->next == NULL) {
			n = p->next;
			p = p->next;
			//��p->next��ͷ�巨�ӵ�������ͷ�����棨����ݼ���
			n->next = r->next;
			r->next = n;
		}
		else {
			n = q->next;
			q->next = n->next;
			//��p->next��ͷ�巨�ӵ�������ͷ�����棨����ݼ���
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