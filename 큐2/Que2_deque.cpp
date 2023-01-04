#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node {
	int elem;
	struct node* prev;
	struct node* next;
}node;
typedef struct deque {

	node* f;
	node* r;
}deque;
void initDeque(deque* q)
{
	q->r = NULL;
	q->f = NULL;
}
int isEmpty(deque* q)
{
	return (q->f == NULL);
}
node* getnode() {
	node* p = (node*)malloc(sizeof(node));
	p->elem = -1;
	p->next = NULL;
	p->prev = NULL;
	return p;
}
void putnode(node* p)
{
	free(p);
	p = NULL;
}
void add_front(deque* q, int X)
{
	node* p = getnode();
	p->elem = X;
	p->next = NULL;
	p->prev = NULL;
    if (isEmpty(q))
    {
    	q->f = p;
    	q->r = p;
    }
    else
    {
    	p->next = q->f;
    	q->f->prev = p;
    	q->f = p;
    }
}
void add_rear(deque* q, int X)
{
	node* p = getnode();
	p->elem = X;
	p->next = NULL;
	p->prev = NULL;
	if (isEmpty(q))
	{
		q->f = p;
		q->r = p;
	}
	else
	{
		p->prev = q->r;
		q->r->next = p;
		q->r = p;
	}
}
void emptyQueueException()
{
	printf("underflow\n");
}
int delete_front(deque* q)
{
	if (isEmpty(q))
	{
		emptyQueueException();
		return -1;
	}
	int e = q->f->elem;
	node* p = q->f;
	q->f = q->f->next;
	if (q->f == NULL)
		q->r = NULL;
	else
		q->f->prev = NULL;
	putnode(p);

	return e;
}
int delete_rear(deque* q)
{
	if (isEmpty(q))
	{
		emptyQueueException();
		return -1;
	}
	int e = q->r->elem;
	node* p = q->r;
	q->r = q->r->prev;
	if (q->r == NULL)
		q->f = NULL;
	else
		q->r->next = NULL;
	putnode(p);
	return e;
}
void traverse(deque* q)
{
	node* p = q->f;
	while (p != NULL)
	{
		printf(" %d", p->elem);
		p = p->next;
	}
	printf("\n");
}
int main() {

	deque dq;
	initDeque(&dq);
	char s[3];
	int n, data;

	scanf("%d", &n);
	getchar();

	for (int i = 0; i < n; i++)
	{
		scanf("%s", s);
		
		if (strcmp("AF", s) == 0)
		{
			scanf("%d", &data);
			getchar();
			add_front(&dq, data);

		}
		else if (strcmp("AR", s) == 0)
		{
			scanf("%d", &data);
			getchar();
			add_rear(&dq, data);
		}
		else if (strcmp("DF", s) == 0)
		{
			getchar();
			if (delete_front(&dq) == -1)
				return 0;
			
		}
		else if (strcmp("DR", s) == 0)
		{
			getchar();
			if (delete_rear(&dq) == -1)
				return 0;
		}
		else
		{
			traverse(&dq);
		}


	}


	return 0;
}