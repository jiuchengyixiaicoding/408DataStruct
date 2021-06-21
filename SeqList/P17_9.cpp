#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct {
    int* data;
    int length;
} SeqList;

//一个有序递增顺序表，最少时间完成在表中寻找到x元素，并把x元素与其后一位元素互换，若找不到则插入x到表中使顺序表保持有序递增
void exchangeOrInsert(SeqList& l, int x) {
    int first = 0;
    int last = l.length - 1;
    int mid = -1;

    while (first <= last) {
        mid = (first + last) / 2;
        if (l.data[mid] == x) {
            break;
        }
        else if(l.data[mid] < x) {
            first = mid + 1;
        }
        else {
            last = mid - 1;
        }
    }
    //把x元素与其后一位元素互换，过滤索引为顺序表最后一位，没有后继元素的情况
    if (l.data[mid] == x && mid < last) {
        int t = l.data[mid];
        l.data[mid] = l.data[mid + 1];
        l.data[mid + 1] = t;
    }
    //上述循环执行后last与first交错而过，last小于mid，first大于mid，故而mid应该在last + 1或者first位(因原first位已经循环向后移动一位)插入，顺序表才能保持有序递增
    if (l.data[mid] != x) {
        for (int i = l.length - 1; i > last; i--) {
            l.data[i + 1] = l.data[i];
        }
        l.data[last + 1] = x;
        l.length++;
    }
    
}



int main0210() {
    SeqList l;
    int arr[10] = { 1, 2, 3, 4, 6, 7, 8, 9, 10 };
    l.data = arr;
    l.length = 9;
    exchangeOrInsert(l, 5);
    for (int i = 0; i < l.length; i++) {
        printf("%d", l.data[i]);
        puts("");
    }
    return 0;
}