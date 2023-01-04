#include<stdio.h>
#include<stdlib.h>
typedef struct DListNode
{
	char elem;
	struct DListNode* prev;
	struct DListNode* next;
}Node;
typedef struct DList
{
	Node* H;
	Node* T;
	int cnt;
};
Node* newNode(char data)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->elem = data;
	p->prev = p->next = NULL;
	return p;
}
void Init(DList* list)
{
	list->cnt = 0;
	list->H = newNode('*');
	list->T = newNode('#');
	list->H->next = list->T;
	list->T->prev = list->H;
}
void Get(DList* list, int pos)
{
	if (pos<1 || pos>list->cnt)
	{
		printf("invalid position\n");
		return;
	}
	Node* p = list->H;
	for (int i = 1; i <= pos; i++)
		p = p->prev;
	printf("%c\n", p->elem);
}
void Print(DList* list)
{
	Node* p = list->H;
	p = p->next;
	while (p != list->T)
	{
		printf("%c", p->elem);
		p = p->next;
	}
	printf("\n");
}
void AddNodeBefore(Node* p, char data)
{
	Node* n = newNode(data);
	n->prev = p->prev;
	n->next = p;
	p->prev->next = n;
	p->prev = n;
}
void Add(DList* list, int pos, char c)
{
	if (pos<1 || pos>list->cnt+1)
	{
		printf("invalid position\n");
		return;
	}
	Node* p = list->H;
	for (int i = 1; i <= pos; i++)
		p = p->next;
	AddNodeBefore(p, c);
	list->cnt += 1;
}
void RemoveNode(Node* p)
{
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
}
void Remove(DList* list, int pos)
{
	if (pos<1 || pos>list->cnt)
	{
		printf("invalid position\n");
		return;
	}
	Node* p = list->H;
	for (int i = 1; i <= pos; i++)
		p = p->next;
	RemoveNode(p);
	list->cnt -= 1;
}
int main()
{
	DList list;
	Init(&list);
	int n, r;
	char menu, e;
	
	scanf("%d", &n);
	getchar();
	while (n != 0)
	{

		scanf("%c", &menu);

		switch (menu)
		{
		case 'A'://list의 순위 r에 원소 e를 추가한다.
			//	add(list, r, e)
			scanf(" %d %c", &r, &e);
			Add(&list, r, e);
			break;

		case 'D'://list의 순위 r에 위치한 원소를 삭제한다 (주교재의 remove와 동일)
			//	delete(list, r)
			scanf(" %d", &r);
			Remove(&list, r);
			break;

		case 'G'://list의 순위 r에 위치한 원소를 반환한다.
			//	get(list, r)
			scanf(" %d", &r);
			Get(&list, r);
			break;

		case 'P'://list의 모든 원소를 저장 순위대로 공백없이 출력한다.
			//	print(list)
			Print(&list);
			break;

		default:
			return 0;
		}
		getchar();
		n--;

	}

}
// [Double Linked List]_Practice
///////////////////	   [10/2(일요일) review-2]	///////////////////////////
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct Node {
//	char data;
//	struct Node* prev;
//	struct Node* next;
//}Node;
//typedef struct List {
//	Node *H;
//	Node *T;
//	int n;
//}List;
//Node* newNode(char data)
//{
//	Node* p = (Node*)malloc(sizeof(Node));
//	p->data = data;
//	p->prev = p->next = NULL;
//	return p;
//}
//void Init(List* list)
//{
//	list->H = newNode('A');
//	list->T = newNode('Z');
//	list->H->next = list->T;
//	list->T->prev = list->H;
//	list->n = 0;
//}
//void Get(List* list, int pos)
//{
//	if (pos <= 0 || pos > list->n)
//	{
//		printf("invalid position\n");
//		return;
//	}
//	Node* p = list->H;
//	for (int i = 1; i <= pos; i++)
//	{
//		p = p->next;
//	}
//	printf("%c\n", p->data);
//}
//void AddBefore(Node*p, char data)
//{
//	Node* New = newNode(data);
//
//	New->prev = p->prev;
//	New->next = p;
//	p->prev->next = New;
//	p->prev = New;
//}
//void Add(List* list, int pos, char data)
//{
//	if (pos < 1 || pos > list->n+1)
//	{
//		printf("invalid position\n");
//		return;
//	}
//	Node* p = list->H;
//	for (int i = 1; i <= pos; i++)
//	{
//		p = p->next;
//	}
//	AddBefore(p, data);
//	list->n++;
//}
//void Delete(List* list, int pos)
//{
//	if (pos<1 || pos>list->n)
//	{
//		printf("invalid position\n");
//		return;
//	}
//	Node* p = list->H;
//	for (int i = 1; i <= pos; i++)
//		p = p->next;
//	p->prev->next = p->next;
//	p->next->prev = p->prev;
//	list->n--;
//	free(p);
//}
//void Print(List* list)
//{
//	Node* p = list->H;
//	p = p->next;
//	while (p != list->T)
//	{
//		printf("%c", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
//int main() {
//	List list;
//	Init(&list);
//	int n,r;
//	char menu, data;
//	scanf("%d", &n);
//	getchar();
//
//	while (n) {
//
//		scanf("%c", &menu);
//		switch (menu)
//		{
//		case 'A':
//			scanf(" %d %c", &r, &data);
//			getchar();
//			Add(&list, r, data);
//			break;
//		case 'D':
//			scanf(" %d", &r);
//			getchar();
//			Delete(&list, r);
//			break;
//		case 'G':
//			scanf(" %d", &r);
//			getchar();
//			Get(&list, r);
//			break;
//		case'P':
//			getchar();
//			Print(&list);
//		default:
//			break;
//		}
//		n--;
//	}
//
//}