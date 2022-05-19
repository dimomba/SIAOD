/*1. Простого обмена (пузырек) с условием Айверсона
  2. Сортировка Шелла со смещениями Д. Кнута. Способ 1
  3. Сортировка слиянием*/


#include <iostream>
#include <ctime>
#include <random>
using namespace std;

void randomize(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = 1 + rand() % 100;
	}
}

void print(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void randomize_for_MergeSort(int* array, int size)
{
	for (int i = 1; i <= size; i++)
	{
		array[i] = 1 + rand() % 100;
	}
}

void print_for_MergeSort(int* array, int size)
{
	for (int i = 1; i <= size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

void BubbleSort(int* array, int size)
{
	int c;
	int k = 0;
	for (int i = size; i > 1; i--)
	{
		k = 0;
		for (int j = 1;j < i;j++)
			if (array[j] < array[j - 1])
			{
				c = array[j];
				array[j] = array[j - 1];
				array[j - 1] = c;
				k = 1;
			}
		if (k == 0)
			break;
	}
}

void ShellKnut(int* array, int size)
{
	int j;
	for (int step = size / 2; step > 0; step /= 2)
	{
		for (int i = step; i < size; i++)
		{
			int temp = array[i];
			for (j = i; j >= step; j -= step)
				if (temp < array[j - step])
					array[j] = array[j - step];
				else
					break;
			array[j] = temp;
		}
	}
}

oid Merge(int* array, int first, int last)
{
	int middle, start, final, j;
	int* mas = new int[100];
	middle = (first + last) / 2;
	start = first;
	final = middle + 1;
	for (j = first; j <= last; j++)
		if ((start <= middle) and ((final > last) or (array[start] < array[final])))
		{
			mas[j] = array[start];
			start++;
		}
		else
		{
			mas[j] = array[final];
			final++;
		}
	for (j = first; j <= last; j++)
		array[j] = mas[j];
}

void MergeSort(int* array, int first, int last)
{
	{
		if (first < last)
		{
			MergeSort(array, first, (first + last) / 2);
			MergeSort(array, (first + last) / 2 + 1, last);
			Merge(array, first, last);
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	int size, f, timing;
	cout << "Введите размер массива: ";
	cin >> size;
	int* array = new int[100];
	cout << "Выберите способ сортировки:\n1. Простого обмена (пузырек) с условием Айверсона\n2. Сортировка Шелла со смещениями Д. Кнута. Способ 1\n3. Сортировка слиянием\n";
	cin >> f;
	switch (f)
	{
		case 1:
			randomize(array, size);
			cout << "Исходный массив: ";
			print(array, size);
			cout << "Время: ";
      timing = clock();
			BubbleSort(array, size);
			cout << clock() - timing << endl;
			cout << "Отсортированный массив: ";
			print(array, size);
			break;
		case 2:
			randomize(array, size);
			cout << "Исходный массив: ";
			print(array, size);
			cout << "Время: ";
      timing = clock();
			ShellKnut(array, size);
			cout << clock() - timing << endl;
			cout << "Отсортированный массив: ";
			print(array, size);
			break;
    case 3:
			randomize_for_MergeSort(array, size);
			cout << "Исходный массив: ";
			print_for_MergeSort(array, size);
			cout << "Время: ";
      timing = clock();
			MergeSort(array, 1, size);
			cout << clock() - timing << endl;
			cout << "Отсортированный массив: ";
			print_for_MergeSort(array, size);
			break;
	}
}
