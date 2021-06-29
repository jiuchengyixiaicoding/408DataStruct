#include <iostream>
#include <cstdlib>

using namespace std;

#define MaxSize 100

typedef struct String {
	char ch[MaxSize];
	int length;
}String;

// bվhttps://www.bilibili.com/video/BV16X4y137qw����next����Ĵ�����ͽ��ķǳ���
void getNext(String s, int next[]) {
	int i = 1, j = 0;
	//Ϊ�˺���ȡֵ����next�����±����ַ���һ��������һλ0
	next[i] = 0;
	// next�����һλ�����ֵ���Ϊǰһλ+1
	while (i <= s.length) {
		// i + 1���ǵ�ǰ������λ�ã��㷨�ǱȽ�s.ch[i]��s.ch[k]
		// k = next[i]�������ƥ�� k = next[next[i]]���㷨�е�k����j
		// ƥ�䲻��k = next[next[next[i]]]���һֱ�Ƚ�
		// ������ƥ�䣬������j = 0
		// j = 0Ϊnext[1]��next�����±����1ʱ����next[k]ƥ�䲻�ϵ�����
		if (j == 0 || s.ch[i] == s.ch[j]) {
			next[++i] = ++j;
		}
		else {
			j = next[j];
		}
	}
}

//kmp���Ż�����ֹnext[i]Ϊ��ͬ��ĸ�ظ��Ƚ�
void getNextval(String s, int nextval[]) {
	int i = 1, j = 0;
	nextval[i] = 0;
	//���ಽ��һ�£��������ַ�����ǰλ��s.ch[i + 1]��s.ch[k]�ıȽϣ�k = next[i + 1]�ıȽϣ��㷨�е�k����j��
	while (i <= s.length) {
		if (j == 0 || s.ch[i] == s.ch[j]) {
			if (s.ch[++i] != s.ch[++j]) {
				nextval[i] = j;
			}
			else {
				nextval[i] = nextval[j];
			}
			
		}
		else {
			j = nextval[j];
		}
	}
}

//��ȡ�Ӵ��������е�һ�γ��ֵ�λ�ã�û���ҵ��򷵻�-1
int indexByKMP(String t, String s, int next[]) {
	//��ȡ�Ӵ�next����
	getNext(s, next);
	int i = 1, j = 1;

	while (i <= t.length && j <= s.length) {
		//next���鷵�ص��Ӵ��±�Ϊ0���ַ���ƥ��ɹ�����£��±��������ơ������ƶ��Ӵ��±굽next[j]
		if (j == 0 || t.ch[i] == t.ch[j]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}
	//j�����Ӵ���ʾ�Ӵ�������ĳ����ȫ��ƥ�䣬����ƥ��ʧ��
	if (j > s.length) {
		return i - s.length;
	}
	return -1;
}