#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 101

typedef char element;
typedef struct{
	element data[MAX_STACK_SIZE];
	int top;
}StackType;
void Init_stack(StackType* s)
{
	s->top = -1;
}
int is_empty(StackType* s)
{
	return (s->top == -1);
}
int is_full(StackType* s)
{
	return(s->top == (MAX_STACK_SIZE - 1));
}
void push(StackType* s, element item)
{
	if (is_full(s))
	{
		//printf("스택 포화 에러\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}
element pop(StackType* s)
{
	
		return s->data[(s->top)--];
}
element peek(StackType* s)
{
	
		return s->data[s->top];
}
int prec(char op)
{
	switch (op)
	{
	case '(':case')':return 0;
	case '|':return 1;
	case '&':return 2;
	case '<':case '>':return 3;
	case '+':case '-':return 4;
	case '*':case '/':return 5;
	case '!':case '$':case '@':return 6;
	}
	return -1;
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
void infix_to_postfix(char infix_array[])
{
	int i = 0;
	char ch, top_op;
	int len = strlen(infix_array);
	StackType s;
	// 단항연산자를 전처리로 먼저 바꿔준다.( + )->( $ ), ( - )->( @ )
	for (int i = 0; i < len; i++)
	{
		if (infix_array[i] == '+' || infix_array[i] == '-')
		{
			if (i == 0)
			{
				infix_array[i] = (infix_array[i] == '+') ? '$' : '@';
			}
			else if (infix_array[i - 1] != ')' && !('A' <= infix_array[i - 1] && infix_array[i - 1] <= 'Z'))
			{
				infix_array[i] = (infix_array[i] == '+') ? '$' : '@';
			}
		}
	}

	Init_stack(&s);

	for (i = 0; i < len; i++)
	{
		ch = infix_array[i];
		switch (ch)
		{
		
		case '+':case '-':case '*':case '/':case '$':case '@':case '<': case '>': case '!': case '|': case '&':// 연산자
			if (ch == '|')
			{
				while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
				{
					write(pop(&s));
					write(pop(&s));
				}
				push(&s, ch);
				push(&s, ch);
				i++;
				break;
			}
			else if (ch == '&')
			{
				while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
				{
					write(pop(&s));
					write(pop(&s));
				}
				push(&s, ch);
				push(&s, ch);
				i++;
				break;
			}
			else
			{
				while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
					write(pop(&s));
				push(&s, ch);
				break;
			}

		case '(':
			push(&s, ch);
			break;

		case ')':
			top_op = pop(&s);
			while (top_op != '(')
			{
				write(top_op);
				top_op = pop(&s);
			}
			break;
		default:
			write(ch);
			break;
		}
	}
	while (!is_empty(&s))
		printf("%c", pop(&s));
}
int main() {
	int n;
	char s[101];

	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		scanf("%s", &s);
		getchar();
		infix_to_postfix(s);
		printf("\n");
	}
}