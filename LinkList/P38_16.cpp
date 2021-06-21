#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

//��ʼ��������
bool initLinkList16(LinkList& l) {
	l = (LinkList)malloc(sizeof(LinkList));
	if (l == NULL) {
		return false;
	}
	l->next = NULL;
	return true;
}

//�ж�b�����Ƿ�Ϊa�������һ�������У���һ�α������������Ĳ��֣�
bool isLinkBIncludeByLinkA(LinkList a, LinkList b) {
	//p��q��ָ���һ�����
	LNode* p = a->next, * q = b->next;
	//a����Ϊ�գ����뱣֤ÿ��ѭ��ʱqָ���һ���ڵ�
	while (p != NULL) {
		if (p->data != q->data) {
			p = p->next;
		}
		else {
			//���һ��δ���ƥ��p�Ѿ�Ϊ�գ�q != NULL
			//������������ڵ�ֵ����ȣ�q != NULL
			//�������ƥ�����q == NULL
			while (p != NULL && q != NULL && p->data == q->data) {
				p = p->next;
				q = q->next;
			}
			//�����ղŵ�ѭ����ֻ��b������a�����ĳһ����ȫ��ͬq�Ż���NULL�������棬�������p����һ���ڵ�
			if (q == NULL) {
				return true;
			}
			else {
				q = b->next;
			}
		}
	}
	//pΪ�ջ���ûƥ�䵽
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