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
void InitList01(SeqList& L) {
    L.data = (int*)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.maxSize = InitSize;
}

//增加顺序表长度

void IncreaseList01(SeqList& L, int len) {
    int* p = L.data;
    L.data = (int*)malloc((L.maxSize + len) * sizeof(int));
    for (int j = 0; j < L.length; j++) {
        L.data[j] = p[j];
    }
    L.maxSize += len;
    free(p);
}


int main0201()
{   
    SeqList L;
    InitList01(L);
    for (int i = 0; i < L.maxSize; i++) {
        L.data[i] = i;
        L.length++;
    }

    IncreaseList01(L, 5);
    for (int i = 0; i < L.length; i++) {
        printf("%d", L.data[i]);
    }
    return 0;
}
