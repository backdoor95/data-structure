#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
	char elem;
	struct node* next;
}node;
typedef struct stack
{
	struct node* top;
}stack;
void initStack(stack* s)
{
	s->top = NULL;
	return;
}
node* getNode()
{
	node* p = (node*)malloc(sizeof(node) * 1);
	p->elem = 0;
	p->next = NULL;
	return p;
}
int isEmpty(stack* s)
{
	return s->top == NULL;
}
void putnode(node* p)
{
	free(p);
	p = NULL;
}
int pop(stack* s)
{
	if (isEmpty(s))
		return -1;
	int e = s->top->elem;
	node* p = s->top;
	s->top = s->top->next;
	putnode(p);
	return e;
}
void push(stack* s, char data)
{
	node* p = getNode();
	p->elem = data;
	p->next = s->top;
	s->top = p;
	return;
}
int isOperand(char c)
{
	if ('0' <= c && c <= '9')// 이 코드로 하면 휠씬 간편
		return 1;
	return 0;//  연산자(operator)일때 
}
int doOperator(char op, int x, int y)
{
	int v=0;
	switch (op)
	{
		case '+': v = x + y; break;
		case '-': v = x - y; break;
		case '*': v = x * y; break;
		case '/': v = x / y; break;
	}
	return v;
}
void evaluate(char* pa)
{
	stack S;
	initStack(&S);

	int N = strlen(pa);
	int idx = 0;

	while (idx != N)
	{
		char s = pa[idx++];
		if (isOperand(s))// 숫자면 저장함.
			push(&S, s);
		else// 연산자일때
		{
			int a = pop(&S)-'0';
			int b = pop(&S)-'0';
			push(&S, doOperator(s, b, a)+'0');
		}
	}
	printf("%d\n", pop(&S)-'0');
}
int main() {

	int n;
	char postfix_array[101];

	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		scanf("%s", postfix_array);
		getchar();
		evaluate(postfix_array);
	}
}