#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	const int Len = 100;
	int x[Len], n;
	cout << "������� ���������� �������������� ��������� �������: ";
	cin >> n;
	if (n > 0 && n < Len)
	{
		cout << "������� " << n << " �����" << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> x[i];
		}
	}
	else
		cout << "n ������ ���� ������ ����";
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
			c += 1;
			for (int k = i; k < n - c; k++)
			{
				x[k] = x[k + 1];
				x[k + 1] = 10000;
			}
		}
	}
	for (int i = 0; i < n - c; i++)
	{
		cout << x[i] << " ";
	}
}