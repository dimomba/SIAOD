#include <iostream>
#include <vector>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int n;
	cout << "������� ���������� �������������� ��������� �������: ";
	cin >> n;
	vector<int> x;
	if (n > 0)
	{
		cout << "������� " << n << " �����" << endl;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			x.push_back(a);
		}
	}
	else
		cout << "n ������ ���� ������ ����";
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
			cout << "������: " << i << endl;
	}
}