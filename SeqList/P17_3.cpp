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
void InitList05(SeqList& L) {
    L.data = (int*)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.maxSize = InitSize;
}

//ɾ������Ԫ��Ϊx������Ԫ�أ�ʱ��O(n),�ռ�O(1)
void deleteElem(SeqList &l, int e) {
    //��k��¼��xԪ�صĸ���
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