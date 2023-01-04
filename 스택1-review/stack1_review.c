#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void pop(char* stack, int* t)
{
	if ((*t) == -1)
	{
		printf("Stack Empty\n");
		return;
	}
	*t -= 1;
}
void push(char* stack, char data, int* t, int n)
{
	int stack_size = n;
	if (*t == stack_size - 1)
	{
		printf("Stack FULL\n");
		return;
	}
	(*t) += 1;
	stack[*t] = data;

}
void peek(char* stack, int* t)
{
	if (*t == -1)
	{
		printf("Stack Empty\n");
		return;
	}
	printf("%c\n", stack[*t]);
}
void duplicate(char* stack, int* t, int n)
{
	int stack_size = n;
	if (*t == stack_size - 1)
	{
		printf("Stack FULL\n");
		return;
	}
	char data = stack[*t];
	pop(stack, t);
	push(stack, data, t, n);
	push(stack, data, t, n);
}
void upRotate(char* stack, int n, int* t)
{
	if (n > *t + 1)// n이 데이터의 개수보다 크면 아무 작업을 하지않는다.
		return;
	char tmp;
	tmp = stack[*t];
	for (int i = 0; i < n - 1; i++)
	{
		stack[*t - i] = stack[*t - i - 1];
	}
	stack[*t - n + 1] = tmp;
}
void downRotate(char* stack, int n, int* t)
{
	if (n > *t + 1)// n이 데이터의 개수보다 크면 아무 작업을 하지않는다.
		return;
	char tmp;
	tmp = stack[*t - n + 1];
	for (int i = n - 1; i >= 1; i--)
		stack[*t - i] = stack[*t - i + 1];
	stack[*t] = tmp;
}
void print(char* stack, int* t)
{
	for (int i = *t; i >= 0; i--)
		printf("%c", stack[i]);
	printf("\n");
}
int main() {

	int n, cnt, r;
	char str[10]; char data;
	int* idx = (int*)malloc(sizeof(int));
	*idx = -1;// 초기화 조건--->top의 인덱스위치를 나타내는 변수임.

	scanf("%d", &n);//stack size
	char* stack = (char*)malloc(sizeof(char) * n);

	scanf("%d", &cnt);//연산 개수
	getchar();

	for (int i = 0; i < cnt; i++)
	{

		scanf("%s", str);
		getchar();
		if (strcmp(str, "POP") == 0)
		{
			pop(stack, idx);
		}
		else if (strcmp(str, "PUSH") == 0)
		{
			scanf("%c", &data);
			getchar();
			push(stack, data, idx, n);
		}
		else if (strcmp(str, "PEEK") == 0)
		{
			peek(stack, idx);
		}
		else if (strcmp(str, "DUP") == 0)
		{
			duplicate(stack, idx, n);
		}
		else if (strcmp(str, "UpR") == 0)
		{
			scanf("%d", &r);
			getchar();
			upRotate(stack, r, idx);
		}
		else if (strcmp(str, "DownR") == 0)
		{
			scanf("%d", &r);
			getchar();
			downRotate(stack, r, idx);
		}
		else if (strcmp(str, "PRINT") == 0)
		{
			print(stack, idx);
		}

	}
}