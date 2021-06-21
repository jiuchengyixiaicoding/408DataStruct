#include <cstdlib>
#include <iostream>

using namespace std;

#define InitSize 10

typedef struct {
    //初始化顺序表
    int data[InitSize];
    //顺序表当前长度
    int length;
    //顺序表最大长度
    int maxSize;
} SeqList;

void initList02(SeqList& l) {
    l.length = 0;
    l.maxSize = InitSize;
}

//插入元素到顺序表，index范围为1->length+1（数组当前长度+1）
bool insertList02(SeqList& l, int index, int e) {
    //排除数组已满的情况，已满再插入会溢出
    if (l.length == l.maxSize) {
        return false;
    }
    //排除插入序号不存在的情况
    if (index < 1 || index > l.maxSize) {
        return false;
    }
    //排除按插入序号插入后内存空间不连续的情况 如：123有数值但是插入序号为5，导致4空
    if (index > l.length + 1) {
        return false;
    }

    /** 非法情况都已经排除接下来都为正常插入 */

    //如果插入序号为当前顺序表最后一位的向后一格（length+1） ，直接插入数组长度+1
    if (index == l.length + 1) {
        l.data[index - 1] = e;
        l.length++;
        return true;
    }
    //如果插入序号大于0，①先从后（length即数组的最后一位+1）往前，到插入序号+1（index+1）为止都向后推一格
    for (int i = l.length; i >= index; i--) {
        l.data[i] = l.data[i - 1];
    }
    //②再把插入元素赋值到插入序号位
    l.data[index - 1] = e;
    l.length++;
    return true;
}

//从顺序表删除元素，带回被删除元素的值
bool deleteList02(SeqList& l, int index, int& e) {
    //排除删除序号不存在的情况
    if (index < 1 || index > l.length) {
        return false;
    }
    //顺序表只有一位或删除序号为最后一位直接把顺序表长度-1
    if (l.length == 1 || index == l.length) {
        e = l.data[index - 1];
        l.length--;
        return true;
    }
    //index>1且<length的情况下
    //①先为e赋值
    e = l.data[index - 1];
    //②再从前（index+1）往后 length都往前推一格
    for (int i = index; i < l.length; i++) {
        l.data[i - 1] = l.data[i];
    }
    l.length--;
    return true;
}



int main0202() {
    SeqList sl;
    initList02(sl);
    int e = -1;
    printf("插入结果：%d\t", insertList02(sl, 1, 1));
    deleteList02(sl, 1, e);
    printf("删除的元素为%d\n", e);
    for (int i = 1; i < sl.length; i++) {
        printf("插入结果：%d\t", insertList02(sl, i, i));
    }
    printf("\n");
    //printf("插入结果：%d\t", insertList(sl, 5, 10));
    //printf("\n");
    printf("插入结果：%d\t", insertList02(sl, 10, 10));
    printf("\n");


    if (deleteList02(sl, 1, e)) {
        printf("删除的元素为%d\n", e);
    }
    else {
        printf("删除序号非法\n");
    }

    for (int i = 0; i < sl.length; i++) {
        printf("当前为第%d位，数值为%d\n", i + 1, sl.data[i]);
    }
    return 0;
}
