#include "sort.h"
#include <stdio.h>

/**
* swap - Échange deux éléments dans un tableau et affiche le tableau.
* @array: Le tableau où l'échange se produit.
* @i: L'index du premier élément.
* @j: L'index du deuxième élément.
* @size: La taille du tableau.
*/
void swap(int *array, int i, int j, size_t size)
{
	int temp = array[i];

	array[i] = array[j];
	array[j] = temp;
	print_array(array, size);
}

/**
* lomuto_partition - Partitionne le tableau avec le schéma de Lomuto.
* @array: Le tableau à partitionner.
* @low: L'index de départ.
* @high: L'index de fin.
* @size: La taille du tableau.
*
* Return: L'index du pivot après partitionnement.
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];

	int i = low - 1;

	for (int j = low; j < high; j++)

	{
		if (array[j] < pivot)
		{
			i++;
			swap(array, i, j, size);
		}
	}
	swap(array, i + 1, high, size);
	return (i + 1);
}

/**
* quick_sort_recursive - Trie récursivement le tableau.
* @array: Le tableau à trier.
* @low: L'index de départ.
* @high: L'index de fin.
* @size: La taille du tableau.
*/
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
* quick_sort - Trie un tableau d'entiers par ordre croissant.
* @array: Le tableau à trier.
* @size: La taille du tableau.
*/
void quick_sort(int *array, size_t size)
{
	if (array != NULL && size > 1)
		quick_sort_recursive(array, 0, size - 1, size);
}
