//Поиск Фибоначчи
//Регистрация земельного участка в СНТ: кадастровый номер – семизначное число, адрес СНТ

#include <iostream>
#include <string>
#include <random>
#include <ctime>
using namespace std;

struct Location
{
    int cad = 0;
    string adres;
};

void stuff(Location* areas, int n)
{
    for (int i = 0; i < n; i++)
    {
        areas[i].cad = rand() % 9000001 + 1000000;
        areas[i].adres = to_string(i + 1);
    }
}

void brute(Location* areas, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (areas[i].cad == x)
            cout << "Найден элемент с кадастровым номером " << x << ". Адрес: " << areas[i].adres;
    }
}

void barrier(Location* areas, int n, int x)
{
    Location last = areas[n - 1];
    areas[n - 1].cad = x;
    int i = 0;
    for (i; areas[i].cad != x; ++i);
    areas[n - 1] = last;
    if (i != (n - 1) or x == last.cad)
        cout << "Найден элемент с кадастровым номером " << x << ". Адрес: " << areas[i].adres;
    else
        cout << "Элемент не найден";
}

void fib(Location* areas, int n, int x)
{
    int fib1 = 0;
    int fib2 = 1;
    int fibM = fib1 + fib2;
    while (fibM < n)
    {
        fib1 = fib2;
        fib2 = fibM;
        fibM = fib2 + fib1;
    }
    int a = -1;
    while (fibM > 1)
    {
        int i = min(a + fib1, n - 1);
        if (areas[i].cad < x)
        {
            fibM = fib2;
            fib2 = fib1;
            fib1 = fibM - fib2;
            a = i;
        }
        else if (areas[i].cad > x)
        {
            fibM = fib1;
            fib2 = fib2 - fib1;
            fib1 = fibM - fib2;
        }
        else
        {
            cout << "Найден элемент с кадастровым номером " << x << ". Адрес: " << i;
            return;
        }
    }
    if (fib1 and areas[a + 1].cad == x)
    {
        cout << "Найден элемент с кадастровым номером " << x << ". Адрес: " << a + 1;
        return;
    }
    cout << "Элемент не найден";
    return;
}

int main()
{
    setlocale(LC_ALL, "ru");
    Location* areas;
    int n;
    cin >> n;
    areas = new Location[n];
    stuff(areas, n);
    for (int i = 0; i < n; i++)
         cout << areas[i].adres << " " << areas[i].cad << endl;
    int cad = 1026500;
    brute(areas, n, cad);
    //barrier(areas, n, cad);
    //fib(areas, n, cad);
}
