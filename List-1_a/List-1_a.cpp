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
DLNode* getNode(char data)// ������
{
	DLNode* p = (DLNode*)malloc(sizeof(DLNode));
	p->elem = data;
	p->prev = p->next = NULL;
	return p;
}
void Init(DList* list)// �ʱ�ȭ
{
	list->cnt = 0;
	list->H = getNode('*');
	list->T = getNode('%');
	list->H->next = list->T;
	list->T->prev = list->H;
}
void Get(DList* list, int pos)// ���ϴ� ��ġ�� �������
{
	if ((pos < 1) || (pos > list->cnt))// ����ó��
	{
		printf("invalid position\n");// invalidRandException
		return;
	}
	DLNode* p = list->H;
	for (int i = 1; i <= pos; i++)
		p = p->next;
	printf("%c\n", p->elem);
}
void Print(DList* list)// ��ȸ traverse() �ϸ鼭 ���
{// ���� Ʋ�������� ������ �� ������( header, tail �� ������ ���� ��������)
	DLNode* p = list->H;
	p = p->next;// �����Ⱚ ������
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
	DLNode* q = getNode(c);// �׳� 0���� �ʱ�ȭ
	//q->elem = c;
	q->prev = p->prev;
	q->next = p;
	(p->prev)->next = q;
	p->prev = q;

}
void Add(DList* list, int pos, char c)// insert ��� �Լ�
{
	if ((pos < 1) || (pos > (list->cnt + 1)))///����� Ư���� +1 �� �����  ��.��.��.��!!!
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
	list->cnt = list->cnt + 1;// cnt ����

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
	Init(&list);// �ʱ�ȭ

	int n, r;
	char menu, e;

	scanf("%d", &n);
	getchar();

	while (n != 0)
	{

		scanf("%c", &menu);

		switch (menu)
		{
		case 'A'://list�� ���� r�� ���� e�� �߰��Ѵ�.
			//	add(list, r, e)
			scanf(" %d %c", &r, &e);
			Add(&list, r, e);
			break;

		case 'D'://list�� ���� r�� ��ġ�� ���Ҹ� �����Ѵ� (�ֱ����� remove�� ����)
			//	delete(list, r)
			scanf(" %d", &r);
			Remove(&list, r);
			break;

		case 'G'://list�� ���� r�� ��ġ�� ���Ҹ� ��ȯ�Ѵ�.
			//	get(list, r)
			scanf(" %d", &r);
			Get(&list, r);
			break;

		case 'P'://list�� ��� ���Ҹ� ���� ������� ������� ����Ѵ�.
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