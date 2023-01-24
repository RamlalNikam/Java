#include <iostream>
#include <string.h>
using namespace std;
class Sort
{
public:
    int no_elem, arr[30];               // variables for array.
    int fl, el, loc;                    // variables to sort.
    int stk1[30], stk2[30], top1, top2; // array for 2 stacks and to initialize stack.
    Sort()
    {
        top1 = -1;
        top2 = -1;
        cout << "\nEnter the Number of elements you want to sort: ";
        cin >> no_elem;
        cout << "Enter elements to sort : ";
        for (int i = 0; i < no_elem; i++)
        {
            cin >> arr[i];
        }
    }

    void push(char x, char y) // push fl=>x and el=>y into stack
    {
        top1 = top1 + 1;
        top2 = top2 + 1;
        stk1[top1] = x;
        stk2[top2] = y;
    }
    int popFl()
    {
        int x;
        x = stk1[top1];
        top1 = top1 - 1;
        return x;
    }
    int popEl()
    {
        int y;
        y = stk2[top2];
        top2 = top2 - 1;
        return y;
    }
    void quickSort()
    {
        fl = 0;
        el = no_elem - 1;
        if (no_elem-1 > 1)
            push(fl, el);
        else
            cout << "You had chosen wrong array to sort."
                    "\n PLEASE ENTER ARRAY GREATER THEN 2 No.OF ELEMENTS. ";
        while (top1 != -1)
        {
            fl = popFl();
            el = popEl();
            loc = divideConcur(fl, el);
            cout << endl
                 << loc;
            if (fl <= loc - 1) // This condition is for one side of the Pivot elements.
                push(fl, loc - 1);
            else if (el >= loc + 1) // This conditon is for another side of the Pivot elements.
                push(loc + 1, el);
        }
        cout << "\n Your sorted elements are : " << endl;
        for (int i = 0; i < no_elem; i++)
        {
            cout << arr[i] << " , ";
            // if (i == no_elem-1)
            //     cout << "SORTING DONE" << endl;
        }
        cout << endl;
    }
    int divideConcur(int &lft, int &rgt)
    {
        int swp;

        loc = lft;
        while (1)
        {
            while ((loc != rgt) && (arr[loc] <= arr[rgt]))
            {
                rgt = rgt - 1;
            }
            if (loc == rgt)
                return loc;
            else
            {
                swp = arr[loc];
                arr[loc] = arr[rgt];
                arr[rgt] = swp;
                lft = loc + 1;
                loc = rgt;
            }
            while ((loc != lft) && (arr[loc] > arr[lft]))
            {
                lft = lft + 1;
            }
            if (loc == lft)
            {
                cout << "\nYour Sorted array is: " << endl;
                for (int i = 0; i < no_elem; i++)
                {
                    cout << arr[i] << " , ";
                }
                return loc;
            }
            else
            {
                swp = arr[loc];
                arr[loc] = arr[lft];
                arr[lft] = swp;
                rgt = loc - 1;
                loc = lft;
            }
        }
    }
};

int main()
{
    Sort S;

    S.quickSort();
    // int pos=S.divideConcur(0,5);
    // cout<<endl<<pos;
    return 0;
}