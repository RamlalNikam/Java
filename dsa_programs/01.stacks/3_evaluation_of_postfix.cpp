//Evaluation of postfix  =>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
class Evaluaton_Of_Postfix
{
public:
    int size, top, posi;
    int a[30];
    char s[40];
    int len;
    void getExpression()
    {
        cout << "Enter the expression: ";
        cin >> s;
        len = strlen(s);
        s[len] = '#';
        cout << endl
             << s << endl;
        //char m='2';
    }
    Evaluaton_Of_Postfix()
    {
        size = len;
        top = -1;
        posi = 0;
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
    int pop_a()
    {
        if (top < 0)
        {    cout << "\nSTACK is empty i.e. underflow.";
            return 0;
        }
        else
        {
            int item = a[top];
            top = top - 1;
            return item;//return a[top];
        }
        // cout << "\nPoping Done.";
    }
    char readSymbol()
    {
        char x;
        x = s[posi];
        posi++;
        return x;
    }
    void postfix()
    {
        char item;
        item = readSymbol();
        while (item != '#')
        {
            if ((item >= '0' && item <= '9'))
                push_a(item-'0');
            else
            {
                int y = pop_a();
                int x = pop_a();
                int t;
                switch (item)
                {
                case '+':
                    // t = x + y;
                    push_a(x+y);
                    break;
                case '-':
                    t = x - y;
                    push_a(t);
                    break;
                case '*':
                    t = x * y;
                    push_a(t);
                    break;
                case '/':
                    t = x / y;
                    push_a(t);
                    break;
                case '^':
                    t = pow(y, x);
                    push_a(t);
                    break;
                }
                //status_a();
            }
            item=readSymbol();
        }
        cout << "\nYour answer is : " << pop_a()<<endl;
    }
    
    void status_a()
    {
        int free;
        for (int i = 8; i >= 0; i--)
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
    Evaluaton_Of_Postfix E;
    E.getExpression();
    E.postfix();
    // E.status_a();
    return 0;
}
