#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct {
    int* data;
    int length;
} SeqList;

//有两个顺序表，长度为m的a:{a1,a2,a3,a4...,am},长度为n的b:{b1,b2,b3,b4...,bn}把这个两个顺序表按a,b顺序存入A[m+n]中
//现要求逆置A中a,b顺序为b,a 即{b1,b2,b3...bn,a1,a2,a3...,am}

//颠倒顺序表
void reverse(SeqList& l, int i, int j) {
    int temp = 0;
    for (i; i < j/2; i++) {
        temp = l.data[i];
        l.data[i] = l.data[j - 1 - i];
        l.data[j - 1 - i] = temp;
    }
}

void exchange(SeqList& l, int m, int n) {
    //先颠倒为(bn,bn-1,...b2,b1,an,an-1,...,a2,a1)
    reverse(l, 0, l.length);
    //颠倒前段b部分
    reverse(l, 0, n);
    //颠倒后段a
    reverse(l, n, m);
}

int main0209() {
    SeqList l;
    int arr[10] = { 0, 1, 2, 3, 4, 100, 99, 98, 97, 96};
    l.data = arr;
    l.length = sizeof(arr) / sizeof(int);
    exchange(l, 5, 5);

    for (int i = 0; i < l.length; i++) {
        printf("%d", l.data[i]);
        puts("");
    }
    return 0;
}