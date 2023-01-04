#include<stdio.h>
#include<stdlib.h>
typedef struct Queue {
	int f;// front
	int r;// rear
	int* Q;// 원형 배열
}Que;
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
	q->f = 1;
	q->r = 0;
}
void fullQueueException()
{
	printf("overflow");
}
int enqueue(Que* q, int N, int e)
{
	if (isFull(q, N))
	{
		fullQueueException();
		return 2;
	}
	q->r = (q->r + 1) % N;
	q->Q[q->r] = e;
	return 1;
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
	q->Q[q->f] = 0;
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
	int N, cnt, elem;
	char k;

	scanf("%d", &N);
	initQue(&q, N);
	scanf("%d", &cnt);
	getchar();

	for (int i = 0; i < cnt; i++)
	{
		scanf("%c", &k);
		switch (k)
		{
		case 'I':// input
			scanf(" %d", &elem);
			getchar();
			if (enqueue(&q, N, elem) == 1)// 정상
			{
				;
			}
			else// overflow
			{
				traverse(&q, N);
				return 0;
			}
			break;
		case 'D':// delete
			getchar();
			if (dequeue(&q, N)==-1)
			{
				return 0;
			}
			break;
		case 'P':
			getchar();
			traverse(&q, N);
			break;
		default:
			break;
		}
	}

	return 0;
}