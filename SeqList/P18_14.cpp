#include <cstdlib>
#include <iostream>

using namespace std;

//时间复杂度O(3n^2) 空间复杂度 O(1)
int diameter(int arr1[], int arr2[], int n1, int n2) {
	int i = 0;
	int j;
	int temp;
	int diameter = (arr1[0] - arr2[0] >= 0 ? arr1[0] - arr2[0] : arr2[0] - arr1[0]);
	while (i < n1) {
		j = 0;
		while (j < n2)
		{
			if (diameter > (temp = (arr1[i] - arr2[j] > 0 ? arr1[i] - arr2[j] : arr2[j] - arr1[i]))) {
				diameter = temp;
			}
			j++;
		}
		i++;
	}
	return diameter;
}

int countDiameter(int arr1[], int arr2[], int arr3[], int n1, int n2, int n3) {
	return diameter(arr1, arr2, n1, n2) + diameter(arr2, arr3, n2, n3) + diameter(arr3, arr1, n3, n1);
}

//参考答案

//定义一个足够大的DMin
#define INT_MAX 0x7fffffff

//返回绝对值
int absoluteValue(int a) {
	if (a > 0)
		return a;
	else
		return -a;
}
//确定a为三个数里最小
bool checkMin(int a, int b, int c) {
	if (a <= b && a <= c)
		return true;
	else
		return false;
}

int findMinDiameter(int arr1[], int arr2[], int arr3[], int n1, int n2, int n3) {
	int i = 0, j = 0, k = 0, dMin = INT_MAX, d;
	while (i < n1 && j < n2 && k < n3 && dMin > 0) {
		d = absoluteValue(arr1[i] - arr2[j]) + absoluteValue(arr2[j] - arr3[k]) + absoluteValue(arr3[k] - arr1[i]);
		if (dMin > d) dMin = d;
		if (checkMin(arr1[i], arr2[j], arr3[k]))
			i++;
		else if (checkMin(arr2[j], arr1[i], arr3[k]))
			j++;
		else
			k++;
	}
	return dMin;
}

int main0214 () {
	int arr1[] = {-1, 0, 9};
	int arr2[] = {-25, -10, 10, 11};
	int arr3[] = {2, 9, 17, 30, 41};
	int diameter = countDiameter(arr1, arr2, arr3, sizeof(arr1) / sizeof(int), sizeof(arr2) / sizeof(int), sizeof(arr3) / sizeof(int));
	printf("%d", diameter);
	puts("");
	diameter = findMinDiameter(arr1, arr2, arr3, sizeof(arr1) / sizeof(int), sizeof(arr2) / sizeof(int), sizeof(arr3) / sizeof(int));
	printf("%d", diameter);
}