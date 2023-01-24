// OPERATION ON LINKED LIST:
#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
    int data;
    Node *link;
    Node() {}
    Node(int data)
    {
        this->data = data;
        this->link = NULL;
    }
};
// This will make a node and insert it to the head.
void insertAtHead(Node *&head, int x)
{
    Node *n2 = new Node(x); // Getting a new node from free pool of storage and inserting data into it with the help of constructor.
    n2->link = head->link;  // This will insert the address of first node into the link part of new node(n2).
    head->link = n2;        // This will move head pointer to the new node and now your 1st node will be the new node(n2).
}
// This will make a node and insert it to the tail.
void insertAtTail(Node *head, int x)
{
    Node *n3 = new Node(x);   // Getting a new node from free pool of storage and inserting data into it with the help of constructor.
    Node *ptr = head;         // This will start from the header node.
    while (ptr->link != NULL) // This will contnue iterating untile it gets NULL in the link part of the last node.
        ptr = ptr->link;
    ptr->link = n3;  // This will insert the address of new node into the exesting previous node.
    n3->link = NULL; // This will insert NULL at the end of the last node.
}
// This will make a node and insert it to the position prior to the key element.
void insertAtAnyPos(Node *head, int x, int key)
{
    Node *n4 = new Node(x);
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
// This will print Node
void printNode(Node *head)
{
    Node *ptr = head;
    do
    {
        cout << "| " << ptr->data << " | "; // This will print data of the node to which ptr is pointing.
        ptr = ptr->link;                    // This will move the ptr pointer to the next node it works as i++ in for loop.
        cout<< " ->   "; // This will print address of the node to which ptr is pointing.
    } while (ptr != NULL);
    cout << "NULL" << endl
         << endl;
}
void deletSllFront(Node *&header)
{
    Node *ptr = header->link;
    // Node *ptr1;
    if (ptr == NULL)
    {
        cout << "The Linked list is EMPTY: No deletion poosible.";
    }
    else
    {
        //  ptr1=ptr->link;
        header->link = ptr->link;
        delete (ptr);
        cout << endl
             << "Node Deleted.\n";
    }
}
// void swapDll(Node *&node1,Node *&node2){
//     Node *temp;
//     temp=node1;
//     node1->r_link=node2->r_link;
//     node1->l_link=node2->l_link;
//     node2->r_link=temp->r_link;
//     node2->l_link=temp->l_link;
//     ptr=node1->l_link;
//     ptr1=node1->r_link;
//     ptr->r_link=node1;
//     ptr1->l_link=node1;
//     ptr=node2->l_link;
//     ptr1=node2->r_link;
//     ptr->r_link=node2;
//     ptr1->l_link=node2;display(1);
// }
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
int main()
{
    Node *n1 = new Node(0);
    Node *head = n1;
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    insertAtTail(head, 9);
    printNode(head);
    // deletSllFront(head);
    Node *n2 = new Node(0);
    Node *head1 = n2;
    insertAtTail(head1, 10);
    insertAtTail(head1, 11);
    insertAtTail(head1, 12);
    insertAtTail(head1, 13);
    insertAtTail(head1, 14);
    insertAtTail(head1, 15);
    printNode(head1);
    meargLinkedList(head, head1);
}
// ___________________________________________________________________________________
// REVERSE A LINKED LIST:

