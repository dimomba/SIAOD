#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int p, o;
	cout << "¬ведите пор€док матрицы: ";
	cin >> p;
	int** x = new int * [p];
	for (int i = 0;i < p;i++)
		x[i] = new int[p];
	cout << " ак заполнить массив: с клавиатуры (1) или рандомно (2)?" << endl;
	cin >> o;
	switch (o) //заполнение массива
	{
	case 1:
		cout << "¬ведите элементы массива: " << endl;
		for (int i = 0; i < p; i++)
		{
			for (int j = 0; j < p; j++)
				cin >> x[i][j];
		}
		break;
	case 2:
		for (int i = 0; i < p; i++)
		{
			for (int j = 0; j < p; j++)
				x[i][j] = rand() % 100;
		}
		break;
	}

	cout << "»значальный массив:" << endl; //вывод заполненного массива
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < p; j++)
			cout << x[i][j] << " ";
		cout << endl;
	}

	int k = 0;
	cout << "Ќомер(-а) строк, элементы каждой из которых образуют монотонную последовательность:" << endl;
	for (int i = 0; i < p; i++) //поиск номеров строк, удовлетвор€ющих условию
	{
		int fl1 = 1;
		for (int j = 0; j < p - 1; j++)
		{
			if (x[i][j] < x[i][j + 1])
				fl1 = 1;
			else
			{
				fl1 = 0;
				break;
			}
		}
		int fl2 = 1;
		for (int j = 0; j < p - 1; j++)
		{
			if (x[i][j] > x[i][j + 1])
				fl2 = 1;
			else
			{
				fl2 = 0;
				break;
			}
		}
		if (fl1 + fl2 == 1)
		{
			k += 1;
			cout << i + 1 << endl;
		}
	}
	if (k == 0)
		cout << "“аких строк нет";
}