#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct {
    int* data;
    int length;
} SeqList;

//һ���������˳�������ʱ������ڱ���Ѱ�ҵ�xԪ�أ�����xԪ�������һλԪ�ػ��������Ҳ��������x������ʹ˳������������
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
    //��xԪ�������һλԪ�ػ�������������Ϊ˳������һλ��û�к��Ԫ�ص����
    if (l.data[mid] == x && mid < last) {
        int t = l.data[mid];
        l.data[mid] = l.data[mid + 1];
        l.data[mid + 1] = t;
    }
    //����ѭ��ִ�к�last��first���������lastС��mid��first����mid���ʶ�midӦ����last + 1����firstλ(��ԭfirstλ�Ѿ�ѭ������ƶ�һλ)���룬˳�����ܱ����������
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