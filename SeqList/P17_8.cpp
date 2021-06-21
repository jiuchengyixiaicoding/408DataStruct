#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct {
    int* data;
    int length;
} SeqList;

//������˳�������Ϊm��a:{a1,a2,a3,a4...,am},����Ϊn��b:{b1,b2,b3,b4...,bn}���������˳���a,b˳�����A[m+n]��
//��Ҫ������A��a,b˳��Ϊb,a ��{b1,b2,b3...bn,a1,a2,a3...,am}

//�ߵ�˳���
void reverse(SeqList& l, int i, int j) {
    int temp = 0;
    for (i; i < j/2; i++) {
        temp = l.data[i];
        l.data[i] = l.data[j - 1 - i];
        l.data[j - 1 - i] = temp;
    }
}

void exchange(SeqList& l, int m, int n) {
    //�ȵߵ�Ϊ(bn,bn-1,...b2,b1,an,an-1,...,a2,a1)
    reverse(l, 0, l.length);
    //�ߵ�ǰ��b����
    reverse(l, 0, n);
    //�ߵ����a
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