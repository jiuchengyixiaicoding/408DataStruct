#include <cstdlib>
#include <iostream>

using namespace std;

#define InitSize 10

typedef struct {
    //��ʼ��˳���
    int data[InitSize];
    //˳���ǰ����
    int length;
    //˳�����󳤶�
    int maxSize;
} SeqList;

void initList02(SeqList& l) {
    l.length = 0;
    l.maxSize = InitSize;
}

//����Ԫ�ص�˳���index��ΧΪ1->length+1�����鵱ǰ����+1��
bool insertList02(SeqList& l, int index, int e) {
    //�ų���������������������ٲ�������
    if (l.length == l.maxSize) {
        return false;
    }
    //�ų�������Ų����ڵ����
    if (index < 1 || index > l.maxSize) {
        return false;
    }
    //�ų���������Ų�����ڴ�ռ䲻��������� �磺123����ֵ���ǲ������Ϊ5������4��
    if (index > l.length + 1) {
        return false;
    }

    /** �Ƿ�������Ѿ��ų���������Ϊ�������� */

    //����������Ϊ��ǰ˳������һλ�����һ��length+1�� ��ֱ�Ӳ������鳤��+1
    if (index == l.length + 1) {
        l.data[index - 1] = e;
        l.length++;
        return true;
    }
    //���������Ŵ���0�����ȴӺ�length����������һλ+1����ǰ�����������+1��index+1��Ϊֹ�������һ��
    for (int i = l.length; i >= index; i--) {
        l.data[i] = l.data[i - 1];
    }
    //���ٰѲ���Ԫ�ظ�ֵ���������λ
    l.data[index - 1] = e;
    l.length++;
    return true;
}

//��˳���ɾ��Ԫ�أ����ر�ɾ��Ԫ�ص�ֵ
bool deleteList02(SeqList& l, int index, int& e) {
    //�ų�ɾ����Ų����ڵ����
    if (index < 1 || index > l.length) {
        return false;
    }
    //˳���ֻ��һλ��ɾ�����Ϊ���һλֱ�Ӱ�˳�����-1
    if (l.length == 1 || index == l.length) {
        e = l.data[index - 1];
        l.length--;
        return true;
    }
    //index>1��<length�������
    //����Ϊe��ֵ
    e = l.data[index - 1];
    //���ٴ�ǰ��index+1������ length����ǰ��һ��
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
    printf("��������%d\t", insertList02(sl, 1, 1));
    deleteList02(sl, 1, e);
    printf("ɾ����Ԫ��Ϊ%d\n", e);
    for (int i = 1; i < sl.length; i++) {
        printf("��������%d\t", insertList02(sl, i, i));
    }
    printf("\n");
    //printf("��������%d\t", insertList(sl, 5, 10));
    //printf("\n");
    printf("��������%d\t", insertList02(sl, 10, 10));
    printf("\n");


    if (deleteList02(sl, 1, e)) {
        printf("ɾ����Ԫ��Ϊ%d\n", e);
    }
    else {
        printf("ɾ����ŷǷ�\n");
    }

    for (int i = 0; i < sl.length; i++) {
        printf("��ǰΪ��%dλ����ֵΪ%d\n", i + 1, sl.data[i]);
    }
    return 0;
}
