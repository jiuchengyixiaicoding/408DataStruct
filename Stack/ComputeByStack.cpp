#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct LNode {
	char data;
	struct LNode* next;
}LNode, *LinkStack;

bool init001(LinkStack& s) {
	s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL) {
		return false;
	}
	s->next = NULL;
	return true;
}

bool push001(LinkStack& s, char x) {
	LNode* p = (LNode*)malloc(sizeof(LNode));
	if (p == NULL) {
		return false;
	}
	p->data = x;
	p->next = s->next;
	s->next = p;
	return true;
}

bool pop001(LinkStack& s, char& x) {
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

bool computeByStack(char str[], char &z) {
	int i = 0, x, y;
	char p, q;
	LinkStack s;
	init001(s);
	while (str[i] != '\0') {
		//是数字则压入栈
		if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/') {
			push001(s, str[i]);
		}
		//运算符则取出两个栈顶元素做运算
		else {
			//后缀表达式：后出为算式被操作数，被加、被减、被乘、被除，需要注意！
			pop001(s, p);
			x = p - '0';
			//如果匹配到运算符，但是栈里只有一个元素，返回false
			if (!pop001(s, q)) {
				return false;
			}
			y = q - '0';
			if (str[i] == '+') {
				y = y + x;
			}
			else if (str[i] == '-') {
				y = y - x;
			}
			else if (str[i] == '*') {
				y = y * x;
			}
			else {
				y = y / x;
			}
			push001(s, y + '0');
		}
		i++;
	}
	//如果栈内不止存在一个数，说明输入的字符串多了数字，返回false
	if (s->next->next != NULL) {
		return false;
	}
	pop001(s, z);
	free(s);
	return true;
}

//中缀表达式转后缀表达式
char* midToSuffix(char str[], int len) {
	//开辟一个栈存放运算符
	LinkStack s;
	init001(s);
	//分别为原字符串和临时字符串的索引
	int i = 0, j = 0;
	//设置一个算式内不会出现的值
	char q = '!';
	char* temp = (char*)malloc(len * sizeof(char));
	if (temp == NULL) {
		return NULL;
	}
	while (str[i] != '\0') {
		//数字直接进入临时字符串
		if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str[i] != '(' && str[i] != ')') {
			temp[j++] = str[i];
		}
		//①非数字按栈内同级或低级运算符出栈原则
		//②遇到（直接入栈
		//③遇到）循环执行出栈操作直到匹配到（
		//④无论加减乘除，若当前字符往后一位为（则不要执行出栈操作，直接入栈
		else {
			if (str[i] == '+' || str[i] == '-') {
				//防止下一位是(的情况
				if (str[i + 1] == '\0' || str[i + 1] != '(') {
					//s->next != NULL防止出现栈空时获取s->next->data的空指针错误
					while (s->next != NULL && (s->next->data == '+' || s->next->data == '-')) {
						pop001(s, q);
						temp[j++] = q;
					}
				}
				push001(s, str[i]);
			}
			else if (str[i] == '*' || str[i] == '/') {
				//防止下一位是(的情况
				if (str[i + 1] == '\0' || str[i + 1] != '(') {
					while (s->next != NULL && (s->next->data == '+' || s->next->data == '-' || s->next->data == '*' || s->next->data == '/')) {
						pop001(s, q);
						temp[j++] = q;
					}
				}
				push001(s, str[i]);
			}
			else if (s->next != NULL && str[i] == '(') {
				push001(s, str[i]);
			}
			//')'的情况
			else {
				while (s->next != NULL && s->next->data != '(') {
					pop001(s, q);
					temp[j++] = q;
				}
				pop001(s, q);
			}
		}
		i++;
	}
	
	//如果最后一个入栈的不是),栈里则还有一位需要输出
	if (s->next != NULL) {
		pop001(s, q);
		temp[j++] = q;
	}

	//temp长度只会小于等于str，小于时后续位是0需要手动\0结尾
	temp[j] = '\0';
	free(s);
	return temp;
}

int main() {
	//预留一位给\0
	char str[12] = "8+8*(2-1)/2"; 
	char* q = (char*)midToSuffix(str, 12);
	printf("%s\n", q);
	char z = '!';
	computeByStack(q, z);
	printf("%c", z);
	return 0;
}