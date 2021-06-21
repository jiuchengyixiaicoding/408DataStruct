#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode, * LinkList;

//初始化单链表
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

//找出两个单链表的公共（共有）节点即：l1有x个元素l2有y个元素，但他们有一部分元素设z个是共用的（像个拉到一半尾部对齐首部没对齐的拉链）
//因为单链表只有一个后继节点，从第一个公共节点开始到结尾的所有节点只可以都是公共节点。所以两个链表可以想象成Y型，而不可能是X型
//思想：两个链表长度不一定相等，先把长的那一个链表移动到和短的那个等长位置，再开始找相同元素
LinkList findInterSection(LinkList& l1, LinkList& l2) {
	//获取两个链表的长度
	int len1 = length(l1), len2 = length(l2);
	//获取两个链表的长度差
	int k;
	//设置长短链表
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

	//把长的那一个链表移动到和短的那个等长位置，再开始找相同元素
	while (k--) {
		p = p->next;
	}
	//p与q完全相等（值和下一个节点的指针）或为空时破开循环
	while (p != NULL && p != q) {
		p = p->next;
		q = q->next;
	}
	//p返回NULL两个链表没有公共节点，不为空则返回公共节点可能一个元素可能是一个链表
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