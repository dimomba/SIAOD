#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int p, o;
	cout << "������� ������� �������: ";
	cin >> p;
	int** x = new int * [p];
	for (int i = 0;i < p;i++)
		x[i] = new int[p];
	cout << "��� ��������� ������: � ���������� (1) ��� �������� (2)?" << endl;
	cin >> o;
	switch (o) //���������� �������
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

	cout << "����������� ������:" << endl; //����� ������������ �������
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < p; j++)
			cout << x[i][j] << " ";
		cout << endl;
	}

	int k = 0;
	cout << "�����(-�) �����, �������� ������ �� ������� �������� ���������� ������������������:" << endl;
	for (int i = 0; i < p; i++) //����� ������� �����, ��������������� �������
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