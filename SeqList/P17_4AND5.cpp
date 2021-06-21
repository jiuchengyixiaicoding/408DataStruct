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
void InitList06(SeqList& L) {
    L.data = (int*)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.maxSize = InitSize;
}

//����˳���ֵ�������У�ɾ��ֵ��s->t���Ԫ�أ�s/t�������˳���Ϊ�մ�ӡ������Ϣ
bool deleteElemInRange(SeqList& l, int s, int t) {
    if (s >= t || l.length == 0) {
        return false;
    }
    //��k��¼��s->tԪ�صĸ���
    int k = 0;
    for (int i = 0; i < l.length; i++) {
        if (l.data[i] < s || l.data[i] > t) {
            l.data[k++] = l.data[i];
        }
    }
    l.length = k;
    return true;
}

int main0206()
{
    SeqList l;
    InitList06(l);
    for (int i = 0; i < l.maxSize; i++) {
        l.data[i] = i;
        l.length++;
    }
    if (!deleteElemInRange(l, 1, 6)) {
        printf("s / tֵ�������˳���Ϊ�մ�!");
    }
    for (int i = 0; i < l.length; i++) {
        printf("%d", l.data[i]);
    }
    return 0;
}