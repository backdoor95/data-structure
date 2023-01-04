#include<stdio.h>
#include<stdlib.h>

struct Que
{
	int f;// front
	int r; //rear
	int* Q;//원형 배열
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
	q->f = 1;// 0 //주의사항---> 1
	q->r = 0;// N-1 //주의사항 ---> [(N-1)+1]%N = 0
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
	q->Q[q->f] = 0;// 주의사항 : 삭제후 초기화 안하면 삭제안된 효과// 연결리스트는 노드를 삭제하기 때문에 이렇게 안해도됨.
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
