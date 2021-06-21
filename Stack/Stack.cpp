#include <iostream>
#include <cstdlib>

using namespace std;

#define MaxSize 10

typedef struct SeqStack {
	int data[MaxSize];
	int top;
}SeqStack;

void initSeqStack(SeqStack& s) {
	s.top = -1;
}

bool pushSeqStack(SeqStack &s, int x) {
	if (s.top == MaxSize - 1) {
		return false;
	}
	s.data[++s.top] = x;
	return true;
}

bool popSeqStack(SeqStack& s, int &x) {
	if (s.top == -1) {
		return false;
	}
	x = s.data[s.top--];
	return false;
}

bool getTopSeqStack(SeqStack s, int &x) {
	if (s.top == -1) {
		return false;
	}
	x = s.data[s.top];
	return true;
}

typedef struct LNode {
	int data;
	struct LNode* next;
}LNode;

typedef struct LinkStack {
	LNode* head;
}LinkStack;

bool initLinkStack(LinkStack &s) {
	s.head = (LNode*)malloc(sizeof(LNode));
	if (s.head == NULL) {
		return false;
	}
	s.head->next = NULL;
	return true;
}

bool push(LinkStack &s, int x) {
	LNode* p = (LNode*)malloc(sizeof(LNode));
	if (p == NULL) {
		return false;
	}
	p->data = x;
	p->next = s.head->next;
	s.head->next = p;
	return true;
}

bool pop(LinkStack& s, int &x) {
	if (s.head->next == NULL) {
		return false;
	}
	x = s.head->next->data;
	LNode* p = (LNode*)malloc(sizeof(LNode));
	if (p == NULL) {
		return false;
	}
	p = s.head->next;
	s.head->next = p->next;
	free(p);
	return true;
}