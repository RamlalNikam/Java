/*OPERATIONS ON LINKED LIST:
    1.TRAVERSAL OF A LINKED LIST.
    2.INSERT AT HEAD & TAIL.
    3.SUM OF ALL ELEMENTS IN A LINKED LIST.
    4.SUM OF ALL ODD AND EVEN ELEMENTS IN A LINKED LIST.
    5.COUNTING NO. OF NODES IN A LINKED LIST.
    6.COUNTING NO. OF EVEN AND ODD ELEMENTS IN A LINKED LIST.
*/
#include <iostream>
#include <string.h>
using namespace std;
// This Class is for String Data.
class Node
{
public:
    string data;
    Node *link;
    Node(string data)
    {
        this->data = data;
        link = NULL;
    }
};
// This will make a node and insert it to the head.
void insertAtHead(Node *&head, string x)
{
    Node *n2 = new Node(x); // Getting a new node from free pool of storage and inserting data into it with the help of constructor.
    n2->link = head->link;  // This will insert the address of first node into the link part of new node(n2).
    head->link = n2;        // This will move head pointer to the new node and now your 1st node will be the new node(n2).
}
// This will make a node and insert it to the tail.
void insertAtTail(Node *tail, string x1)
{
    Node *n3 = new Node(x1);  // Getting a new node from free pool of storage and inserting data into it with the help of constructor.
    Node *ptr = tail;         // This will start from the header node.
    while (ptr->link != NULL) // This will contnue iterating untile it gets NULL in the link part of the last node.
        ptr = ptr->link;
    ptr->link = n3;  // This will insert the address of new node into the exesting previous node.
    n3->link = NULL; // This will insert NULL at the end of the last node.
}
// To print all nodes of linked list.
void printNode(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << "| " << ptr->data << " | "; // This will print data to the curient node.
        ptr = ptr->link;                    // As link is having the address of the next node so it wil jump to the next node.
        cout << " " << &ptr->link << " | "
             << " -> "; // This will print the address of the next node.
    }
    cout << "NULL" << endl;
}

