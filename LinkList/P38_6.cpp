#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

//��ʼ��������
bool initLinkList06(LinkList& l) {
	l = (LNode*)malloc(sizeof(LNode));
	if (l == NULL) {
		return false;
	}
	l->next = NULL;
	return true;
}

//ʹ��ͷ��������������
void ascHLList(LinkList& l) {
	LNode* p = l->next;
	LNode* q = p->next;
	LNode* r;
	//ʹ������ֳ����Σ���һ�� ��ͷ���͵�һ��Ԫ�ص����� �ڶ��� ����ͷ����ʣ��Ԫ��
	p->next = NULL;

	//
	while (q != NULL) {
		//����ǰq�е�ֵ
		p = q;
		//��¼�ڶ�����ʣ��Ԫ�ط�ֹ����
		q = q->next;
		r = l;
		//���������ѭ�������˵������������Ԫ�ض���q�ڵ�ֵС������ĩβ
		//δ�����q��ֵ��r�м�����������Ĵ�ģ�����뵽���ֵǰ��
		while (r->next != NULL && r->next->data < p->data) {
			r = r->next;
		}
		//����p��r��r->next֮�䣬����Ĳ���ǰ���������q=q->next�����
		p->next = r->next;
		r->next = p;
	}
}

int main020206() {

	LinkList l;
	initLinkList06(l);

	LNode* n1 = (LNode*)malloc(sizeof(LNode));
	if (n1 != NULL) {
		l->next = n1;
		n1->data = 4;
	}
	LNode* n2 = (LNode*)malloc(sizeof(LNode));
	if (n1 != NULL && n2 != NULL) {
		n2->data = 3;
		n1->next = n2;
	}
	LNode* n3 = (LNode*)malloc(sizeof(LNode));
	if (n2 != NULL && n3 != NULL) {
		n3->data = 2;
		n2->next = n3;
	}
	LNode* n4 = (LNode*)malloc(sizeof(LNode));
	if (n3 != NULL && n4 != NULL) {
		n4->data = 1;
		n3->next = n4;
		n4->next = NULL;
	}

	

	ascHLList(l);

	LNode* p = l->next;

	while (p != NULL) {
		printf("%d", p->data);
		puts("");
		p = p->next;
	}
	return 0;
}