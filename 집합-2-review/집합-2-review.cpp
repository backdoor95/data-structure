#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node* next;
}Node;
typedef struct List
{
	Node* H;
}List;
Node* newNode()
{
	Node* p = (Node*)malloc(sizeof(Node));
	return p;
}
void Init(List* list)
{
	list->H = newNode();
}
Node* Add(Node* k, int elem)
{
	Node* t = newNode();
	t->data = elem;
	k->next = t;
	k = t;
	return k;
}
void Print(List* list)
{
	Node* p = list->H;
	p = p->next;
	if (p == NULL)
	{
		printf("%d\n", 0);
		return;
	}
	while (p != NULL)
	{
		printf(" %d", p->data);
		p = p->next;
	}
	printf("\n");
}
Node* Union(Node* A, Node* B)
{
	if (A == NULL && B == NULL)
		return NULL;
	Node* p = newNode();
	if (A == NULL)
	{
		p->data = B->data;
		p->next = Union(A, B->next);
	}
	else if (B == NULL)
	{
		p->data = A->data;
		p->next = Union(A->next, B);
	}
	else
	{
		if (A->data < B->data)
		{
			p->data = A->data;
			p->next = Union(A->next, B);
		}
		else if (A->data > B->data)
		{
			p->data = B->data;
			p->next = Union(A, B->next);
		}
		else
		{
			p->data = A->data;
			p->next = Union(A->next, B->next);
		}
	}
	return p;
}
Node* Intersect(Node* A, Node* B)
{
	if (A == NULL || B == NULL)
		return NULL;
	if (A->data < B->data)
		return Intersect(A->next, B);
	else if (A->data > B->data)
		return Intersect(A, B->next);
	else
	{
		Node* p = newNode();
		p->data = A->data;
		p->next = Intersect(A->next, B->next);
		return p;
	}
}
int main() {
	List A, B;
	List UNION, INTERSECT;
	Init(&A); Init(&B);
	Init(&UNION); Init(&INTERSECT);

	int a, b, e;
	Node* p; Node* k;
	scanf("%d", &a);
	p = A.H;
	for (int i = 0; i < a; i++)
	{
		scanf("%d", &e);
		p = Add(p, e);
	}


	scanf("%d", &b);
	p = B.H;
	for (int i = 0; i < b; i++)
	{
		scanf("%d", &e);
		p = Add(p, e);
	}
	/*Print(&A);
	Print(&B);*/
	UNION.H->next = Union(A.H->next, B.H->next);
	Print(&UNION);
	INTERSECT.H->next = Intersect(A.H->next, B.H->next);
	Print(&INTERSECT);

}
