#include <iostream>
#include <vector>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int n;
	cout << "¬ведите количество обрабатываемых элементов массива: ";
	cin >> n;
	vector<int> x;
	if (n > 0)
	{
		cout << "¬ведите " << n << " чисел" << endl;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			x.push_back(a);
		}
	}
	else
		cout << "n должно быть больше нул€";
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
		}
	}
	int b = 0;
	for (int i = 0; i < n - b; i++)
	{
		if (x[i] == 10000)
		{
			b += 1;
			for (int k = i; k < n - b; k++)
			{
				x[k] = x[k + 1];
			}
			i -= 1;
			x[n - b] = 10000;
		}
	}
	for (int i = 0; i < b; i++)
	{
		x.pop_back();
	}
	for (int i = 0; i < n - b; i++)
	{
		cout << x[i] << " ";
	}
}