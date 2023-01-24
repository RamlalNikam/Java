#include <iostream>
using namespace std;
class LinkedList
{
public:
    struct node
    {
        struct node *l_link;
        int data;
        struct node *r_link;
    };
    struct node *header[3], *ptr, *get_new, *ptr1;
    LinkedList();
    // ~LinkedList();
    void create();
    void display(int i);
    void merg();
    void insertFront(int);
    void insertEnd(int);
    void reverseSll();
    void swapDll(node *&,node *&);
    void askSwap();
};
LinkedList::LinkedList()
{
    header[0] = new node;
    header[0]->r_link = NULL;
    header[0]->data = 0;
    header[1] = new node;
    header[1]->r_link = NULL;
    header[1]->data = 1;
}
// LinkedList::~LinkedList()
// {
//     while (header != NULL)
//     {
//         ptr = header[0];
//         header[0] = header[0]->r_link;
//         delete ptr;
//     }
// }
void LinkedList::merg()
{
    //struct node mearg;
    ptr = header[0]->r_link;
    ptr1 = header[1]->r_link;
    while (ptr->r_link != NULL)
        ptr = ptr->r_link;
    ptr->r_link = header[1]->r_link;
    ptr1->l_link=ptr;
    display(0);
    display(1);
}
void LinkedList::reverseSll()
{
    ptr = header[0]->r_link;
    while (ptr->r_link != NULL)
        ptr = ptr->r_link;
    while (ptr != NULL)
    {
        cout << ptr->data << " ->  ";
        ptr = ptr->l_link;
    }
}
void LinkedList::insertFront(int i)
{
    ptr = header[i]->r_link;
    get_new = new node;
    if (get_new == NULL)
    {
        cout << endl
             << "Insufficient Memory." << endl;
        return;
    }
    cout << endl
         << "Data: ";
    cin >> get_new->data;
    if (header[i]->r_link == 0)
    {
        get_new->l_link = header[i];
        get_new->r_link = header[i]->r_link;
        header[i]->r_link = get_new;
    }
    else
    {
        get_new->l_link = header[i];
        header[i]->r_link = get_new;
        get_new->r_link = ptr;
        ptr->l_link = get_new;
        // ptr = ptr->l_link;
    }
}
void LinkedList::insertEnd(int i)
{
    ptr = header[i];
    get_new = new node;
    if (get_new == NULL)
    {
        cout << endl
             << "Insufficient Memory." << endl;
        return;
    }
    cout << endl
         << "Data: ";
    cin >> get_new->data;
    while (ptr->r_link != NULL)
    {
        ptr = ptr->r_link;
    }
    get_new->l_link = ptr;
    ptr->r_link = get_new;
    get_new->r_link = NULL;
}
void LinkedList::create()
{
    int n, choise;
    cout << endl
         << "How many element u want to enter in the linked list: ";
    cin >> n;
    while (choise != 3)
    {
    back:
        cout << endl
             << "\t1.To insert from frount.\n\t2.To insert from End.\n\t3.To Exit.\n\t4.To create a linked list and mearg it into the another.\n\t5.To print a linked list." << endl;
        cin >> choise;
        switch (choise)
        {
        case 1:
            insertFront(0);
            break;
        case 2:
            insertEnd(0);
            break;
        case 4:
            back1:
            cout << endl
                 << "1.To insert from front."
                 << "\n\t2.To insert from end.\n\t3.To go Back"
                 << "\n\t4.To mearge." 
                 << "\n\t5.To Display & Swap"<< endl;
            cin >> choise;
            switch (choise)
            {
            case 1:
                insertFront(1);
                goto back1;
            case 2:
                insertEnd(1);
                goto back1;
            case 3:
                goto back;
            case 4:
                merg();
                goto back1;
            }
            break;
        case 5:
            display(0);
            askSwap();
            break;
        default:
            break;
        }
    }
}
void LinkedList::display(int i)
{
    cout << endl
         << "Elements of the linked list are: " << endl;
    ptr = header[i];
    while (ptr != NULL)
    {
        cout << ptr->data << " ->  ";
        ptr = ptr->r_link;
    }
    cout << "NULL" << endl;
}
void LinkedList::askSwap(){
    int n1,n2;
    cout<<endl<<"Enter elements to swap: ";
    cin>>n1>>n2;
    ptr=header[0]->r_link;
    ptr1=header[0]->r_link;
    while((ptr->data!=n1)&&(ptr->r_link!=NULL))
        ptr=ptr->r_link;
    while((ptr1->data!=n2)&&(ptr1->r_link!=NULL))
        ptr1=ptr1->r_link;
    // swapDll(ptr,ptr1);
    struct node *temp;
    temp=ptr;
    ptr->r_link=ptr1->r_link;
    ptr=ptr->l_link;
    ptr->r_link=ptr1;
    // ptr->l_link=ptr1->l_link;
    ptr1->r_link=temp->r_link;
    ptr1=ptr1->l_link;
    ptr->l_link=temp;
    // ptr1->l_link=temp->l_link;
    // ptr=ptr->l_link;
    // ptr1=ptr->r_link;
    // ptr->r_link=ptr;
    // ptr1->l_link=ptr;
    // ptr=ptr1->l_link;
    // ptr1=ptr1->r_link;
    // ptr->r_link=ptr1;
    // ptr1->l_link=ptr1;
    display(0);
}
void LinkedList::swapDll(node *&ptr,node *&ptr1){
    
}
int main()
{
    int no_list;
    cout << "Enter number of linked list you want to create: ";
    cin >> no_list;
    LinkedList *l;
    l = new LinkedList[no_list];
    for (int i = 0; i < no_list; i++)
    {
        l->create();

        l->reverseSll();
    }

    return 0;
}