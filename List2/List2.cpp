#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode
{
	int coef;
	int exp;
	struct ListNode* next;
}Node;
typedef struct singlyLinkedList
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
	list->H = newNode();// 헤더 노드 생성
}
Node* appendTerm(Node* k, int c, int e)
{
	Node* t = newNode();
	t->coef = c;
	t->exp = e;
	t->next = NULL;
	k->next = t;
	k = t;
	return k;
}
Node* addPoly(Node* x, Node* y)
{
	Node* result = newNode();
	Node* i = x->next; 
	Node* j = y->next;
	Node* k = result;
	while ((i != NULL) && (j != NULL))
	{
		if (i->exp > j->exp)
		{
			k=appendTerm(k, i->coef, i->exp);
			i = i->next;
		}
		else if (i->exp < j->exp)
		{
			k=appendTerm(k, j->coef, j->exp);
			j = j->next;
		}
		else
		{
			int sum = i->coef + j->coef;
			if (sum != 0)
				k=appendTerm(k, sum, i->exp);
			i = i->next;
			j = j->next;
		}
	}

	while (i != NULL)
	{
		k=appendTerm(k, i->coef, i->exp);
		i = i->next;
	}
	while (j != NULL)
	{
		k = appendTerm(k, j->coef, j->exp);
		j = j->next;
	}
	return result;
}
void Print(List* result)
{
	Node* p = result->H;
	p = p->next;
	while (p != NULL)
	{
		printf("%d %d ", p->coef, p->exp);
		p = p->next;
	}
}

int main() {
	int n1, n2;
	int c, e;
	List listA;
	List listB;
	Init(&listA); Init(&listB);
	Node* k;
	List result;
	
	scanf("%d", &n1);// 1번 째 항의 개수
	k = listA.H;
	for (int i = 0; i < n1; i++)
	{
		scanf("%d %d ", &c, &e);
		k=appendTerm(k, c, e);
	}

	scanf("%d", &n2);// 2번 째 항의 개수
	k = listB.H;
	
	for (int i = 0; i < n2; i++)
	{
		scanf("%d %d ", &c, &e);
		k=appendTerm(k, c, e);
	}
	result.H = addPoly(listA.H, listB.H);
	Print(&result);
	
}