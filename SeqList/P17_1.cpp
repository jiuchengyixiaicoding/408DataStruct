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

void initList03(SeqList& l) {
    l.length = 0;
    l.maxSize = InitSize;
}

//����Ԫ�ص�˳���index��ΧΪ1->length+1�����鵱ǰ����+1��
bool insertList03(SeqList& l, int index, int e) {
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

//ɾ��������Сֵ�����һλ���ȱ����������Сֵ
bool deleteMinFromList03(SeqList& l, int& e) {
    if (l.length == 0) {
        return false;
    }
    e = l.data[0];
    int index = 0;
    for (int i = 1; i < l.length; i++) {
        if (e > l.data[i]) {
            e = l.data[i];
            index = i;
        }
    }
    l.data[index] = l.data[l.length - 1];
    l.length--;
    return true;

}

int main0203() {
    SeqList sl;
    initList03(sl);
    int e = -1;
    for (int i = 1; i < sl.maxSize; i++) {
        printf("��������%d\t", insertList03(sl, i, i));
        puts("");
    }

    if (deleteMinFromList03(sl, e)) {
        printf("ɾ����Ԫ��Ϊ%d\n", e);
    }
    else {
        printf("˳���Ϊ��\n");
    }

    for (int i = 0; i < sl.length; i++) {
        printf("��ǰΪ��%dλ����ֵΪ%d\n", i + 1, sl.data[i]);
    }
    return 0;
}
