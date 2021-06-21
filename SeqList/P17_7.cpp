#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct {
    int* data;
    int length;
} SeqList;

//合并两个有序顺序表为一个新的有序顺序表
SeqList mergeOrderSeqList (SeqList& l1, SeqList& l2) {
    SeqList l;
    l.length = 0;
    if (l1.length == 0 && l2.length == 0)
    {
        return l;
    }
    else if (l1.length == 0 && l2.length > 0)
    {
        return l2;
    }
    else if (l1.length > 0 && l2.length == 0)
    {
        return l1;
    }
    int* a;
    if((a = (int*)malloc((l1.length + l2.length) * sizeof(int))) != NULL)
    l.data = a;

    //记录合并后顺序表指针位置
    int k = 0;
    //记录l1已经被合并了几位
    int p = 0;
    //记录l2已经被合并了几位
    int q = 0;
    for (int i = 0; i < (l1.length + l2.length); i++)
    {
        if (p < l1.length && q < l2.length)
        {
            if (l1.data[p] <= l2.data[q])
            {
                if (l1.data[p] < l2.data[q]) {
                    l.data[k++] = l1.data[p++];
                }
                else
                {
                    l.data[k++] = l1.data[p++];
                    l.data[k++] = l2.data[q++];
                }
            }
            else
            {
                l.data[k++] = l2.data[q++];
            }
        }
        else 
        {
            if (p == l1.length && q < l2.length) 
            {
                l.data[k++] = l2.data[q++];
            }
            else if (p < l1.length && q == l2.length) 
            {
                l.data[k++] = l1.data[p++];
            }
        }
    }
    l.length = k;
    return l;
}

int main0208() {
    SeqList l1;
    SeqList l2;
    int arr1[10] = { 0, 0, 0, 1, 1, 2, 2, 3, 3, 4 };
    int arr2[10] = { 1, 1, 3, 3, 4, 5, 5, 8, 8, 9 };
    l1.data = arr1;
    l1.length = sizeof(arr1)/sizeof(int);
    l2.data = arr2;
    l2.length = sizeof(arr2) / sizeof(int);
    SeqList l = mergeOrderSeqList(l1, l2);

    for (int i = 0; i < l.length; i++) {
        printf("%d", l.data[i]);
    }
    return 0;
}