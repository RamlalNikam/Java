// Program to insert and deleat an element in a queqe.
#include <iostream>
using namespace std;
class Queue
{
public:
    int rear, front, que[5], no, choise, elem;
    Queue()
    {
        no = 4;
        rear = -1;
        front = -1;
    }
    void getData()
    {
        while (choise != 3)
        {

            cout << "Enter your choise from the geven options:\n1.Insert the element into QUEUE.\n2.Delet the element from the QUEUE.\n3.To Exit.\nYour Choise: ";
            cin >> choise;
            switch (choise)
            {
            case 1:
                cout << "Enter the element to insert : ";
                cin >> elem;
                insertQue(elem);
                break;
            case 2:
                deletQue();
                break;
            // default:
            //     cout << "YOU HAD ENTERED A WRONG CHOISE.";
            //     break;
            }
            if(choise>3)
            cout<<"\nYou had entered Wrong Choise."<<endl;
        }
    }
    void insertQue(int item)
    {
        if (rear == no)
            cout << "\n-------------------------------------\nQueue is full i.e. OVERFLOW\n-------------------------------------"<<endl;
        else
        {
            if ((rear == -1) && (front == -1))
                front = 0;
            rear = rear + 1;
            que[rear] = item;
            cout<<"\n-------------------------------------\nRear: "<<rear+1<<"\tFront: "<<front+1<<"\n-------------------------------------"<<endl;
            cout << "\nItem inserted at position " << rear + 1 << " the ITEM is " << que[rear] << endl;
            cout << "____________________________________________________" << endl;
        }
    }
    void deletQue()
    {
        if (front == -1)
            cout << "\n-------------------------------------\nQUEUE is empty or UNDERFLOW\n-------------------------------------"<<endl;
        else
        {
            if (front == rear)
            {
                rear = -1;
                front = -1;
            }
            else
                front = front + 1;
            cout<<"\n-------------------------------------\nRear: "<<rear+1<<"\tFront: "<<front+1<<"\n-------------------------------------"<<endl;
            cout << "\nItem deleted from position " << front + 1 << " the ITEM is " << que[front] << endl;
            cout << "____________________________________________________" << endl;
        }
    }
};
int main()
{
    Queue q;
    q.getData();
}