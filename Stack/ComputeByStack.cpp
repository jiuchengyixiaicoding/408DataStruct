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
		//��������ѹ��ջ
		if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/') {
			push001(s, str[i]);
		}
		//�������ȡ������ջ��Ԫ��������
		else {
			//��׺���ʽ�����Ϊ��ʽ�������������ӡ����������ˡ���������Ҫע�⣡
			pop001(s, p);
			x = p - '0';
			//���ƥ�䵽�����������ջ��ֻ��һ��Ԫ�أ�����false
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
	//���ջ�ڲ�ֹ����һ������˵��������ַ����������֣�����false
	if (s->next->next != NULL) {
		return false;
	}
	pop001(s, z);
	free(s);
	return true;
}

//��׺���ʽת��׺���ʽ
char* midToSuffix(char str[], int len) {
	//����һ��ջ��������
	LinkStack s;
	init001(s);
	//�ֱ�Ϊԭ�ַ�������ʱ�ַ���������
	int i = 0, j = 0;
	//����һ����ʽ�ڲ�����ֵ�ֵ
	char q = '!';
	char* temp = (char*)malloc(len * sizeof(char));
	if (temp == NULL) {
		return NULL;
	}
	while (str[i] != '\0') {
		//����ֱ�ӽ�����ʱ�ַ���
		if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/' && str[i] != '(' && str[i] != ')') {
			temp[j++] = str[i];
		}
		//�ٷ����ְ�ջ��ͬ����ͼ��������ջԭ��
		//��������ֱ����ջ
		//��������ѭ��ִ�г�ջ����ֱ��ƥ�䵽��
		//�����ۼӼ��˳�������ǰ�ַ�����һλΪ����Ҫִ�г�ջ������ֱ����ջ
		else {
			if (str[i] == '+' || str[i] == '-') {
				//��ֹ��һλ��(�����
				if (str[i + 1] == '\0' || str[i + 1] != '(') {
					//s->next != NULL��ֹ����ջ��ʱ��ȡs->next->data�Ŀ�ָ�����
					while (s->next != NULL && (s->next->data == '+' || s->next->data == '-')) {
						pop001(s, q);
						temp[j++] = q;
					}
				}
				push001(s, str[i]);
			}
			else if (str[i] == '*' || str[i] == '/') {
				//��ֹ��һλ��(�����
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
			//')'�����
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
	
	//������һ����ջ�Ĳ���),ջ������һλ��Ҫ���
	if (s->next != NULL) {
		pop001(s, q);
		temp[j++] = q;
	}

	//temp����ֻ��С�ڵ���str��С��ʱ����λ��0��Ҫ�ֶ�\0��β
	temp[j] = '\0';
	free(s);
	return temp;
}

int main() {
	//Ԥ��һλ��\0
	char str[12] = "8+8*(2-1)/2"; 
	char* q = (char*)midToSuffix(str, 12);
	printf("%s\n", q);
	char z = '!';
	computeByStack(q, z);
	printf("%c", z);
	return 0;
}