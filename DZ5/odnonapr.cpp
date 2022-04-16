/*
1)	Даны два списка с головным элементом. Головной элемент не является узлом списка, а это структура, которая хранит информацию о списке: количество узлов в списке, указатель на вершину (на первый узел) списка.
2)	Разработать функцию вставки нового узла в начало списка.
3)	Разработать функцию удаления узла из начала списка.
4)	Сравнить два списка на равенство, т.е. их длины равны и значения в соответствующих по номеру узлах равны).
*/

#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node(int _val) : val(_val), next(nullptr) {}
};

struct list 
{
    int len = 0;
    Node* first;
    Node* last;

    list() : first(nullptr), last(nullptr) {}

    bool is_empty()
    {
        return first == nullptr;
    }

    void push_back(int _val)
    {
        Node* p = new Node(_val);
        if (is_empty())
        {
            first = p;
            last = p;
            len += 1;
            return;
        }
        last->next = p;
        last = p;
        len += 1;
    }

    void print() 
    {
        if (is_empty()) return;
        Node* p = first;
        while (p)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }

    void remove_first() //удаление первого узла из списка
    {
        if (is_empty()) return;
        Node* p = first;
        first = p->next;
        delete p;
    }

    Node* operator[] (const int index)
    {
        if (is_empty()) return nullptr;
        Node* p = first;
        for (int i = 0; i < index; i++)
        {
            p = p->next;
            if (!p) return nullptr;
        }
        return p;
    }
};

void add_on_first_place(list L) //добавление узла в начало списка
{
    cout << "Какое значение элемента нужно вставить в начало списка? ";
    int _val;
    cin >> _val;
    for (int i = L.len; i > 0; i--)
    {
        if (i == L.len)
            L.push_back(9999);
        L[i]->val = L[i - 1]->val;
    }
    L[0]->val = _val;
    L.len += 1;
};

bool equivalence(list L1, list L2) //проверка на равенстов списков
{
    if (L1.len != L2.len)
    {
        cout << "Списки не равны";
        return false;
    }
    else
    {
        for (int i = 0; i < L1.len; i++)
        {
            if (L1[i]->val != L2[i]->val)
            {
                cout << "Списки не равны";
                return false;
            }
        }
        cout << "Списки равны";
        return true;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");

    list L1, L2;
    int len1, len2;

    cout << "Введите количество элементов в списке L1: ";
    cin >> len1;
    cout << "Введите " << len1 << " значений элементов списка L1:" << endl;
    int elem;
    for (int i = 0; i < len1; i++) 
    {
        cin >> elem;
        L1.push_back(elem);
    }
    L1.print();

    cout << "Введите количество элементов в списке L2: ";
    cin >> len2;
    cout << "Введите " << len2 << " значений элементов списка L2:" << endl;
    for (int i = 0; i < len2; i++)
    {
        cin >> elem;
        L2.push_back(elem);
    }
    L2.print();

    add_on_first_place(L1); //добавление узла в начало списка L1
    L1.print();

    L1.remove_first(); //удаление первого узла из списка L1
    L1.print();

    equivalence(L1, L2); //проверка на равенстов списков
}
