#include <iostream>
#include <ctime>

using namespace std;
#define Cols 10
#define Rows 10
int p;

void input(int x[][Cols])
{
	cout << "������� ������� �������: ";
	int o;
	cin >> p;
	cout << "��� ��������� ������: � ���������� (1) ��� �������� (2)?" << endl;
	cin >> o;
	switch (o)
	{
	case 1:
		cout << "������� �������� �������: " << endl;
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
}

void output(int x[][Cols])
{
	cout << "����������� ������:" << endl;
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < p; j++)
			cout << x[i][j] << " ";
		cout << endl;
	}
}

void number_monot(int x[][Cols])
{
	int k = 0;
	cout << "�����(-�) �����, �������� ������ �� ������� �������� ���������� ������������������:" << endl;
	for (int i = 0; i < p; i++)
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
		cout << "����� ����� ���";
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int x[Rows][Cols];
	input(x);
	output(x);
	number_monot(x);
}