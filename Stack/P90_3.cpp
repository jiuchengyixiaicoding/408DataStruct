#include <iostream>
#include <cstdlib>

using namespace std;

#define MaxSize 100

//用栈模拟递归函数，计算Pn(x) = 1, n = 0, Pn(x) = 2 * x, n = 1, Pn(x) = 2 * x * Pn-1(x) - 2 * (n - 1) * Pn-2(x)
double compute003(int n, double x) {
	//设置一个结构体栈为函数局部变量
	struct Stack {
		//运算结果
		double data;
		//当前运算次数
		int n;
	}stack[MaxSize];
	//分别代表n = 0和n = 1的情况
	double result1 = 1, result2 = 2 * x;
	//栈顶和运算次数
	int top = -1, i = n;
	//模拟递归中栈顶为最后一次执行的函数，栈底为第一次执行的函数
	while (i >= 2) {
		stack[++top].n = i--;
	}

	//第一次执行的是栈顶函数此时n = 2，其中Pn-1(x)的结果为n = 1的情况，Pn-2(x)的结果为n = 0的情况
	//再往后执行则是n = 3，Pn-1(x)的结果为n = 2的情况，Pn-2(x)的结果为n = 1的情况，则把result1 Pn-2(x)的值设为刚才的result2 Pn-1(x)，result2  Pn-1(x)设为本次栈顶函数的执行结果
	//以此类推，知道栈内元素全部弹出，P(x)结果为最后弹出的元素运算值
	while (top >= 0) {
		stack[top].data = 2 * x * result1 - 2 * (double)((double)stack[top].n - 1) * result2;
		result1 = result2;
		result2 = stack[top--].data;
	}
	if (x == 0) {
		return result1;
	}
	//n为1结果为2 * x，大于1则为stack[top--].data
	return result2;
}

int main() {
	printf("%f", compute003(4, 2.0));
}