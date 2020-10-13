#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>

int main(void)
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	 // объ€вл€ем переменные дл€ определени€ времени выполнени€
	int i = 0, j = 0, r;
	int **a, **b, **c, elem_c;
	
	int n, k;



	printf("¬ведите значение n\n");
	scanf_s("%d", &n);
	printf("¬ведите значение k\n");
	scanf_s("%d", &k);

	a = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		a[i] = (int*)malloc(k * sizeof(int));
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++) {										// «аполнение массива случайными числами в диапазоне от -50 до 50
			a[i][j] = rand() % 101;

		}

	i = 0; j = 0;
	b = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		b[i] = (int*)malloc(k * sizeof(int));
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++) {										// «аполнение массива случайными числами в диапазоне от -50 до 50
			b[i][j] = rand() % 101;

		}


	c = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		c[i] = (int*)malloc(k * sizeof(int));
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++) {										// «аполнение массива случайными числами в диапазоне от -50 до 50
			elem_c = 0;

		}


	clock_t t0 = clock();

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < k; j++)
		{
			elem_c = 0;
			for (r = 0; r < n; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}

	clock_t t1 = clock();

	printf("ѕроизведение двух матриц размерами %d x %d зан€ло по времени %lf c:\n", n, k, (double)(t1 - t0) / CLK_TCK);
	return(0);
}