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
	for (int i = n - 1; i != indmn; i--)
	{
		x[i] = x[i - 1];
	}
	x[indmn] = 9999;
	for (int i = 0; i < n; i++)
	{
		cout << x[i] << " ";
	}
}