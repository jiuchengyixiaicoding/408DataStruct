#include <cstdlib>
#include <iostream>
using namespace std;
//��󳤶�
#define InitSize 10
typedef struct {
    int* data;
    int length;
    int maxSize;
} SeqList;

//��ʼ��˳���
void InitList04(SeqList& L) {
    L.data = (int*)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.maxSize = InitSize;
}

//����˳����ؼ����Ӷ�O��1��
void reverseSql(SeqList& l) {
    int i = 0;
    int temp = 0;
    int j = 0;
    for (i; i < l.length/2; i++) {
        temp = l.data[i];
        j = l.length - i - 1;
        l.data[i] = l.data[j];
        l.data[j] = temp;
    }
}

int main0204()
{
    SeqList l;
    InitList04(l);
    for (int i = 0; i < l.maxSize; i++) {
        l.data[i] = i;
        l.length++;
    }
    reverseSql(l);
    for (int i = 0; i < l.length; i++) {
        printf("%d", l.data[i]);
    }
    return 0;
}