#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
	p->elem = 'z';
	p->next = NULL;
	return p;
}
void push(stack* s, char data)
{
	node* p = getNode();
	p->elem = data;
	p->next = s->top;
	s->top = p;
	return;
}
int isEmpty(stack* s)
{
	return s->top == NULL;
}
void emptyStackException()
{
	printf("StackException \n");
}
void putnode(node* p)
{
	free(p);
	p = NULL;
}
void write(char c)
{
	if (c == '$')
		printf("+");
	else if (c == '@')
		printf("-");
	else if (c == '(')
		printf("");
	else
		printf("%c", c);
}
void pop(stack* s)
{
	if (isEmpty(s))
		return;
	write(s->top->elem);
	node* p = s->top;
	s->top = s->top->next;
	putnode(p);
}
int strfind(char* str, char s)
{
	for (int i = 0; i < strlen(str); i++)
		if (str[i] == s)
			return i;
}
int getPrior(char s)
{
	char Prior[12] = {'(', '|', '&', '<', '>', '+','-','/','*','!','$','@'};// unary + (&), unary -(@)
	char Prior_N[12] = {0,1,2,3,3,4,4,5,5,6,6,6 };
	return Prior_N[strfind(Prior, s)];
}
char top(stack* s)
{
	if (s->top == NULL)
	{
		emptyStackException();
		return 'e';
	}
	return s->top->elem;
}
int First(stack* s)
{
	if (s->top->elem == '(')
		return 0;
	return 1;
}
int isOperand(char c)
{
	if ('A' <= c && c <= 'Z')// �� �ڵ�� �ϸ� �پ� ����
		return 1;
	return 0;//  ������(operator)�϶� 
}
void convert(char* infix_array)// infix expression = ��������
{							   //postfix expression = ��������
	stack S;
	initStack(&S);
	int N = strlen(infix_array);
	int idx = 0;

	// ���׿����ڸ� ��ó���� ���� �ٲ��ش�.( + )->( $ ), ( - )->( @ )
	for (int i = 0; i < N; i++)
	{
		if (infix_array[i] == '+' || infix_array[i] == '-')
		{
			if (i == 0)
			{
				//infix_array[i] = (infix_array[i] == '+') ? '$' : '@';
				if (infix_array[i] == '+')
					infix_array[i] = '$';
				else
					infix_array[i] = '@';
			}
			else if (infix_array[i - 1] != ')' && !('A' <= infix_array[i - 1] && infix_array[i - 1] <= 'Z'))
			{
				//infix_array[i] = (infix_array[i] == '+') ? '$' : '@';
				if (infix_array[i] == '+')
					infix_array[i] = '$';
				else
					infix_array[i] = '@';
			}
		}
	}

	while (idx != N)
	{
		char s = infix_array[idx++];

		if (isOperand(s))// �ǿ����� �϶�
		{
			write(s);
		}
		else if (s == '(')
		{
			push(&S, s);// ���ÿ� ����
		}
		else if (s == ')')
		{
			while (top(&S) != '(')
				pop(&S);// ���
			pop(&S);// ���ÿ��� ����

			//while (First(&S))
			//	pop(&S);// �����ϰ� ���
			//pop(&S);// ���ÿ��� ����
			/*while (1)
			{
				if (First(&S) == 1)
					pop(&S);
				else
				{
					pop(&S);
					break;
				}
			}*/
		}
		else// �������϶�
		{
			if (s == '&' || s == '|')
			{
				while ((!isEmpty(&S)) && (getPrior(s) <= getPrior(top(&S))))
				{
					pop(&S);
					pop(&S);
				}
				push(&S, s);
				s = infix_array[idx++];
				push(&S, s);

			}
			else
			{
				while ((!isEmpty(&S)) && (getPrior(s) <= getPrior(top(&S))))
					pop(&S);
				push(&S, s);

			}
			/*while ((!isEmpty(&S)) && (getPrior(s) <= getPrior(top(&S))))
				pop(&S);
			push(&S, s);*/
		}

	}
	while (!isEmpty(&S))
		pop(&S);
}
int main() {
	int n;//������ ����
	char s[101];

	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s);
		getchar();
		convert(s);
		printf("\n");
	}

}