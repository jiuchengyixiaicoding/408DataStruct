#include <iostream>
#include <cstdlib>
#include "LinkList.h"
using namespace std;

//��ʼ����ѭ��˫����
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

//����ֵΪx��Ԫ�أ�ʹ����Ƶ��freq+1�����Ұ���������Ƶ�ȵݼ����У����Ƶ���£����·��ʷ���ǰ����ʹ����Ƶ�ȸߵ�Ԫ�ر������ܽϿ���ʵ�����ǰ��
DLinkList locate(DLinkList &l, int x) {
	
	DNode* p = l, * q, * r;
	DLinkList temp;
	if (!initDLinkList20(temp)) {
		return NULL;
	}
	q = temp;
	while (p->next != NULL) {
		if (p->next->data == x) {
			//���ӷ���Ƶ��
			p->next->freq++;
			//�Ͽ�r����
			r = p->next;
			p->next = r->next;
			//��ֹrΪ��β�����
			if(r->next != NULL)
				r->next->pred = p;

			//��r����ʱ��ͷ�������ʹ�ô�ͷ�������ԭ�򣺱�ͷ����������λ�ò������һ�£�
			//ע��r->next = q->next����©��֤��λ��nextλ��NULL
			r->next = q->next;
			q->next = r;
			r->pred = q;
			//�ƶ���ʱ����ָ������λ
			q = q->next;
		}
		else {
			//�޲�������°�ԭ����ָ��������
			p = p->next;
		}
	}
	//----------�����������ԭ����ֵΪx�Ľڵ㶼�Ͽ���ŵ���ʱ����-------------
	//��ʱqָ����ʱ�����β
	p = l;
	//Ƶ��С�ڵ��ڵ�ǰ����Ƶ��
	while (p->next != NULL && p->next->freq < q->freq) {
		p = p->next;
	}
	//������ʱ��Ƶ��С��q�Ҵ��ڻ����q��Ԫ��֮��
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
	
	cout << "exit��" << endl;
	return 0;
}