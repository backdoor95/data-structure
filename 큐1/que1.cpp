#include<stdio.h>
#include<stdlib.h>

struct Que
{
	int f;// front
	int r; //rear
	int* Q;//���� �迭
};
int isEmpty(Que* q, int N)
{
	return ((q->r + 1) % N == q->f);
}
int isFull(Que* q, int N)
{
	return ((q->r + 2) % N == q->f);
}
void initQue(Que* q, int N)
{
	q->Q = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
	{
		q->Q[i] = 0;
	}
	q->f = 1;// 0 //���ǻ���---> 1
	q->r = 0;// N-1 //���ǻ��� ---> [(N-1)+1]%N = 0
}
void fullQueueException()
{
	printf("overflow");
}
void enqueue(Que* q, int N, int e)
{
	if (isFull(q, N))
	{
		fullQueueException();
		return;
	}
	q->r = (q->r + 1) % N;
	q->Q[q->r] = e;
}
void emptyQueueException()
{
	printf("underflow\n");
}
int dequeue(Que* q, int N)
{
	if (isEmpty(q, N))
	{
		emptyQueueException();
		return -1;
	}
	int e = q->Q[q->f];
	q->Q[q->f] = 0;// ���ǻ��� : ������ �ʱ�ȭ ���ϸ� �����ȵ� ȿ��// ���Ḯ��Ʈ�� ��带 �����ϱ� ������ �̷��� ���ص���.
	q->f = (q->f + 1) % N;
	return e;
}
void traverse(Que* q, int N)
{
	for (int i = 0; i < N; i++)
	{
		int e = q->Q[i];
		printf(" %d", e);
	}
	printf("\n");
}
int main() {
	Que q;
	int N = 6;
	initQue(&q, N);




	return 0;
}
