#include<stdio.h>
#include<stdlib.h>
void make_matrix(int n, int m)
{
	int** matrix;
	matrix = (int**)calloc(n , sizeof(int*));// 0으로 초기화 되면서 동적할당됨
	for (int i = 0; i < n; i++)
		matrix[i] = (int*)calloc(m, sizeof(int));

	int val=1;
	int grad = 1;
	int rowbound = n;
	int colbound = m;
	int indc = -1, indr = 0;

	while (1)
	{
		for (int i = 0; i < colbound; i++)
		{
			indc = indc + grad;
			matrix[indr][indc] = val;
			val++;
		}

		rowbound--;
		if (rowbound < 0)	break;
		for (int i = 0; i < rowbound; i++)
		{
			indr = indr + grad;
			matrix[indr][indc] = val;
			val++;
		}
		colbound--;
		if (colbound < 0)break;
		
		grad *= -1;

	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%02d ", matrix[i][j]);
		printf("\n");
	}

}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	printf("\n");
	make_matrix(n, m);
	return 0;

}