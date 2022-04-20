/*
1.	Дано целое число. Определить количество делителей числа.
2.	Дан линейный однонаправленный список. Сформировать новый список, записав него четные числа, но в обратном порядке, по отношению к их расположению в исходном.
*/

#include <iostream>
using namespace std;

int cnt = 0;

void cnt_of_del(int number, int del)
{
    if (number % (del - 1) == 0 and del - 1 > 1)
    {
        //cout << del - 1 << "\n";
        cnt++;
        cnt_of_del(number, del - 1);
    }
    else if (del - 1 > 1)
    {
        cnt_of_del(number, del - 1);
    }
    else if (del - 1 == 1)
        return;
}

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Введите число: ";
    int number;
    cin >> number;
    cnt_of_del(number, number);
    cout << "Количество делителей: " << cnt;
}
