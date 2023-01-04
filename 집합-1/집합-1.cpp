#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>// bool 함수 쓰려면 이걸 써야함.
typedef struct ListNode {
	int data;
	struct ListNode* next;
}Node;
typedef struct singlyLinkedList
{
	Node* First;
	
}List;
void Init(List * list) {
	list->First = NULL;
	
}
Node* newNode(int elem) {
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
bool member(List *B , int e)//element
{
	
	if (B->First == NULL)// 제발 [=] ,[==] 실수 줄이자 
		return false;
	Node* p = B->First;
	
	int a;
	while (true)
	{
		a = p->data;
		
		if (a < e)
			if (p->next == NULL)
			{
				return false;
			}
			else
				p = p->next;
		else if (a > e)

			return false;
		else// a==e
			return true;
	}
}
bool subset(List* A, List* B)
{
	if ((A->First == NULL))
	{	
		//printf("%d", 0);
		return true;
	}
	Node* p = A->First;
	
	while (true)
	{
		if (member(B, p->data))
		{
			if (p->next == NULL)
			{ 
				//printf("%d", 0);
				
				return true;
			}
			else
				p = p->next;
		}
		else
		{ 
			printf("%d", p->data);
			return false;
		}
	}
	//printf("while out\n");
}
void Print(List* list)
{
	//printf("List출력\n");
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
	
	if (a != 0) {
		for (int i = 0; i < a; i++)
		{
			scanf("%d", &e);
			if (i == 0)
			{
				pa=AddFirst(&A, e);// 첫번째 노드 생성
			}
			else
			{
				pa = Add(pa, e);
			}
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

	//printf("********************\n");
	//Print(&A);
	//Print(&B);
	//printf("********************\n");

	if (subset(&A, &B))
		printf("%d", 0);
	


	/*if (subset(&A, &B))
		printf("합집합 입니다.\n");
	else
		printf("합집합이 아닙니다.\n");*/
		

}