//1) Дан код программы на языке С++. Определить, использовались ли операторы цикла в этом коде.
//2) Определить, является ли строка корректным IPv4-адресом
//Алгоритм Кнута-Мориса-Пратта

#include <iostream>
#include <string>
#include <vector>
#include <regex>
using namespace std;

vector<int> Knut_Moris_Pratt(const string& s)
{
	vector<int> pi(s.length(), 0);
	for (int i = 1; i < s.length(); i++)
	{
		int j = pi[i - 1];
		while (j > 0 and s[i] != s[j])
		{
			j = pi[j - 1];
		}
		if (s[i] == s[j])
		{
			pi[i] = j + 1;
		}
		else
		{
			pi[i] = j;
		}
	}
	return pi;
}

int isValidIp4(char* str)
{
	int segments = 0;
	int cnt = 0;
	int accum = 0;
	if (str == NULL)
		return 0;
	while (*str != '\0')
	{
		if (*str == '.')
		{
			if (cnt == 0)
				return 0;
			if (++segments == 4)
				return 0;
			cnt = 0;
			accum = 0;
			str++;
			continue;
		}
		if ((*str < '0') or (*str > '9'))
			return 0;
		if ((accum = accum * 10 + *str - '0') > 255)
			return 0;
		cnt += 1;
		str++;
	}
	if (segments != 3 or cnt == 0)
		return 0;
	return 1;
}

int main()
{
	setlocale(LC_ALL, "ru");
	
	string s, fr, whl;
	s = "jklsdfjsjkdsjd alsfdl aldfypovk; jksafjlforjhasgh";
	fr = "for";
	whl = "while";
	vector<int> pi1 = Knut_Moris_Pratt(fr + '#' + s);
	vector<int> pi2 = Knut_Moris_Pratt(whl + '#' + s);
	int fr_len = fr.length();
	int whl_len = whl.length();
	int k = 0;
	
	for (int i = 0; i < s.length(); i++)
	{
		if (pi1[fr_len + 1 + i] == fr_len or pi2[whl_len + 1 + i] == whl_len)
		{
			k += 1;
		}
	}
	if (k > 0)
		cout << "В этом коде использовались операторы цикла" << endl;
	else
		cout << "В этом коде не использовались операторы цикла" << endl;

	char st[] = "230.52.167.0.6";
	if (isValidIp4(st))
		cout << "Данная строка является корректным IPv4-адресом" << endl;
	else
		cout << "Данная строка не является корректным IPv4-адресом" << endl;
}
