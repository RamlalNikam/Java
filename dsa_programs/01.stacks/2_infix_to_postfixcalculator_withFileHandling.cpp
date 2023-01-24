#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
using namespace std;
class Postfix
{
public:
    char e[100], i[100];      // e=>for stack , i=>to store input.
    string o;                 // o=>to store output.
    int top, poso, posi, len; /*top=>top of stack, poso=>position of output,
     posi=>position of input, len=>length of input */

public:
    void setTop()
    {
        top = -1;
        poso = 0;
        posi = 0;
    }
    void push(char x)
    {
        top = top + 1;
        e[top] = x;
    }
    char pop()
    {
        char elem;
        elem = e[top];
        top = top - 1;
        return elem;
    }
    char readSymbol() // this function will read the character one by one.
    {
        char x;
        x = i[posi];
        posi++;
        return x;
    }
    void output(char x) // this function will store the output.
    {
        o += x;
    }
    int priority(char ch) // it will set the priority of the character.
    {
        if (ch == '+' || ch == '-')
            return 1;
        else if (ch == '*' || ch == '/')
            return 2;
        else if (ch == '^')
            return 3;
        else
            return 0;
    }
    void getInfix()
    {
        cout << "Enter INFIX Expression : ";
        cin >> i;
        len = strlen(i);
        i[len] = ')';
        cout << endl
             << i;
    }
    void infixToPostfix()
    {
        char item;
        char x;
        push('(');
        do
        {
            item = readSymbol();
            x = pop();
            if (((item >= 'a' && item <= 'z') || (item >= 'A' && item <= 'Z')) || (item >= '0' && item <= '9'))
            {
                push(x);
                output(item);
            }
            else if (item == '(')
            {
                push(x);
                push(item);
            }
            else if (item == ')')
            {
                do
                {
                    output(x);
                    x = pop();
                } while (x != '(');
            }
            else if (priority(x) >= priority(item))
            {
                do
                {
                    output(x);
                    x = pop();
                } while (priority(x) >= priority(item));
                push(x);
                push(item);
            }
            else if (priority(x) < priority(item))
            {
                push(x);
                push(item);
            }
            else
                printf("Invalid Expression");
        } while (top > -1);
        cout << "\nYour postfix expression is : " << o << endl;
    }
};
class Evaluaton_Of_Postfix
{
public:
    int size, posi,ans;
    int top;
    float a[30];
    char str[40];
    int len;
    void getExpression(string s)
    {
        strcpy(str, s.c_str());
        // cout << "Enter the expression: ";
        // cin >> s;
        len = strlen(str);
        size = len;
        str[len] = '#';
        cout << endl
             << str << endl;

        // return s;
    }
    Evaluaton_Of_Postfix()
    {
        // size = len;
        top = -1;
        posi = 0;
    }
    void push_a(float item)
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
        {
            cout << "\nSTACK is empty i.e. underflow.";
            return 0;
        }
        else
        {
            float item = a[top];
            top = top - 1;
            return item; // return a[top];
        }
        // cout << "\nPoping Done.";
    }
    char readSymbol()
    {
        char x;
        x = str[posi];
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
                push_a(item - '0');
            else
            {
                float y = pop_a();
                float x = pop_a();
                float t;
                switch (item)
                {
                case '+':
                    // t = x + y;
                    push_a(x + y);
                    break;
                case '-':
                    t = (float)x - y;
                    push_a(t);
                    break;
                case '*':
                    t = (float)x * y;
                    push_a(t);
                    break;
                case '/':
                    t = (float)x / y;
                    push_a(t);
                    break;
                case '^':
                    t = pow(y, x);
                    push_a(t);
                    break;
                }
                // status_a();
            }
            item = readSymbol();
        }
        ans=pop_a();
        cout << "\nYour answer is : " << ans << endl;
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
    ofstream fout("infix_to_postfix.txt");
    Postfix p;
    Evaluaton_Of_Postfix e;
    p.setTop();
    p.getInfix();
    p.infixToPostfix();
    e.getExpression(p.o);
    e.postfix();
    fout<<"The answer of "<<p.i<<": "<<e.ans;

    return 0;
}