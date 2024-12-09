#include "sort.h"

int main(void)
{
	int array[] = {5, 3, 8, 4, 2};

	size_t n = sizeof(array) / sizeof(array[0]);

	bubble_sort(array, n);
	return (0);
}
