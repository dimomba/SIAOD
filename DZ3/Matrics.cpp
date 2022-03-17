/*#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	double A[3][4] = { {5,2,0,10},
					   {3,5,2, 5},
					   {20,0,0,0} };
	double B[4][2] = { {1.2, 0.5},
					   {2.8, 0.4},
					   {5, 1},
					   {2, 1.5} };
	double C[3][2] = { {0, 0},
					   {0, 0},
					   {0, 0} };
	for (int i = 0; i < 2; i++) 
	{
		for (int j = 0; j < 3; j++) 
		{
			for (int k = 0; k < 4; k++) 
			{
				C[j][i] += A[j][k] * B[k][i];
			}
		}
	}
	double mx = 0;
	double mn = 9999;
	double vyg, vyr = 0;
	int maxprod = 0;
	int minprod = 0;
	for (int i = 0; i <= 2; i++) 
	{
		for (int j = 0; j < 1; j++) 
		{
			vyg = C[i][j];
			vyr += vyg;
			if (vyg > mx) 
			{
				mx = vyg;
				maxprod = i + 1;
			}
			else if (vyg < mn) 
			{
				mn = vyg;
				minprod = i + 1;
			}
		}
	}
	cout << "Больше всего выручил денег с продажи продавец " << maxprod << endl;
	cout << "Меньше всего выручил денег с продажи продавец " << minprod << endl;
	int maxcom = 0;
	int mincom = 0;
	double downcom = 9999;
	double upcom = 0;
	double com = 0;
	for (int i = 0; i <= 2; i++) 
	{
		for (int j = 1; j < 2; j++) 
		{
			com += C[i][j];
			if (C[i][j] > upcom) 
			{
				upcom = C[i][j];
				maxcom = i + 1;
			}
			else if (C[i][j] < downcom) 
			{
				downcom = C[i][j];
				mincom = i + 1;
			}
		}
	}
	cout << "Наибольшие комиссионные у продавца " << maxcom << endl;
	cout << "Наименьшие комиссионные у продавца " << mincom << endl;
	cout << "Oбщая сумма денег, вырученных за проданные товары, равна " << vyr << endl;
	cout << "Oбщая сумма комиссионных равна " << com << endl;
	cout << "Oбщая сумма денег, прошедших через руки продавцов, равна " << vyr + com << endl;
}*/