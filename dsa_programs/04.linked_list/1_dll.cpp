#include <iostream>
using namespace std;
class LinkedList
{
public:
    struct node
    {
        node *l_link;
        node *r_link;
        int data;
    };
    struct node *header, *get_new, *ptr;
    LinkedList()
    {
        header->l_link = NULL;
        header->r_link = NULL;
        header->data = 0;
    }
    void printDll(node *);
    void insertAtHeader(int);
    void insertAtEnd(int);
    void insertAtAny(int);
};
void LinkedList::insertAtHeader(int x)
{
    get_new = new node;
    get_new->r_link = header->r_link;
    get_new->l_link = header;
    header->r_link = get_new;
    get_new->data = x;
}
void LinkedList::printDll(node *head)
{
    ptr = head;
    while (ptr != NULL)
    {
        cout << " " << ptr->data;
        ptr = ptr->r_link;
    }
}
void LinkedList::insertAtAny(int key)
{
    get_new = new node;
}
int main()
{
    LinkedList l;
    l.insertAtHeader(6);
    l.insertAtHeader(2);
    l.insertAtHeader(4);
    l.insertAtHeader(7);
    l.insertAtHeader(8);
    l.printDll(l.header);
}