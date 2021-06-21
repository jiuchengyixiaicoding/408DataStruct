#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct {
    int* data;
    int length;
} SeqList;

//i=0 j=0 k=0 mn=5 i+j=0 j++  l1.v=11 l2.v=2
//i=0 j=1 k=1 ...  i+j=1 j++  l1.v=11 l2.v=4
//i=0 j=2 k=2 ...  i+j=2 j++  l1.v=11 l2.v=6
//i=0 j=3 k=3 ...  i+j=3 j++  l1.v=11 l2.v=8
//i=0 j=4 k=4 ...  i+j=4 i++  l1.v=11 l2.v=20
//i=1 j=4 k=5==mn stop
//�������ȳ�����˳���A��B��Ѱ����λ�� ʱ�临�Ӷ�o(2n) �ռ����Ӷ�o(n)
void findMedian(SeqList l1, SeqList l2, int &e) {
    //��־l1��ָ��λ��
    int i = 0;
    //��־l2��ָ��λ��
    int j = 0;
    //��λ��Ϊ˳���ڼ�λ
    int midNum = (l1.length + l2.length)/2;
    //i+j��־ģ��A��B�ϲ���ǰָ��λ
    while ((i < l1.length || j < l2.length) && (i+j) < midNum) {
        if (i < l1.length && j < l2.length) {
            if (l1.data[i] < l2.data[j]) {
                e = l1.data[i++];
            }
            else {
                e = l1.data[j++];
            }
        }
        if (i < l1.length && j == l2.length) {
            e = l1.data[i++];
        }
        if (i == l1.length && j < l2.length) {
            e = l1.data[j++];
        }
    }
}

//�ο���
//Ϊʲô��n������sizeof(arr1)/sizeof(int)����Ϊ���κ�arr1ֻ��ʾ�������λ����arr[0]��ʱ��õ���n��Զ��1
int Search_M(int arr1[], int arr2[], int n) {
    //��������һ����β��������ֵ����
    int start1 = 0;
    int end1 = n - 1;
    int mid1;
    //�������������β��������ֵ����
    int start2 = 0;
    int end2 = n - 1;
    int mid2;
    while (start1 != end1 || start2 != end2) {
        mid1 = (start1 + end1) / 2;
        mid2 = (start2 + end2) / 2;
        //����������λ����ȣ����ùܱ������������Ǻϲ��������λ��
        if (arr1[mid1] == arr2[mid2]) {
            return arr1[mid1];
        }
        //�������һ��λ��С�����������������һǰ�벿�֣������������벿��
        if (arr1[mid1] < arr2[mid2]) {
            //�������һ����������
            if ((start1 + end1 + 1) % 2 != 0) {
                start1 = mid1;
            }
            else {
                start1 = mid1 + 1;
            }
            end2 = mid2;
        }
        else {
            //������������������
            if ((start2 + end2 + 1) % 2 != 0) {
                start2 = mid2;
            }
            else {
                start2 = mid2 + 1;
            }
            end1 = mid1;
        }
    }
    //start == end���Է���start����end����
    return arr1[start1] < arr2[start2] ? arr1[start1] : arr2[start2];
}
int main0211() {
    SeqList l1;
    SeqList l2;
    int arr1[5] = { 11, 13, 15, 17, 19 };
    int arr2[5] = { 2, 4, 12, 18, 20 };
    l1.data = arr1;
    l1.length = sizeof(arr1)/sizeof(int);
    l2.data = arr2;
    l2.length = sizeof(arr2) / sizeof(int);
    int e;
    findMedian(l1, l2, e);
    printf("%d", e);
    printf("%d", e = Search_M(arr1, arr2, sizeof(arr1) / sizeof(int)));
    return 0;
}