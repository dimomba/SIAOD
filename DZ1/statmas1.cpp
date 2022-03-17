#include <iostream>
using namespace std;
void vvod(int x[], int n)
{
	if (n > 0 && n < 100)
	{
		cout << "Введите " << n << " чисел" << endl;
		for (int i = 0; i < n; i++)
			cin >> x[i];
	}
	else
		cout << "n должно быть больше нуля";
}

void vivod(int x[], int n)
{
	for (int i = 0; i < n; i++)
		cout << x[i] << " ";
}

int main()
{
	setlocale(LC_ALL, "ru");
	const int Len = 100;
	int x[Len], n;
	cout << "Введите количество обрабатываемых элементов массива: ";
	cin >> n;
	vvod(x, n);
	for (int i = 0; i < n; i++)
	{
		int sm = 0;
		int a = x[i];
		while (a != 0)
		{
			sm += a % 10;
			a /= 10;
		}
		if (sm % 7 == 0 and sm != 0)
			cout << i << endl;
	}
}
