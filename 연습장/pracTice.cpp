#include<stdio.h>
#include<stdlib.h>

struct node
{
	int elem;
	struct node* next;
};
struct Que
{
	struct node* f;
	struct node* r;
};
void initQueue(Que* q)
{
	q->r = NULL;
	q->f = NULL;
}
int isEmpty(Que* q)
{
	return (q->f == NULL);
}
struct node* getnode()
{
	struct node* p = (struct node*)malloc(sizeof(struct node) * 1);
	p->elem = -1;
	p->next = NULL;
	return p;
}
void enqueue(Que* q, int e)
{
	struct node* p = getnode();
	p->elem = e;
	p->next = NULL;
	if (isEmpty(q))
	{
		q->r = p;
		q->f = p;
	}
	else
	{
		q->r->next = p;
		q->r = p;
	}
}
void emptyQueueException()
{
	printf("EmptyQueueException\n");
}
void putnode(struct node* p)
{
	free(p);
	p = NULL;
}
int dequeue(Que* q)
{
	if (isEmpty(q))
	{
		emptyQueueException();
		return -1;
	}
	int e = q->f->elem;
	struct node* p = q->f;
	q->f = q->f->next;
	if (q->f == NULL)
		q->r = NULL;
	putnode(p);
	return e;
}
void traverse(Que* q)
{
	struct node* p = q->f;
	while (p != NULL)
	{
		printf(" %d", p->elem);
		p = p->next;
	}
	printf("\n");
}
int main()
{
	Que q;
	initQueue(&q);
}