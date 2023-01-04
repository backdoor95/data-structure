#include<stdio.h>
#include<stdlib.h>
typedef struct DListNode
{
	char elem;
	struct DListNode* prev;
	struct DListNode* next;
}DLNode;
typedef struct DList// 
{
	DLNode* H;
	DLNode* T;
	int cnt;
}DList;
DLNode* getNode(char data)// 노드생성
{
	DLNode* p = (DLNode*)malloc(sizeof(DLNode));
	p->elem = data;
	p->prev = p->next = NULL;
	return p;
}
void Init(DList* list)// 초기화
{
	list->cnt = 0;
	list->H = getNode('*');
	list->T = getNode('%');
	list->H->next = list->T;
	list->T->prev = list->H;
}
void Get(DList* list, int pos)// 원하는 위치의 원소출력
{
	if ((pos < 1) || (pos > list->cnt))// 예외처리
	{
		printf("invalid position\n");// invalidRandException
		return;
	}
	DLNode* p = list->H;
	for (int i = 1; i <= pos; i++)
		p = p->next;
	printf("%c\n", p->elem);
}
void Print(DList* list)// 순회 traverse() 하면서 출력
{// 내가 틀린이유는 쓰레기 값 때문임( header, tail 의 쓰레기 값을 조심하자)
	DLNode* p = list->H;
	p = p->next;// 쓰레기값 방지용
	while (p != list->T)
	{
		printf("%c", p->elem);
		p = p->next;
	}
	/*for (DLNode* p = list->H->next; p != NULL; p = p->next)
	{
		printf("%c", p->elem);
	}*/
	printf("\n");
}
void AddNodeBefore(DLNode* p, char c)
{
	DLNode* q = getNode(c);// 그냥 0으로 초기화
	//q->elem = c;
	q->prev = p->prev;
	q->next = p;
	(p->prev)->next = q;
	p->prev = q;

}
void Add(DList* list, int pos, char c)// insert 기능 함수
{
	if ((pos < 1) || (pos > (list->cnt + 1)))///여기는 특별히 +1 을 해줘야  이.부.분.만!!!
	{
		printf("invalid position\n");// invalidRandException
		return;
	}
	DLNode* p = list->H;
	for (int i = 1; i <= pos; i++)
	{
		p = p->next;
	}
	AddNodeBefore(p, c);
	list->cnt = list->cnt + 1;// cnt 증가

}
void RemoveNode(DLNode* p)
{
	(p->prev)->next = p->next;
	(p->next)->prev = p->prev;
	free(p);
}
void Remove(DList* list, int pos)
{
	if ((pos < 1) || (pos > list->cnt))
	{
		printf("invalid position\n");// invalidRandException
		return;
	}
	DLNode* p = list->H;
	for (int i = 1; i <= pos; i++)
	{
		p = p->next;
	}
	RemoveNode(p);
	list->cnt = list->cnt - 1;
}
int main() {

	DList list;
	Init(&list);// 초기화

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