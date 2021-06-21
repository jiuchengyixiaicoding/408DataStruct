#include <cstdlib>
#include <iostream>
using namespace std;
//最大长度
#define InitSize 10
typedef struct {
    int* data;
    int length;
    int maxSize;
} SeqList;

//删除有序顺序表中所有重复元素，使表中所有元素都不同
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