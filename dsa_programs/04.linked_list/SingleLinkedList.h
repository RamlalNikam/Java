#include<iostream>
using namespace std;
class Node
{
public:
    Node *rlink;
    int data;
    Node *llink;
    Node() {}
    Node(int data)
    {
        this->data = data;
        this->llink = NULL;
    }
    string sdata;
    Node *link;
    Node(string sdata) // Created constructor to insert the data(string) into the node.
    {
        this->sdata = sdata;
        link = NULL;
    }
};
// This will make a node and insert it to the head.
void insertAtHead(Node *&head, int x)
{
    Node *n2 = new Node(x);  // Getting a new node from free pool of storage and inserting data into it with the help of constructor.
    n2->llink = head->llink; // This will insert the address of first node into the link part of new node(n2).
    head->llink = n2;        // This will move head pointer to the new node and now your 1st node will be the new node(n2).
}
// This will make a node and insert it to the tail.
void insertAtTail(Node *head, int x)
{
    Node *n3 = new Node(x);    // Getting a new node from free pool of storage and inserting data into it with the help of constructor.
    Node *ptr = head;          // This will start from the header node.
    while (ptr->llink != NULL) // This will contnue iterating untile it gets NULL in the link part of the last node.
        ptr = ptr->llink;
    ptr->llink = n3;  // This will insert the address of new node into the exesting previous node.
    n3->llink = NULL; // This will insert NULL at the end of the last node.
}
// This will make a node and insert it to the position prior to the key element.
void insertAtAnyPos(Node *head, int x, int key)
{
    Node *n4 = new Node(x);
    Node *ptr = head;
    while ((ptr->data != key) && (ptr->llink != NULL)) // It will scan for the data which was entered to line 114 and weather the node is the last node or not.
        ptr = ptr->llink;                              // This will move ptr pointer to the next node.
    if (ptr->llink == NULL)
    {
        cout << endl
             << "Key is not available in the list." << endl;
    }
    else
    {
        n4->llink = ptr->llink; // Now the address of its preciding node will be inserted into the new node.
        ptr->llink = n4;        // and the address of new node will be inserted into the previous node.
        cout << endl
             << "\t\tDATA INSERTED" << endl;
    }
}
// This will print Node
void printNodeInt(Node *head)
{
    Node *ptr = head;
    do
    {
        cout << "| " << ptr->data << " | "; // This will print data of the node to which ptr is pointing.
        ptr = ptr->llink;                   // This will move the ptr pointer to the next node it works as i++ in for loop.
        cout << " ->   ";                   // This will print address of the node to which ptr is pointing.
    } while (ptr != NULL);
    cout << "NULL" << endl
         << endl;
}
void deletSllFront(Node *&header)
{
    Node *ptr = header->llink;
    // Node *ptr1;
    if (ptr == NULL)
    {
        cout << "The Linked list is EMPTY: No deletion poosible.";
    }
    else
    {
        //  ptr1=ptr->link;
        header->llink = ptr->llink;
        delete (ptr);
        cout << endl
             << "Node Deleted.\n";
    }
}
// void meargLinkedList(Node *&header, Node *&header1)
// {
//     Node *header2;
//     Node *ptr = header;
//     while (ptr->llink != NULL)
//         ptr = ptr->llink;
//     ptr->llink = header1->llink;
//     delete (header1);
//     header2 = header;
//     printNode(header2);
// }
//-------------------------------------------------------------------
//         Functions For string operations
//-------------------------------------------------------------------
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
void insertAtAnyPos(Node *head, string x, string key)
{
    Node *n4 = new Node(x);
    Node *ptr = head;
    while ((ptr->sdata != key) && (ptr->link != NULL)) // It will scan for the data which was entered to line 114 and weather the node is the last node or not.
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
void printNode(Node *head)
{
    Node *ptr = head;
    do
    {
        cout << "| " << ptr->sdata << " | "; // This will print data of the node to which ptr is pointing.
        ptr = ptr->link;                    // This will move the ptr pointer to the next node it works as i++ in for loop.
        cout << " ->   ";
    } while (ptr != NULL);
    cout << "NULL" << endl
         << endl;
}
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
void copyLinkedList(Node *&header, Node *&header1)
{
    Node *ptr = header->link;
    Node *ptr1 = header1;
    while (ptr != NULL)
    {
        Node *n5 = new Node(ptr->sdata);
        ptr1->link = n5;
        ptr1 = n5;
        ptr = ptr->link;
    }
    cout << endl
         << "\t\t\tDATA COPIED" << endl;
}