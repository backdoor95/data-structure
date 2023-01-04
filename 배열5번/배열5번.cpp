#include<stdio.h>
#include<stdlib.h>
void fill_cell(int matrix[][101], int n, int i, int j, int* num)
{
	while (1)
	{
		if (j < 0 || i >= n)break;
		matrix[i++][j--] = (*num)++;
	}
}
int main() {
	int n, m, i, j, num = 1;
	int matrix[101][101];
	scanf("%d %d", &n, &m);
	if (n < 1 || n>100 || m < 1 || m>100)
	{
		printf("error matrix");
		return 1;
	}
	// 접근 방식:[ 1. 좌측상단] 채우고 난 뒤에 [ 2. 우측하단]
	for (j = 0; j < m; j++)// **[ 1. 좌측상단]
	{
		fill_cell(matrix, n, 0, j, &num);
	}

	for (i = 1; i < n; i++)///**[ 2. 우측하단]
	{
		fill_cell(matrix, n, i, m - 1, &num);
	}

	for (i = 0; i < n; i++)// 출력
	{
		for (j = 0; j < m; j++)
		{
			printf("%02d ", matrix[i][j]);
		}
		printf("\n");
	}


	return 0;
}