#include<iostream>
using namespace std;
class DllNode
{
public:
    DllNode *l_link;
    int data;
    string s_data;
    DllNode *r_link;
    DllNode();
    DllNode(int data)
    {
        l_link = NULL;
        this->data = data;
        r_link = NULL;
    }

    DllNode(string s_data)
    {
        l_link = NULL;
        this->s_data = s_data;
        r_link = NULL;
    }
};
int countNodesDll(DllNode *header)
{
    DllNode *ptr = header->r_link;
    int count = 0;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->r_link;
    }
    return count;
}
/*
--------------------------------------------------------------
                    FUNCTIONS TO INSERT:
--------------------------------------------------------------
*/
//This function will make a node and insert it to the front of the dounle linked list.
void insertDllNodeHeadInt(DllNode *&header, int x)
{
    DllNode *new_node = new DllNode(x);
    DllNode *tail = new DllNode(999);
    if (header->r_link == NULL)
    {
        header->r_link = tail;
        tail->l_link = header;
    }
    DllNode *ptr = header->r_link;
    new_node->r_link = header->r_link;
    header->r_link = new_node;
    new_node->l_link = header;
    ptr->l_link = new_node;
}
//This function will make a node and insert it to the end of the double linked list.
void insertDllNodeEndInt(DllNode *&header, int x)
{
    DllNode *ptr = header;
    while (ptr->r_link != NULL)
        ptr = ptr->r_link;
    DllNode *new_node = new DllNode(x);
    ptr->r_link = new_node;
    new_node->l_link = ptr;
}
//This function will make a node and insert it after the key element of the linked list.
void insertDllNodeAnyInt(DllNode *&header, int key, int x)
{
    DllNode *ptr = header->r_link;
    while ((ptr->data != key) && (ptr->r_link != NULL))
        ptr = ptr->r_link;
    if (ptr->r_link == NULL)
        cout << endl<<"Data not found."<<endl;
    else
    {
        DllNode *new_node = new DllNode(x);
        DllNode *ptr1;
        ptr1 = ptr->r_link;
        new_node->l_link = ptr;
        new_node->r_link = ptr1;
        ptr->r_link = new_node;
        ptr1->l_link = new_node;
    }
}
/*
--------------------------------------------------------------
                    FUNCTIONS TO DELETE:
--------------------------------------------------------------
*/
// This function will delete a mode from front.
void deletDllNodeHeadInt(DllNode *&header)
{
    DllNode *ptr = header->r_link;
    DllNode *ptr1 = ptr->r_link;
    header->r_link = ptr1;
    ptr1->l_link = header;
    delete (ptr);
}
// This function will delete a node from end.
void deletDllNodeEndInt(DllNode *&header)
{
    DllNode *ptr = header->r_link;
    DllNode *ptr1;
    while (ptr->r_link != NULL)
    {
        ptr1 = ptr;
        ptr = ptr->r_link;
    }
    ptr1->r_link = NULL;
    delete (ptr);
}
// This function will delete a node of the key element.
int deletDllNodeAnyInt(DllNode *&header, int key)
{
    DllNode *ptr = header->r_link;
    DllNode *ptr1;
    DllNode *ptr2;
    if (ptr == NULL)
    {
        cout << "List is empty: No deletion possible";
        return 0;
    }

    while ((ptr->data != key) && (ptr->r_link != NULL))
        ptr = ptr->r_link;
    if (ptr->data == key)
    {
        ptr1 = ptr->l_link;
        ptr2 = ptr->r_link;
        ptr1->r_link = ptr2;
        ptr2->l_link = ptr1;
        delete (ptr);
    }
    else
        cout << endl
             << "The node does not exist in the given list." << endl;
    return 0;
}
/*
--------------------------------------------------------------
                    FUNCTIONS TO PRINT:
--------------------------------------------------------------
*/
//This function will print the whole double linked list
void printDllNodeInt(DllNode *header)
{
    DllNode *ptr = header->r_link;
    cout << "| " << &header->l_link << " | " << header->s_data << " | " << &header->l_link << "  ->  " << endl;
    while (ptr != NULL)
    {
        cout << "| " << &ptr->l_link << " | " << ptr->data << " | ";
        ptr = ptr->r_link;
        cout << &ptr->r_link << " |  ->  " << endl;
        // cout<<"\t  | "<<&ptr->l_link<<" |"<<endl;
    }
    cout << "NULL" << endl;
}
//This function will print the whole double linked list from the end(i.e.it will reverse the linked list).
void reverseADll(DllNode *header)
{
    DllNode *ptr = header->r_link;
    while (ptr->r_link != 0)
        ptr = ptr->r_link;
    cout << endl
         << endl;
    while (ptr->l_link != NULL)
    {
        cout << "| " << ptr->data << " |  ->  ";
        ptr = ptr->l_link;
    }
    cout<<"| "<<ptr->s_data<<" |  ->  NULL"<<endl;
}