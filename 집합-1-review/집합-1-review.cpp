#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct ListNode {
	int data;
	struct ListNode* next;
}Node;
typedef struct singlyLinkedList
{
	Node* First;
}List;
void Init(List* list)
{
	list->First = NULL;
}
Node* newNode(int elem)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = elem;
	p->next = NULL;
	return p;
}
Node* AddFirst(List* list, int elem)
{
	list->First = newNode(elem);
	return list->First;
}
Node* Add(Node* k, int elem)
{
	Node* t = newNode(elem);
	k->next = t;
	k = t;
	return k;
}
bool member(List* B, int e)
{
	if (B->First == NULL)
	{
		return false;
	}
	Node* p = B->First;
	int a;
	while (true)
	{
		a = p->data;
		if (a < e)
			if (p->next == NULL)
				return false;
			else
				p = p->next;
		else if (a > e)
			return false;
		else
			return true;
	}
}
bool subset(List* A, List* B)
{
	if ((A->First == NULL))
	{
		return true;
	}
	Node* p = A->First;
	while (true)
	{
		if (member(B, p->data))
		{
			if (p->next == NULL)
				return true;
			else
				p = p->next;
		}
		else
		{
			printf("%d", p->data);
			return false;
		}
	}
}
void Print(List* list)
{
	Node* p = list->First;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
int main() {
	int a, b, e;
	List A; List B;
	Init(&A); Init(&B);
	Node* pa; Node* pb;

	scanf("%d", &a);
	
	if (a != 0)
	{
		for (int i = 0; i < a; i++)
		{
			scanf("%d", &a);
			if (i == 0)
				pa = AddFirst(&A, e);
			else
				pa = Add(pa, e);
		}
	}
	else
	{
		A.First = NULL;
	}

	scanf("%d", &b);

	if (b != 0)
	{
		for (int i = 0; i < b; i++)
		{
			scanf("%d", &e);
			if (i == 0)
			{
				pb = AddFirst(&B, e);// 첫번째 노드 생성
			}
			else
			{
				pb = Add(pb, e);
			}
		}
	}
	else
	{
		B.First = NULL;
	}

	if (subset(&A, &B))
		printf("%d", 0);
}