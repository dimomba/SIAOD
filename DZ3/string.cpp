#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

int transform(string s, int l) //перевод из 16-ричной в 10-чную
{
    int sm = 0;
    for (int i = l - 1; i >= 0; i = i - 1)
    {
        if (int(s[l - i - 1]) < 65)
            sm += (int(s[l - i - 1]) - 48) * (pow(16, i));
        else
            sm += (int(s[l - i - 1]) - 55) * (pow(16, i));
    }
    return sm;
}

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string str;
    string a[10]{};
    cout << "Введите предложение:" << endl;
    getline(cin, str);
    int k = -1;
    int* razm = new int[10];
    int len = str.length();
    for (int i = 0; i < len - 1; i++)
    {
        if (str[i] == '$')
        {
            str[i] = '~';
            k += 1;
            razm[k] = 0;
            int j = i + 1;
            while (str[j] != ' ' and j < len)
            {
                a[k] += str[j];
                str[j] = '~';
                razm[k] += 1;
                j += 1;
            }
            if (str[j] == ' ')
            {
                str[j] = '~';
            }
        }
    }
    int* arr = new int[k + 1]{};
    for (int i = 0; i <= k; i++)
        arr[i] = transform(a[i], razm[i]);
    cout << "Массив из десятичных значений шестнадцатеричных чисел:" << endl;
    for (int i = 0; i <= k; i++)
        cout << arr[i] << ' ';
    string newstr[100];
    int p = 0;
    for (int i = 0; i < len; i++)
        if (str[i] != '~')
        {
            newstr[p] = str[i];
            p += 1;
        }
    cout << "\nПредложение без шестнадцатеричных чисел:" << endl;
    for (int i = 0; i < p; i++)
        cout << newstr[i];
}
