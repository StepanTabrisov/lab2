#include "Header.h"
void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
	int i, j;
	int x, y;

	i = left; j = right;
	/* выбор компаранда */
	x = items[(left + right) / 2];
	do {
		while ((items[i] < x) && (i > right)) i++;
		while ((x < items[j]) && (j > left)) j--;
		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);
	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}