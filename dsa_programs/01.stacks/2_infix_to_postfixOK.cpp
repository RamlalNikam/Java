#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;
class Postfix
{
public:
    char e[100], o[100], i[100]; // e=>for stack , o=>to store output , i=>to store input.
    int top, poso, posi, len;    /*top=>top of stack, poso=>position of output,
        posi=>position of input, len=>length of input */

public:
    int check() // useles function
    {
        if (top >= 0)
            return 1;
        else if (top == -1)
            return 0;
        else
            return 0;
    }
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
        o[poso] = x;
        poso++;
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
            if ((item >= 'a' && item <= 'z') || (item >= 'A' && item <= 'Z'))
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
int main()
{
    Postfix p;
    fstream file;
    // this will open file
    file.open("infixData.txt", ios::in);

    p.setTop();         // it will set top=-1,poso(i.e.position of output)=0,posi(i.e.position of input)=0.
    p.getInfix();       // it will accept the infix expression.
    p.infixToPostfix(); // it is the main function will perform the action of conversion fron infix to postfix.

    // to copy the data into the file.
    if (!file)
        cout << "\nFile Creation faled.\n";
    else
    {
        cout << "\nNew file created.\n";
        file << p.o;
        file.close();
    }

    return 0;
}