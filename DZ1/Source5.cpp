#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	int n;
	cout << "¬ведите количество обрабатываемых элементов массива: ";
	cin >> n;
	int* x = new int[n];
	if (n > 0)
	{
		cout << "¬ведите " << n << " чисел" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> x[i];
		}
	}
	else
		cout << "n должно быть больше нул€";
	int c = 0;
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
		{
			x[i] = 10000;
			//c += 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (x[i] != 10000)
		{
			cout << x[i] << " ";
		}
	}
}