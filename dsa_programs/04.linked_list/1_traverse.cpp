// INSERTION OF NODES AT HEADER AND THE TAIL PART OF A LINKED LIST.
#include <iostream>
#include <string.h>
using namespace std;
class Node
{
public:
    string data;
    Node *link;
    Node(string data) // Created constructor to insert the data(string0) into the node.
    {
        this->data = data;
        link = NULL;
    }
};
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
//                              Functions to insert:
//                              ____________________
// This will make a node and insert it to the head.
void insertAtHead(Node *&head, string x)
{
    Node *n2 = new Node(x); // Getting a new node from free pool of storage and inserting data into it with the help of constructor.
    n2->link = head->link;  // This will insert the address of first node into the link part of new node(n2).
    head->link = n2;        // This will move head pointer to the new node and now your 1st node will be the new node(n2).
}
// This will make a node and insert it to the tail.
void insertAtTail(Node *head, string x)
{
    Node *n3 = new Node(x);   // Getting a new node from free pool of storage and inserting data into it with the help of constructor.
    Node *ptr = head;         // This will start from the header node.
    while (ptr->link != NULL) // This will contnue iterating untile it gets NULL in the link part of the last node.
        ptr = ptr->link;
    ptr->link = n3;  // This will insert the address of new node into the exesting previous node.
    n3->link = NULL; // This will insert NULL at the end of the last node.
}
//This will make a node and insert it to the position prior to the key element.
void insertAtAnyPos(Node *head, string x, string key)
{
    Node *n4 = new Node(x);//This will creatr a new node.
    Node *ptr = head;
    while ((ptr->data != key) && (ptr->link != NULL)) // It will scan for the data which was entered to line 114 and weather the node is the last node or not.
        ptr = ptr->link;                              // This will move ptr pointer to the next node.
    if (ptr->link == NULL)
    {
        cout << endl
             << "Key is not available in the list." << endl;
    }
    else
    {
        n4->link = ptr->link; // Now the address of its preciding node will be inserted into the new node.
        ptr->link = n4;       // and the address of new node will be inserted into the previous node.
        cout << endl
             << "\t\tDATA INSERTED" << endl;
    }
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------
//                              Functions to Print a Linked List:
//                              _________________________________
//This function will print the hole linked list.
void printNode(Node *head)
{
    Node *ptr = head;
    do
    {
        cout << "| " << ptr->data << " | "; // This will print data of the node to which ptr is pointing.
        ptr = ptr->link;                    // This will move the ptr pointer to the next node it works as i++ in for loop.
        cout << " ->   ";
    } while (ptr != NULL);
    cout << "NULL" << endl
         << endl;
}
//------------------------------------------------------------------------------------------------------------------------------
//                              Functions to perform operations on 2 Linked List:
//                              _________________________________________________
//This function will create a linked list and will mearg it to the first linked list.
void meargLinkedList(Node *&header, Node *&header1)
{
    Node *header2;
    Node *ptr = header;
    while (ptr->link != NULL)
        ptr = ptr->link;
    ptr->link = header1->link;
    delete (header1);
    header2 = header;
    printNode(header2);
}
//This function will create an empty linked list and will copy the first linked list into it.
void copyLinkedList(Node *&header, Node *&header1)
{
    Node *ptr = header->link;
    Node *ptr1 = header1;
    while (ptr != NULL)
    {
        Node *n5 = new Node(ptr->data);
        ptr1->link = n5;
        ptr1 = n5;
        ptr = ptr->link;
    }
    cout << endl
         << "\t\t\tDATA COPIED" << endl;
}
int searchLinkedList(Node *&header, string key)
{
    Node *ptr = header->link;
    int flag = 0, pos = 0;
    while ((ptr != NULL) && (flag == 0))
    {
        if (ptr->data == key)
        {
            flag = 1;
            pos = pos + 1;
            return pos;
        }
        else
            ptr = ptr->link;
    }
    if (ptr == NULL)
    {
        cout << endl
             << "Element not fount : SEARCH UNSUCCESSFUL";
    }
    else
    {
        cout << endl
             << "Node found at position: " << pos;
    }
    return 0;
}
int main()
{
    int n_nodes, n_switch;
    string d, s, inp_d, name_l1, name_l2, name_l3, search;
    Node *n1 = new Node("l1");
    Node *header = n1;
mistake:

    cout << "Please ENTER your Choise:\n\t1.To insert a node from TAIL.\n\t2.To insert a node from HEAD.\n\t3.To insert a node at any position.\n\t4.To Exit\n\t5.To create n2 linked list and mearg it into l3(from tail).\n\t6.To copy l1 linked list into l3.\n\t7.To find a particular node in l1 linked list." << endl;
    cout << endl
         << "Choise: ";
    cin >> n_switch;
    cin.ignore();
    // cout << "Enter Name of Ist linked list(or header node): ";
    // getline(cin, name_l1);
    switch (n_switch)
    {
    case 1:

        cout << "Enter nunber of nodes you want : ";
        cin >> n_nodes;
        cin.ignore();
        cout << "Enter data of all nodes: " << endl; // This will insert the data from TAIL into the linked list.
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
        cout << endl
             << "--------------------------------------------------------------------" << endl;
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
        cout << endl
             << "--------------------------------------------------------------------" << endl;
        goto mistake;
    case 3:
        cin.ignore();
        cout << endl
             << "Enter the data of new node: ";
        getline(cin, inp_d);
        cout << endl
             << "Enter the data of node after which you want to insert the node: ";
        getline(cin, s);
        insertAtAnyPos(header, inp_d, s);
        printNode(header);
        cout << endl
             << "--------------------------------------------------------------------" << endl;
        goto mistake;
    case 4:
        break;
    case 5:
    {
        Node *n2 = new Node("l2");
        Node *head1 = n2;
        cout << "Enter nunber of nodes you want : ";
        cin >> n_nodes;
        cout << endl
             << "Enter the data of the new node: ";
        cin.ignore();
        for (int i = 0; i < n_nodes; i++)
        {
            cout << "Data: ";
            getline(cin, d);
            insertAtTail(head1, d); // This is the main function which will make a node and insert it to the head.
        }
        printNode(head1);
        meargLinkedList(header, head1);
        cout << endl
             << "--------------------------------------------------------------------" << endl;
        goto mistake;
    }
    case 6:
    {
        cin.ignore();
        cout << "Enter Name of the linked list(or header node): ";
        getline(cin, name_l3);
        Node *n3 = new Node(name_l3);
        Node *head2 = n3;
        copyLinkedList(header, head2);
        cout << endl
             << "\t\tOriginal Linked List" << endl;
        printNode(header);
        cout << endl
             << "\t\tCopied Linked List" << endl;
        printNode(head2);
        cout << endl
             << "--------------------------------------------------------------------" << endl;
        goto mistake;
    }
    case 7:
    {

        cout << "Enter the data of node to search: ";
        cin.ignore();
        getline(cin, search);
        searchLinkedList(header, search);
        // if (searchLinkedList(header, search) == 0)
        //     cout << endl
        //          << "\tElement Not found." << endl;
        // else
        // {
        //     cout << endl
        //          << "Element found at node: " << searchLinkedList(header, search);
        // }
        cout << endl
             << "--------------------------------------------------------------------" << endl;
        goto mistake;
    }
    default:
        cout << "Entered a wrong Choise.\n\tPlease enter a Correct Choise.\n"
             << endl;
        goto mistake;
        break;
    }

    return 0;
}