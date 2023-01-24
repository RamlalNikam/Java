#include <iostream>
using namespace std;
class Stacks
{
public:
    int size, top;
    int a[5];
    void fix_size_top()
    {
        size = 4;
        top = -1;
        a[0] = 0;
        a[1] = 0;
        a[2] = 0;
        a[3] = 0;
        a[4] = 0;
    }
    void push_a(int item)
    {
        if (top >= size)
            cout << "\nSTACK is full i.e. OVERFLOW";
        else
        {
            top = top + 1;
            a[top] = item;
        }
    }
    void pop_a()
    {
        if (top < 0)
            cout << "\nSTACK is empty i.e. underflow.";
        else
        {
            int item = a[top];
            a[top]=0;
            top = top - 1;
        }
        cout << "\nPoping Done.";
    }
    void status_a()
    {
        int free;
        for (int i = 4; i >= 0; i--)
        {
            cout << "\n|" << a[i] << "|";
        }
        cout << "\nThe element of top is " << a[top];
        free = (size - top) / size * 100;
        cout << "\nPercentage of free stack is " << free;
    }
};
int main()
{
    Stacks s;
    int elemnt;
    int choise;
    s.fix_size_top();
    do
    {
        cout << "\n1.Push an element into stack.\n2.Pop an element from stack.\n3.Check Status of your stack.\n4.Exit";
        cout << "\nEnter Your Choise: ";
        cin >> choise;
        switch (choise)
        {
        case 1:
            cout << "\nEnter the Element to PUSH: ";
            cin >> elemnt;
            s.push_a(elemnt);
            s.status_a();
            break;
        case 2:
            s.pop_a();
            s.status_a();
        }
    } while (choise != 4);

    return 0;
}