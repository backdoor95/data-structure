#include<stdio.h>
#include<stdlib.h>
/// <summary>
/// 비파괴적 알고리즘 사용 ---> 재귀함수 사용
/// </summary>
typedef struct Node {
	int data;
	struct Node* next;
}Node;
typedef struct List {
	Node* H;// 헤더(머리)
	//Node* T;// 테일(꼬리)
}List;
Node* newNode()
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->next = NULL;
	return p;
}
void Init(List* list) {
	list->H = newNode();
	/*list->T = newNode();
	list->H->next = list->T;*/
}
Node* Add(Node*k, int elem)
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
	if (p == NULL)// 공집합일때
	{
		printf("%d\n", 0);
		
		return;
	}
	while (p!=NULL)
	{
		printf(" %d", p->data);
		p = p->next;
	}
	printf("\n");
}
Node* Union(Node* A, Node* B)// 헤더부터 시작함. 합집합
{
	if (A == NULL && B == NULL)// and 연산자!!!!!  
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
		else//A->data == B->data
		{
			p->data = A->data;// p->data = B->data; 이렇게 해도됨 
			p->next = Union(A->next, B->next);
		}
	}
	return p;
}
Node* Intersect(Node* A, Node* B)// 교집합
{
	if (A == NULL || B == NULL)// or 연산자임.!!!!!
		return NULL;
	if (A->data < B->data)
		return Intersect(A->next, B);
	else if (A->data > B->data)
		return Intersect(A, B->next);
	else//A->data== B->data 
	{
		Node* p = newNode();
		p->data = A->data;
		p->next = Intersect(A->next, B->next);
		return p;
	}
}
int main() {
	List A; List B;
	List UNION; List INTERSECT;
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
	UNION.H->next=Union(A.H->next, B.H->next);
	Print(&UNION);
	INTERSECT.H->next=Intersect(A.H->next, B.H->next);
	Print(&INTERSECT);
}