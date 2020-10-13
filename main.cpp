#include "Header.h"
#pragma warning(suppress : 4996)
#pragma warning(suppress : 6387)
int comp(const void* i, const void* j) {

	return*(int*)i - *(int*)j;
}

int main()
{

	setlocale(LC_ALL, "Rus");

	int* rndm;
	int* up;
	int* down;
	int* updown;
	int* rndm1;
	int* up1;
	int* down1;
	int* updown1;
	int* rndm2;
	int* up2;
	int* down2;
	int* updown2;
	FILE* result;
	int m = 0;
	int n;
	char Name[50];
	printf("Введите название файла, в котором хотите сохранить результаты: ");
	scanf("%s", Name);


	double Tshell[4];
	double Tqsort[4];
	double Tqs[4];


	result = fopen(Name, "w");
	for (int n = 50000; n < 170001; n = n + 30000) {

		rndm = (int*)malloc(n * sizeof(int)); // random
		for (int i = 0; i < n; i++) {
			rndm[i] = rand() % 101;
		}

		up = (int*)malloc(n * sizeof(int)); // up
		for (int i = 0; i < n; i++) {
			up[i] = i + 1;
		}

		down = (int*)malloc(n * sizeof(int)); // down
		for (int i = 0; i < n; i++) {
			down[i] = n - 1;
		}

		updown = (int*)malloc(n * sizeof(int)); // updown
		for (int i = 0; i < n; i++) {

			if (i < n / 2) {

				updown[i] = i;
			}

			else {


				updown[i] = i - m;
				m = m + 2;
			}

		}
		clock_t t0 = clock();
		shell(rndm, n);
		clock_t t1 = clock();
		Tshell[0] = (double)(t1 - t0) / CLK_TCK;
		free(rndm);

		clock_t t2 = clock();
		shell(up, n);
		clock_t t3 = clock();
		Tshell[1] = (double)(t3 - t2) / CLK_TCK;
		free(up);

		clock_t t4 = clock();
		shell(down, n);
		clock_t t5 = clock();
		Tshell[2] = (double)(t5 - t4) / CLK_TCK;
		free(down);


		clock_t t6 = clock();
		shell(updown, n);
		clock_t t7 = clock();
		Tshell[3] = (double)(t7 - t6) / CLK_TCK;
		free(updown);


		rndm1 = (int*)malloc(n * sizeof(int)); // random
		for (int i = 0; i < n; i++) {
			rndm1[i] = rand() % 1001;
		}

		up1 = (int*)malloc(n * sizeof(int)); // up
		for (int i = 0; i < n; i++) {
			up1[i] = i;
		}

		down1 = (int*)malloc(n * sizeof(int)); // down
		for (int i = 0; i < n; i++) {
			down1[i] = n - 1;

		}

		updown1 = (int*)malloc(n * sizeof(int)); // updown
		for (int i = 0; i < n; i++) {

			if (i < n / 2) {

				updown1[i] = i;
			}

			else {


				updown1[i] = i - m;
				m = m + 2;
			}

		}
		clock_t t8 = clock();
		qs(rndm1, 0, n - 1);
		clock_t t9 = clock();
		Tqs[0] = (double)(t9 - t8) / CLK_TCK;
		free(rndm1);

		clock_t t10 = clock();
		qs(up1, 0, n - 1);
		clock_t t11 = clock();
		Tqs[1] = (double)(t11 - t10) / CLK_TCK;
		free(up1);

		clock_t t12 = clock();
		qs(down1, 0, n - 1);
		clock_t t13 = clock();
		Tqs[2] = (double)(t13 - t12) / CLK_TCK;
		free(down1);

		clock_t t14 = clock();
		qs(updown1, 0, n - 1);
		clock_t t15 = clock();
		Tqs[3] = (double)(t15 - t14) / CLK_TCK;
		free(updown1);



		rndm2 = (int*)malloc(n * sizeof(int)); // random
		for (int i = 0; i < n; i++) {
			rndm2[i] = rand() % 1001;
		}

		up2 = (int*)malloc(n * sizeof(int)); // up
		for (int i = 0; i < n; i++) {
			up2[i] = i;
		}

		down2 = (int*)malloc(n * sizeof(int)); // down
		for (int i = 0; i < n; i++) {
			down2[i] = n - 1;
		}

		updown2 = (int*)malloc(n * sizeof(int)); // updown
		for (int i = 0; i < n; i++) {

			if (i < n / 2) {

				updown2[i] = i + 1;
			}

			else {


				updown2[i] = i - 1;

			}

		}
		clock_t t16 = clock();
		qsort(rndm2, n, sizeof(int), comp);
		clock_t t17 = clock();

		clock_t t18 = clock();
		qsort(up2, n, sizeof(int), comp);
		clock_t t19 = clock();

		clock_t t20 = clock();
		qsort(down2, n, sizeof(int), comp);
		clock_t t21 = clock();

		clock_t t22 = clock();
		qsort(updown2, n, sizeof(int), comp);
		clock_t t23 = clock();

		Tqsort[0] = (double)(t17 - t16) / CLK_TCK;
		Tqsort[1] = (double)(t19 - t18) / CLK_TCK;
		Tqsort[2] = (double)(t21 - t20) / CLK_TCK;
		Tqsort[3] = (double)(t23 - t22) / CLK_TCK;

		free(rndm2);
		free(up2);
		free(down2);
		free(updown2);

		printf("|----------------------------------------Размер массива:%d----------------------------------------------------------|\n", n);
		printf("|---------------------------------|--Случайные числа--|--По возрастанию--|--По убыванию--|--По возрастанию - убыванию--|\n");
		printf("|Сортировка Шелла:                |------%lf-----|------%lf-----|------%lf----|--------%lf---------|\n", Tshell[0], Tshell[1], Tshell[2], Tshell[3]);
		printf("|Быстрая сортировка:              |------%lf-----|------%lf-----|------%lf----|--------%lf---------|\n", Tqs[0], Tqs[1], Tqs[2], Tqs[3]);
		printf("|Быстрая сортировка(Библиотечная):|------%lf-----|------%lf-----|------%lf----|--------%lf---------|\n", Tqsort[0], Tqsort[1], Tqsort[2], Tqsort[3]);
		printf("|----------------------------------------------------------------------------------------------------------------------|\n\n\n");


		fprintf(result, "|----------------------------------------Размер массива:%d--------------------------------------------------------------------------------------------------------|\n", n);
		fprintf(result, "|\t\t\t\t|Случайные числа\t|По возрастанию\t|По убыванию\t|По возрастанию - убыванию\t| \n");
		fprintf(result, "|Сортировка Шелла :\t\t|\t%lf\t|\t%lf\t|\t%lf\t|\t%lf\t\t|\n", Tshell[0], Tshell[1], Tshell[2], Tshell[3]);
		fprintf(result, "|Быстрая сортировка:\t\t|\t%lf\t|\t%lf\t|\t%lf\t|\t%lf\t\t|\n", Tqs[0], Tqs[1], Tqs[2], Tqs[3]);
		fprintf(result, "|Быстрая сортировка(Библиотечная):\t|\t%lf\t|\t%lf\t|\t%lf\t|\t%lf\t\t|\n", Tqsort[0], Tqsort[1], Tqsort[2], Tqsort[3]);
		fprintf(result, "|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n\n\n");
	}
	fclose(result);
	system("PAUSE");
}