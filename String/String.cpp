#include<iostream>
#include<cstdlib>

using namespace std;

#define MaxSize 100
#define BlockSize 4

//*******这里都是舍弃数组第一位下标从1开始*******
//定长
typedef struct SString {
	char ch[MaxSize];
	int length;
}SString;

//堆分配存储
typedef struct HString {
	char* ch;
	int length;
}HString;

//块链存储：设为4位char数组的原因是32位情况下只存一个字符只占一个字节，而指针占四个字节，
// 这样一来实际存储的内容反而相对较少，这种情况称为存储密度低，不是很好
//typedef struct lstring {
//	char block[4];
//	struct lstring* next;
//}lstring;

//给字符串赋值
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

//字符串拷贝
bool strCopy(SString t, SString &s) {
	int i = 1;
	while (i <= t.length) {
		s.ch[i] = t.ch[i++];
	}
	s.ch[i] = '\0';
	s.length = t.length;
	return true;
}

//字符串判空
bool strEmpty(SString t) {
	return t.length == 0;
}

//字符串比较大小，大1 等0 小-1
int strCompare(SString t, SString s) {
	int i = 1;
	while (i <= t.length && i <= s.length) {
		if (t.ch[i] != s.ch[i]) {
			return -1;
		}
		i++;
	}
	//前面全部匹配则比较长度
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

//返回字符串长度
int strLength(SString t) {
	return t.length;
}

//返回字符串从pos起，截一段长度为len的子串
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

//字符串合并（合并顺序按函数参数顺序）
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
//子串出现在字符串第几位
int index(SString t, SString s) {
	int i = 1, j = 1, n = t.length, m = s.length;
	while (i <= n && j <= m) {
		//匹配失败子串重头开始，主串+1
		if (t.ch[i++] != s.ch[j++]) {
			j = 1;
		}
	}
	//子串未匹配到末尾主串已经循环结束
	if (i == t.length + 1 && j  < s.length + 1) {
		return -1;
	}
	//主串未循环结束子串匹配到末尾，或主串循环结束且子串匹配到末尾
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