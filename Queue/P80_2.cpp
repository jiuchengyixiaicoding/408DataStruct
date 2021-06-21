#include <iostream>
#include <cstdlib>

using namespace std;

#define MaxSize 10

typedef struct SeqQueue {
	int data[MaxSize];
	int front=0, rear=0;
}SeqQueue;

typedef struct Stack {
	int data[MaxSize];
	int top = -1;
}Stack;

bool inverseSeqQueue(SeqQueue &q, Stack s) {
	int i = 0;
	while (i < MaxSize) {
		s.data[i] = q.data[q.front++];
	}
}

int main() {
	SeqQueue sq;
	Stack s;
	int i = 0;
	while (i < MaxSize)
	{
		sq.data[i] = i;
	}
	sq.rear = i - 1;
	return 0;
}