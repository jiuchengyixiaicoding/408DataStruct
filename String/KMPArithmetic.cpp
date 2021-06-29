#include <iostream>
#include <cstdlib>

using namespace std;

#define MaxSize 100

typedef struct String {
	char ch[MaxSize];
	int length;
}String;

// b站https://www.bilibili.com/video/BV16X4y137qw对求next数组的代码解释讲的非常好
void getNext(String s, int next[]) {
	int i = 1, j = 0;
	//为了后面取值方便next数组下标与字符串一样舍弃第一位0
	next[i] = 0;
	// next数组后一位储存的值最多为前一位+1
	while (i <= s.length) {
		// i + 1才是当前主串的位置，算法是比较s.ch[i]与s.ch[k]
		// k = next[i]，如果不匹配 k = next[next[i]]，算法中的k就是j
		// 匹配不上k = next[next[next[i]]]如此一直比较
		// 若都不匹配，有最坏情况j = 0
		// j = 0为next[1]和next数组下标大于1时所有next[k]匹配不上的最坏情况
		if (j == 0 || s.ch[i] == s.ch[j]) {
			next[++i] = ++j;
		}
		else {
			j = next[j];
		}
	}
}

//kmp的优化，防止next[i]为相同字母重复比较
void getNextval(String s, int nextval[]) {
	int i = 1, j = 0;
	nextval[i] = 0;
	//其余步骤一致，但多了字符串当前位置s.ch[i + 1]与s.ch[k]的比较（k = next[i + 1]的比较，算法中的k就是j）
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

//获取子串在主串中第一次出现的位置，没有找到则返回-1
int indexByKMP(String t, String s, int next[]) {
	//获取子串next数组
	getNext(s, next);
	int i = 1, j = 1;

	while (i <= t.length && j <= s.length) {
		//next数组返回的子串下标为0或字符串匹配成功情况下，下标正常后移。否则移动子串下标到next[j]
		if (j == 0 || t.ch[i] == t.ch[j]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}
	//j大于子串表示子串与主串某部分全部匹配，否则匹配失败
	if (j > s.length) {
		return i - s.length;
	}
	return -1;
}