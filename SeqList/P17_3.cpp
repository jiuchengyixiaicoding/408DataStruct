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

//初始化顺序表
void InitList05(SeqList& L) {
    L.data = (int*)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.maxSize = InitSize;
}

//删除所有元素为x的数据元素，时间O(n),空间O(1)
void deleteElem(SeqList &l, int e) {
    //用k记录非x元素的个数
    int k = 0;
    for (int i = 0; i < l.length; i++) {
        if (l.data[i] != e) {
            l.data[k++] = l.data[i];
        }
    }
    l.length = k;
}

int main0205()
{
    SeqList l;
    InitList05(l);
    for (int i = 0; i < l.maxSize; i++) {
        l.data[i] = i;
        l.length++;
    }
    deleteElem(l, 5);
    for (int i = 0; i < l.length; i++) {
        printf("%d", l.data[i]);
    }
    return 0;
}