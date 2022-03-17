#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int main() 
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int n, o, m = 2;
	cout << "������� ���������� �����: ";
	cin >> n;
	vector < vector <int> > a(n, vector <int>(m));

	cout << "��� ���������� ����������: � ���������� (1) ��� �������� (2)?" << endl;
	cin >> o;
	switch (o)
	{
	case 1:
		cout << "������� ���������� ����� � ����: x1 y1 x2 y2..." << endl;
		for (int i = 0; i < n; i++)     // ����, ������� ��� �� �������
			for (int j = 0; j < m; j++) // ����, ������� ��� �� ���������
			{
				cin >> a[i][j]; // ���������� ������� ��� ������� (� ������ ������ ����)
			}
		break;
	case 2:
		for (int i = 0; i < n; i++)     // ����, ������� ��� �� �������
			for (int j = 0; j < m; j++) // ����, ������� ��� �� ���������
			{
				a[i][j] = rand() % 100; // ���������� ������� ��� ������� (� ������ ������ ����)
			}
		break;
	}

	cout << "The values of the vector are : \n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << a[i][j] << " ";
		cout << '\n';
	}

	int sm = 0;
	for (int i = 1; i < n; i++)
		sm += i;
	cout << "���������� ��������, � ������� ��� ����� ����������� ��������� ���������: " << sm << endl;
	
	int k = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == 0)
			{
				k += 1;
				break;
			}
	for (int i = 0; i < k; i++)
	{
		sm = sm - (n - 1 - i);
	}
	cout << "���������� ��������, � ������� �� ���� ����� �� ����� �� ���� ���������: " << sm << endl;
	
	int t = 0;
	for (int i = 0; i < n - 1; i++)
		for (int e = i + 1; e < n; e++)
		{
			int u = 0;
			if (a[i][0] * a[e][0] <= 0)
				u += 1;
			if (a[i][1] * a[e][1] <= 0)
				u += 1;
			if (u == 1)
				t += 1;
		}
	cout << "���������� ��������, ������� ������������ ����� � ����� ���� ���������:" << t;
}