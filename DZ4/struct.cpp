/*Касса магазина. Структура записи операции по кассе: номер кассы, код товара, количество товара, цена товара, процентная скидка на товар, сумма за товар с учетом скидки.
Операции
Заполнение записи по одной операции с клавиатуры.
Вставить записи по отдельной операции, проведенной кассой, в таблицу, располагая ее в начале списка других операций, проведенных этой кассой.
Вывести список операций, проведенных заданной кассой, с указанием стоимости покупки по каждой операции.
Удалить записи по операциям, проведенным определенной кассой.
*/

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Cassa
{
	float number_cass;
	float cod_tovara;
	float kolvo_tovara;
	float price;
	float discount;
	float stoimost;
};

Cassa operation()
{
	Cassa oper;
	cout << "Введите номер кассы: " << endl;
	cin >> oper.number_cass;
	cout << "Введите код товара: " << endl;
	cin >> oper.cod_tovara;
	cout << "Введите количество товара: " << endl;
	cin >> oper.kolvo_tovara;
	cout << "Введите цену товара: " << endl;
	cin >> oper.price;
	cout << "Введите размер скидки на товар (в процентах): " << endl;
	cin >> oper.discount;
	oper.stoimost = (oper.kolvo_tovara * oper.price) * (1 - oper.discount / 100);
	return oper;
}

void operation_in_tabl(Cassa operation, vector<vector<float>>& vect)
{
	vector<float> tabl(6);
	tabl[0] = operation.number_cass;
	tabl[1] = operation.cod_tovara;
	tabl[2] = operation.kolvo_tovara;
	tabl[3] = operation.price;
	tabl[4] = operation.discount;
	tabl[5] = operation.stoimost;
	bool is_added = false;
	for (int i = 0; i < vect.size(); i++)
	{
		if (vect[i][0] == tabl[0])
		{
			vect.push_back(tabl);
			for (int j = vect.size() - 1; j > i; j--)
			{
				vect[j].swap(vect[j - 1]);
			}
			vect[i] = tabl;
			is_added = true;
			break;
		}
	}
	if (is_added == false)
	{
		vect.push_back(tabl);
	}
}

void print(vector<vector<float>> vect)
{
	cout << "Номер кассы  Код товара  Количество        Цена      Скидка   Стоимость" << endl;
	for (int i = 0; i < vect.size(); i++)
	{
		for (int j = 0; j < vect[i].size(); j++)
		{
			cout << setw(11) << vect[i][j] << " ";
		}
		cout << endl;
	}
}

void oper_of_one_cassa(vector<vector<float>> vect)
{
	int n;
	cout << "Введите номер кассы, у которой нужно вывести проведенные операции: ";
	cin >> n;
	for (int i = 0; i < vect.size(); i++)
	{
		if (vect[i][0] == n)
		{
			for (int j = 0; j < vect[i].size(); j++)
			{
				cout << setw(7) << vect[i][j] << " ";
			}
			cout << endl;
		}
	}
}

void deleteoperations(vector<vector<float>>& vect)
{
	int n;
	cout << "Введите номер кассы, записи по операциям которой нужно удалить: ";
	cin >> n;
	int count_oper = 0;
	int begin = 0;
	for (int i = 0; i < vect.size(); i++)
	{
		if (vect[i][0] == n)
		{
			int j = i;
			begin = i;
			while (vect[j][0] == n and j < vect.size())
			{
				count_oper++;
				j++;
				if (j >= vect.size())
					break;
			}
			break;
		}
	}
	for (int p = begin; p < begin + count_oper; p++)
	{
		vect[p].erase(vect[p].begin(), vect[p].end());
	}
}

int main() 
{
	setlocale(LC_ALL, "ru");
	vector<vector<float>> arr;
	int n;
	cout << "Введите количество операций: " << endl;
	cin >> n;
	for (int i = 0; i < n; ++i) 
	{
		Cassa oper = operation();
		operation_in_tabl(oper, arr);
	}
	print(arr);
	oper_of_one_cassa(arr);
	deleteoperations(arr);
	cout << "Итоговая таблица: " << endl;
	print(arr);
}
