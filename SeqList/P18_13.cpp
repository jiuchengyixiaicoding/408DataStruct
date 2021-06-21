#include <cstdlib>
#include <iostream>
using namespace std;

//找出含n个整数数组中未出现的最小正整数，如{-5,3,2,3}是1  {1,2,3}是4
//本算法思想为设一个k为1在数组中寻找是否有相匹配的值，若有则把k加1，如此推进可保证k得到最终值是数组中缺少的最小正整数。
//时间复杂度O(n) 空间复杂度O(1)
//因为没规定顺序数组，若规定顺序数组可以用开头结尾与中间指针把算法改良成O(log2n)
int findMinPositiveInteger(int arr[], int n) {
	//数组指针
	int i = 0;
	//设k为从1到n + 1的正整数
	int k = 1;
	//最坏情况arr数组里是连续的从1开始的升序序列，数组循环n遍，n遍后k等于n+1才符合条件，注意k++与++k的区别
	
	while (i < n)
	{
		if (/*arr[i] > 0 && */k == arr[i]) {
			k++;
		}
		i++;
	}
	
	return k;
}

int main0213() {
	//int arr[] = { -5, 3, 2, 3 };
	int arr[] = { 1, 2, 3, 4 };
	int n = sizeof(arr) / sizeof(int);
	printf("%d", findMinPositiveInteger(arr, n));
	
	return 0;
}