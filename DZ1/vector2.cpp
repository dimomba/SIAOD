#include <iostream>
#include <vector>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int n;
	cout << "Введите количество обрабатываемых элементов массива: ";
	cin >> n;
	vector<int> x;
	if (n > 0)
	{
		cout << "Введите " << n << " чисел" << endl;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			x.push_back(a);
		}
	}
	else
		cout << "n должно быть больше нуля";
	int mn = 99999;
	int indmn = 1000;
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
			if (x[i] < mn)
			{
				mn = x[i];
				indmn = i;
			}
	}
	x.push_back(x[n - 1]);
	for (int i = n - 1; i != indmn; i--)
		x[i] = x[i - 1];
	x[indmn] = 9999;
	for (int i = 0; i <= n; i++)
		cout << x[i] << " ";
}
