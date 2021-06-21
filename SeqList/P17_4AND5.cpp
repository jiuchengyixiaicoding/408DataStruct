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
void InitList06(SeqList& L) {
    L.data = (int*)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.maxSize = InitSize;
}

//有序顺序表（值有序排列）删除值在s->t间的元素，s/t不合理或顺序表为空打印错误信息
bool deleteElemInRange(SeqList& l, int s, int t) {
    if (s >= t || l.length == 0) {
        return false;
    }
    //用k记录非s->t元素的个数
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
        printf("s / t值不合理或顺序表为空打!");
    }
    for (int i = 0; i < l.length; i++) {
        printf("%d", l.data[i]);
    }
    return 0;
}