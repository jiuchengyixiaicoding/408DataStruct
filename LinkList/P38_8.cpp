#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

//��ʼ��������
bool initLinkList08(LinkList& l) {
	l = (LNode*)malloc(sizeof(LNode));
	if (l == NULL) {
		return false;
	}
	l->next = NULL;
	return true;
}

int length(LinkList& l) {
	int len = 0;
	LNode* n = l->next;
	while (n != NULL) {
		n = n->next;
		len++;
	}
	return len;
}

//�ҳ�����������Ĺ��������У��ڵ㼴��l1��x��Ԫ��l2��y��Ԫ�أ���������һ����Ԫ����z���ǹ��õģ��������һ��β�������ײ�û�����������
//��Ϊ������ֻ��һ����̽ڵ㣬�ӵ�һ�������ڵ㿪ʼ����β�����нڵ�ֻ���Զ��ǹ����ڵ㡣��������������������Y�ͣ�����������X��
//˼�룺���������Ȳ�һ����ȣ��Ȱѳ�����һ�������ƶ����Ͷ̵��Ǹ��ȳ�λ�ã��ٿ�ʼ����ͬԪ��
LinkList findInterSection(LinkList& l1, LinkList& l2) {
	//��ȡ��������ĳ���
	int len1 = length(l1), len2 = length(l2);
	//��ȡ��������ĳ��Ȳ�
	int k;
	//���ó�������
	LinkList longList, shortList;
	if (len1 > len2) {
		longList = l1;
		shortList = l2;
		k = len1 - len2;
	}
	else {
		longList = l2;
		shortList = l1;
		k = len2 - len1;
	}
	LNode* p = longList->next, * q = shortList->next;

	//�ѳ�����һ�������ƶ����Ͷ̵��Ǹ��ȳ�λ�ã��ٿ�ʼ����ͬԪ��
	while (k--) {
		p = p->next;
	}
	//p��q��ȫ��ȣ�ֵ����һ���ڵ��ָ�룩��Ϊ��ʱ�ƿ�ѭ��
	while (p != NULL && p != q) {
		p = p->next;
		q = q->next;
	}
	//p����NULL��������û�й����ڵ㣬��Ϊ���򷵻ع����ڵ����һ��Ԫ�ؿ�����һ������
	return p;
}

int main020208() {

	LinkList l1;
	initLinkList08(l1);

	LinkList l2;
	initLinkList08(l2);

	LNode* n0 = (LNode*)malloc(sizeof(LNode));
	if (n0 != NULL) {
		n0->data = 0;
	}
	LNode* n1 = (LNode*)malloc(sizeof(LNode));
	if (n0 != NULL && n1 != NULL) {
		n1->data = 1;
		n0->next = n1;
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

	l1->next = n1;
	l2->next = n0;
	

	LNode* p = findInterSection(l1, l2);

	while (p != NULL) {
		printf("%d", p->data);
		puts("");
		p = p->next;
	}
	return 0;
}