#include <iostream>
#include <cstdlib>

using namespace std;

#define MaxSize 100

//��ջģ��ݹ麯��������Pn(x) = 1, n = 0, Pn(x) = 2 * x, n = 1, Pn(x) = 2 * x * Pn-1(x) - 2 * (n - 1) * Pn-2(x)
double compute003(int n, double x) {
	//����һ���ṹ��ջΪ�����ֲ�����
	struct Stack {
		//������
		double data;
		//��ǰ�������
		int n;
	}stack[MaxSize];
	//�ֱ����n = 0��n = 1�����
	double result1 = 1, result2 = 2 * x;
	//ջ�����������
	int top = -1, i = n;
	//ģ��ݹ���ջ��Ϊ���һ��ִ�еĺ�����ջ��Ϊ��һ��ִ�еĺ���
	while (i >= 2) {
		stack[++top].n = i--;
	}

	//��һ��ִ�е���ջ��������ʱn = 2������Pn-1(x)�Ľ��Ϊn = 1�������Pn-2(x)�Ľ��Ϊn = 0�����
	//������ִ������n = 3��Pn-1(x)�Ľ��Ϊn = 2�������Pn-2(x)�Ľ��Ϊn = 1����������result1 Pn-2(x)��ֵ��Ϊ�ղŵ�result2 Pn-1(x)��result2  Pn-1(x)��Ϊ����ջ��������ִ�н��
	//�Դ����ƣ�֪��ջ��Ԫ��ȫ��������P(x)���Ϊ��󵯳���Ԫ������ֵ
	while (top >= 0) {
		stack[top].data = 2 * x * result1 - 2 * (double)((double)stack[top].n - 1) * result2;
		result1 = result2;
		result2 = stack[top--].data;
	}
	if (x == 0) {
		return result1;
	}
	//nΪ1���Ϊ2 * x������1��Ϊstack[top--].data
	return result2;
}

int main() {
	printf("%f", compute003(4, 2.0));
}