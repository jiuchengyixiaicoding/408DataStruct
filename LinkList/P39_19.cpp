#include <iostream>
#include <cstdlib>

using namespace std;
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

//��ʼ��ѭ��������
bool initLinkList19(LinkList& l) {
	l = (LinkList)malloc(sizeof(LinkList));
	if (l == NULL) {
		return false;
	}
	l->next = l;
	return true;
}

//ѭ�������ɾ���������Сֵ��ֱ������Ϊ��
void printfMinAndFree(LinkList& a) {
	//min��ʾ��Сֵ�ڵ㣬minPre��ʾ��Сֵ�ڵ��ǰһ���ڵ�
	LNode* n = a->next, * p, * min, * minPre = a;

	//n == a��ʾ����Ϊ��
	while (a->next != a) {
		//��p�洢��ʱ����ĵ�һ���ڵ�
		p = a->next;
		//������СֵΪ��һ���ڵ�
		min = p;
		//ѭ���ҳ���������Сֵ����Сֵ��ǰһ���ڵ�
		while (p->next != a) {
			if (min->data > p->next->data) {
				minPre = p;
				min = p->next;
			}
			p = p->next;
		}
		//�ӵ�����Ͽ�min
		minPre->next = min->next;
		
		
		printf("%d", min->data);
		puts("");
		free(min);
		
	}
	
}

int main020219() {
	LinkList a;
	initLinkList19(a);

	LNode* n1 = (LNode*)malloc(sizeof(LNode));
	if (n1 != NULL) {
		n1->data = 5;
		a->next = n1;
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
		n4->next = a;
	}
	printfMinAndFree(a);
	return 0;
}