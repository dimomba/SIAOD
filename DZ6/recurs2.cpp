/*
1.	Дано целое число.Определить количество делителей числа.
2.	Дан линейный однонаправленный список.Сформировать новый список, записав него четные числа, но в обратном порядке, по отношению к их расположению в исходном.
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

list L2;

void making_new_list(list L, int len)
{
    if (L[len - 1]->val % 2 == 0 and len - 1 >= 0)
    {
        L2.push_back(L[len - 1]->val);
        making_new_list(L, len - 1);
    }
    else if (len - 1 >= 0)
    {
        making_new_list(L, len - 1);
    }
    else if (len - 1 == -1)
        return;
}

int main()
{
    setlocale(LC_ALL, "ru");

    list L1;
    int len1;

    cout << "Введите количество элементов в списке: ";
    cin >> len1;
    cout << "Введите " << len1 << " значений элементов списка:" << endl;
    int elem;
    for (int i = 0; i < len1; i++)
    {
        cin >> elem;
        L1.push_back(elem);
    }
    cout << "Исходный список:" << endl;
    L1.print();

    making_new_list(L1, len1);
    cout << "Новый сформированный список:" << endl;
    L2.print();
}
