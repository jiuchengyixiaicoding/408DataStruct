#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct LNode {
	char data;
	struct LNode* next;
}LNode, * LinkStack;

bool init00(LinkStack& s) {
	s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL) {
		return false;
	}
	s->next = NULL;
	return true;
}

bool push00(LinkStack &s, char x) {
	LNode* p = (LNode*)malloc(sizeof(LNode));
	if (p == NULL) {
		return false;
	}
	p->data = x;
	p->next = s->next;
	s->next = p;
	return true;
}

bool pop00(LinkStack &s, char &x) {
	if (s->next == NULL) {
		return false;
	}
	LNode* p = (LNode*)malloc(sizeof(LNode));
	if (p == NULL) {
		return false;
	}
	p = s->next;
	s->next = p->next;
	x = p->data;
	free(p);
	return true;
}

	
bool mateSymbol00(char arr[], int length) {
	LinkStack s;
	init00(s);
	int i = 0;
	char x = 'a';
	while (i < length) {
		if (arr[i] == '{' || arr[i] == '[' || arr[i] == '(') {
			if(!push00(s, arr[i])) return false;
		}
		else {
			pop00(s, x);
			if (arr[i] == ')' && x != '(') {
				return false;
			}
			if (arr[i] == ']' && x != '[') {
				return false;
			}
			if (arr[i] == '}' && x != '{') {
				return false;
			}
		}
		i++;
	}
	//字符串遍历完成，若栈中还有元素则说明有左括号右括号匹配，总体匹配失败 return false
	//反之全部匹配成功，return true
	return s->next == NULL;
}

int main030300() {
	char arr[10] = {'{', '{', '(', ')', '}', '[', '(', ')', ']', '}'};
	printf("%d", mateSymbol00(arr, 10));
	return 0;
}