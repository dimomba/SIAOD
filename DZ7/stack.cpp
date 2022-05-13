/*Массив. Инфиксная -> Постфиксная запись*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

bool is_operation(char x)
{
    return (x == '+' or x == '-' or x == '*' or x == '/');
}

bool prioritet(char x, vector <char> stack)
{
    return ((stack.back() == '-' or stack.back() == '+') and (x == '*' or x == '/'));
}

void izvlech(vector <char>& st, string& postfix, char x)
{
    if (x == '+' or x == '-')
    {
        while (st.back() != '(')
        {
            postfix += st.back();
            st.pop_back();
            if (st.empty())
                break;
        }
        st.push_back(x);
    }
    else
    {
        while (st.back() != '(')
        {
            postfix += st.back();
            st.pop_back();
            if (st.back() == '-' or st.back() == '+')
                break;
        }
        st.push_back(x);
    }
}

void izvlech_in_postf(vector <char>& st, string& postf)
{
    while (st.back() != '(')
    {
        postf += st.back();
        st.pop_back();
    }
    st.pop_back();
}

string transform(string inf)
{
    vector <char> st;
    string postf = "";
    char a;
    int i = 0;
    while (inf.size() > i)
    {
        a = inf[i];
        if (a == ' ')
        {
            inf.erase(0, 1);
            continue;
        }
        if (is_operation(a))
        {
            if (st.size() == 0 or st.back() == '(')
            {
                st.push_back(a);
            }
            else if (prioritet(a, st))
            {
                st.push_back(a);
            }
            else
            {
                izvlech(st, postf, a);
            }
        }
        else if (a == '(')
        {
            st.push_back(a);
        }
        else if (a == ')')
        {
            izvlech_in_postf(st, postf);
        }
        else
        {
            postf += a;
        }
        i += 1;
    }
    while (st.size() != 0)
    {
        postf += st.back();
        st.pop_back();
    }
    return postf;
}
 
int main()
{
    string v;
    v = "a + (b - c * k) / (d * e - f)";
    cout << transform(v);
    return 0;
}
