#include<iostream>
#include<cstdlib>

using namespace std;

#define MaxSize 100
#define BlockSize 4

//*******���ﶼ�����������һλ�±��1��ʼ*******
//����
typedef struct SString {
	char ch[MaxSize];
	int length;
}SString;

//�ѷ���洢
typedef struct HString {
	char* ch;
	int length;
}HString;

//�����洢����Ϊ4λchar�����ԭ����32λ�����ֻ��һ���ַ�ֻռһ���ֽڣ���ָ��ռ�ĸ��ֽڣ�
// ����һ��ʵ�ʴ洢�����ݷ�����Խ��٣����������Ϊ�洢�ܶȵͣ����Ǻܺ�
//typedef struct lstring {
//	char block[4];
//	struct lstring* next;
//}lstring;

//���ַ�����ֵ
bool strAssign(SString &t, char chars[], int len) {
	int i = 1;
	while (i <= len) {
		t.ch[i] = chars[i - 1];
		i++;
	}
	t.ch[i] = '\0';
	t.length = len;
	return true;
}

//�ַ�������
bool strCopy(SString t, SString &s) {
	int i = 1;
	while (i <= t.length) {
		s.ch[i] = t.ch[i++];
	}
	s.ch[i] = '\0';
	s.length = t.length;
	return true;
}

//�ַ����п�
bool strEmpty(SString t) {
	return t.length == 0;
}

//�ַ����Ƚϴ�С����1 ��0 С-1
int strCompare(SString t, SString s) {
	int i = 1;
	while (i <= t.length && i <= s.length) {
		if (t.ch[i] != s.ch[i]) {
			return -1;
		}
		i++;
	}
	//ǰ��ȫ��ƥ����Ƚϳ���
	if (t.length < s.length) { 
		return -1; 
	}
	else if (t.length > s.length) {
		return 1;
	}
	else {
		return 0;
	}
}

//�����ַ�������
int strLength(SString t) {
	return t.length;
}

//�����ַ�����pos�𣬽�һ�γ���Ϊlen���Ӵ�
bool strSubSting(SString t, SString &sub, int pos, int len) {
	if (pos + len - 1 > t.length) {
		return false;
	}
	int i = 1;
	while (i <= len) {
		sub.ch[i++] = t.ch[pos++];
	}
	sub.ch[i] = '\0';
	sub.length = len;
	return true;
}

//�ַ����ϲ����ϲ�˳�򰴺�������˳��
SString contact(SString a, SString b) {
	SString t;
	int i = 1;
	while (i <= a.length + b.length) {
		if (i <= a.length) {
			t.ch[i] = a.ch[i];
		}
		else {
			t.ch[i] = b.ch[i - a.length];
		}
		i++;
	}
	t.ch[i] = '\0';
	return t;
}
//�Ӵ��������ַ����ڼ�λ
int index(SString t, SString s) {
	int i = 1, j = 1, n = t.length, m = s.length;
	while (i <= n && j <= m) {
		//ƥ��ʧ���Ӵ���ͷ��ʼ������+1
		if (t.ch[i++] != s.ch[j++]) {
			j = 1;
		}
	}
	//�Ӵ�δƥ�䵽ĩβ�����Ѿ�ѭ������
	if (i == t.length + 1 && j  < s.length + 1) {
		return -1;
	}
	//����δѭ�������Ӵ�ƥ�䵽ĩβ��������ѭ���������Ӵ�ƥ�䵽ĩβ
	return j - 1;
}

int main() {
	SString t;
	SString sub;
	int i = 0;
	while (i < 10) {
		t.ch[i] = i + '0';
		i++;
	}
	t.ch[i] = '\0';
	t.length = 10;
	strSubSting(t, sub, 5, 5);
	i = 0;
	while (sub.ch[i] != '\0') {
		printf("%c", sub.ch[i++]);
	}
	return 0;
}