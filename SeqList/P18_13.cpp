#include <cstdlib>
#include <iostream>
using namespace std;

//�ҳ���n������������δ���ֵ���С����������{-5,3,2,3}��1  {1,2,3}��4
//���㷨˼��Ϊ��һ��kΪ1��������Ѱ���Ƿ�����ƥ���ֵ���������k��1������ƽ��ɱ�֤k�õ�����ֵ��������ȱ�ٵ���С��������
//ʱ�临�Ӷ�O(n) �ռ临�Ӷ�O(1)
//��Ϊû�涨˳�����飬���涨˳����������ÿ�ͷ��β���м�ָ����㷨������O(log2n)
int findMinPositiveInteger(int arr[], int n) {
	//����ָ��
	int i = 0;
	//��kΪ��1��n + 1��������
	int k = 1;
	//����arr�������������Ĵ�1��ʼ���������У�����ѭ��n�飬n���k����n+1�ŷ���������ע��k++��++k������
	
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