// This class is for INTEGER data.
class NodeInt
{
public:
    int data;
    NodeInt *link;
    NodeInt(int data)
    {
        this->data = data;
        link = NULL;
    }
};
// This function is used to insert node from head into a linked list.
void insertAtHeadInt(NodeInt *&head, int x)
{
    NodeInt *n2 = new NodeInt(x);
    n2->link = head->link;
    head->link = n2;
}
// This function is used to insert node from tail into a linked list.
void insertAtTailInt(NodeInt *&tail, int item)
{
    NodeInt *n3 = new NodeInt(item);
    NodeInt *ptr = tail;
    while (ptr->link != NULL)
        ptr = ptr->link;
    ptr->link = n3;
    n3->link = NULL;
}
void insertAtAnyInt(NodeInt *&head, int x, int key)
{
    NodeInt *n4 = new NodeInt(x);
    NodeInt *ptr = head;
    while ((ptr->data != key) && (ptr->link != NULL))
        ptr = ptr->link;
    if (ptr->link == NULL)
        cout << endl
             << "Key is not available in the list." << endl;
    else
    {
        n4->link = ptr->link;
        ptr->link = n4;
        cout << endl
             << "\t\tDATA INSERTED\n"
             << endl;
    }
}
// This function is used to print all nodes of a linked list.
void printNodeInt(NodeInt *head)
{
    NodeInt *ptr = head;
    while (ptr != NULL)
    {
        cout << "  | " << ptr->data << " | ";
        ptr = ptr->link;
        cout << &ptr->link << " |  ->";
    }
    cout << "NULL";
}
// This function is used to find sum of data present into linked list.
void sumOfLinkedList(NodeInt *head)
{
    NodeInt *ptr = head;
    int temp = 0;
    while (ptr != NULL)
    {
        temp = temp + ptr->data;
        ptr = ptr->link;
    }
    cout << endl
         << "Sum of data of your linked list is : " << temp << endl;
}
// This function is used to count number of nodes in a linked list.
void countNodes(NodeInt *head)
{
    NodeInt *ptr = head;
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->link;
    }
    cout << endl
         << "Number of NODES in Curient Linked list are(including HEADER NODE): " << count << endl;
    cout << endl
         << "Number of NODES in Curient Linked list are(excluding HEADER NODE): " << count - 1 << endl;
}
// This function is used to count number of even and odd elements of a linked list.
void countEvenOdd(NodeInt *head)
{
    NodeInt *ptr = head;
    int count_even = 0;
    int count_odd = 0;
    while (ptr != NULL)
    {
        if (ptr->data % 2 == 0)
            count_even++;
        else
            count_odd++;
        ptr = ptr->link;
    }
    cout << endl
         << "\nNumber of EVEN elements(excluding Header i.e. 0) in Linked List: " << count_even - 1 << "\nNumber of ODD elements in Linked List: " << count_odd << endl;
}
// This function is used to get sum of even and odd elements of linked list.
void sumEvenOdd(NodeInt *head)
{
    NodeInt *ptr = head;
    int sum_even = 0;
    int sum_odd = 0;
    while (ptr != NULL)
    {
        if (ptr->data % 2 == 0)
            sum_even = sum_even + ptr->data;
        else
            sum_odd = sum_odd + ptr->data;
        ptr = ptr->link;
    }
    cout << endl
         << "\nSUM of ALL EVEN data of linked list: " << sum_even << endl;
    cout << endl
         << "\nSUM of ALL ODD data of linked list: " << sum_odd << endl
         << endl;
}
int main()
{
    // Declaration Part:
    // Objects of Class:
    Node *n1 = new Node("Header");
    Node *header = n1;
    Node *tail = n1;
    NodeInt *m1 = new NodeInt(0);
    NodeInt *headerInt = m1;
    NodeInt *tailInt = m1;
    // Variables:
    string d;
    int n_intNodes, n_nodes, n_switch, n1_switch, int_data;
// Logical Part:
goBack:
    cout << "\nPlease ENTER your choise:\n\t1.Play with INTEGERS.\n\t2.Play with CHARACTERS.\n\t3.To Exit.\nChoise: ";
    cin >> n1_switch;
    switch (n1_switch)
    {
    case 1:
    mistake1:

        cout << "\n\nPlease ENTER your Choise:\n\t->'1'to insert a node from TAIL.\n\t->'2' to insert a node from HEAD.\n\t->'3'to get SUM of data of all Nodes.\n\t->'4'to count NUMBER OF NODES.\n\t->'5' to count NUMBER of EVEN ELEMENTS and NUMBER of ODD ELEMENTS\n\t->'6' to get SUM OF EVEN and ODD elements \n\t->'Ctrl + C' to Exit\n\t8.To Go Back";
        cout << endl
             << "Choise: ";
        cin >> n1_switch;

        switch (n1_switch)
        {
        case 1:
            cout << "Enter nunber of nodes you want : ";
            cin >> n_intNodes;
            cout << "Enter data of all nodes: " << endl;
            for (int i = 0; i < n_intNodes; i++)
            {
                cout << "Data: ";
                cin >> int_data;
                insertAtTailInt(tailInt, int_data);
            }
            cout << endl
                 << "Your all Nodes of linked list are: " << endl
                 << endl;
            printNodeInt(headerInt);
            goto mistake1;
        case 2:
            cout << "Enter nunber of nodes you want : ";
            cin >> n_intNodes;
            cout << "Enter data of all nodes: " << endl;
            for (int i = 0; i < n_intNodes; i++)
            {
                cout << "Data: ";
                cin >> int_data;
                insertAtHeadInt(headerInt, int_data);
            }
            cout << endl
                 << "Your all Nodes of linked list are: " << endl
                 << endl;
            printNodeInt(headerInt);
            goto mistake1;
        case 3:
            sumOfLinkedList(headerInt);
            goto mistake1;
        case 4:
            countNodes(headerInt);
            goto mistake1;
        case 5:
            countEvenOdd(headerInt);
            goto mistake1;
        case 6:
            sumEvenOdd(headerInt);
            goto mistake1;
        case 8:
            goto goBack;
        case 7:
            break;
        }
    case 2:
    mistake:

        cout << "Please ENTER your Choise:\n\t->'1'to insert a node from TAIL.\n\t->'2'to insert a node from HEAD.\n\t->'Ctrl + C'to Exit.\n\t->'4'to Go Back.";
        cout << endl
             << "Choise: ";
        cin >> n_switch;

        switch (n_switch)
        {
        case 1:
            cout << "Enter nunber of nodes you want : ";
            cin >> n_nodes;
            cout << "Enter data of all nodes: " << endl; // This will insert the data from TAIL into the linked list.
            cin.ignore();
            for (int i = 0; i < n_nodes; i++)
            {
                cout << "Data: ";
                getline(cin, d);
                insertAtTail(header, d); // This is the main function which will make a node and insert it to the tail.
            }
            cout << endl
                 << "Your all Nodes of linked list are: " << endl
                 << endl;
            printNode(header); // This function will print the hole linked list.
            goto mistake;
        case 2:
            cout << "Enter nunber of nodes you want : ";
            cin >> n_nodes;
            cout << "Enter data of all nodes: " << endl; // This will insert the data from HEAD into the linked list.
            cin.ignore();
            for (int i = 0; i < n_nodes; i++)
            {
                cout << "Data: ";
                getline(cin, d);
                insertAtHead(header, d); // This is the main function which will make a node and insert it to the head.
            }
            cout << endl
                 << "Your all Nodes of linked list are: " << endl
                 << endl;
            printNode(header); // This function will print the hole linked list.
            goto mistake;
        case 4:
            goto goBack;
        default:
            cout << "Entered a wrong Choise.\n\tPlease enter a Correct Choise.\n"
                 << endl;
            goto mistake;
            break;
        }
    case 3:
        break;
    default:
        cout << "Entered WRONG CHOISE \n\tPlease Enter a CORRECT CHOISE.\n";
    }
}