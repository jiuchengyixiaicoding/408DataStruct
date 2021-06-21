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

//ɾ������˳����������ظ�Ԫ�أ�ʹ��������Ԫ�ض���ͬ
bool deleteRecurrenceElem(SeqList &l) {
    if (l.length == 0) {
        return false;
    }
    int k = 0;
    for (int i = 1; i < l.length; i++) {
        if (l.data[k] != l.data[i]) {
            l.data[++k] = l.data[i];
        }
    }
    l.length = k + 1;
    return true;
}

int main0207() {
    SeqList l;
    int arr[10] = {0, 0, 0, 1, 1, 2, 2, 3, 3, 4};
    l.data = arr;
    l.length = 10;

    deleteRecurrenceElem(l);

    for (int i = 0; i < l.length; i++) {
        printf("%d", l.data[i]);
    }
    return 0;
}