#include <iostream>
using namespace std;
class Tree
{
public:
    struct node
    {
        node *rc;
        node *lc;
        char data;
    };
    struct node *root, *get_new, *bptr, *ptr, *stack[12];
    Tree()
    {
        root->rc = NULL;
        root->lc = NULL;
        root->data = 'A';
        bptr = root;
    }
    void insertAtRc(char);
    void insertAtRcRoot(char);
    void insertAtLc(char);
    void inorder();
    void preorder();
    void postorder();
};
Tree::Tree()
{
    root->rc = NULL;
    root->lc = NULL;
    root->data = 'A';
    bptr = root;
}
void Tree::insertAtRc(char x)
{
    get_new = new node;
    bptr->rc = get_new;
    get_new->data = x;
    get_new->rc = get_new->lc = NULL;
    bptr = get_new;
}
void Tree::insertAtRcRoot(char x)
{
    get_new = new node;
    root->rc = get_new;
    get_new->data = x;
    get_new->rc = get_new->lc = NULL;
    bptr = get_new;
}
void Tree::insertAtLc(char x)
{
    get_new = new node;
    bptr->lc = get_new;
    get_new->data = x;
    get_new->rc = get_new->lc = NULL;
    bptr = get_new;
}
void Tree::inorder()
{
    int top = 0;
    stack[top] = NULL;
    ptr = root;
step2:
    while (ptr != NULL)
    {
        top = top + 1;
        stack[top] = ptr;
        ptr = ptr->lc;
    }
    ptr = stack[top];
    top -= 1;
    while (ptr != NULL)
    {
        if (ptr->data == root->data)
            cout << " " << ptr->data << "  ";
        else
            cout << ptr->data << " ";
        if (ptr->rc != NULL)
        {
            ptr = ptr->rc;
            goto step2;
        }
        ptr = stack[top];
        top -= 1;
    }
}
void Tree::preorder()
{
    int top = 0;
    stack[top] = NULL;
    ptr = root;
    while (ptr != NULL)
    {
        if (ptr->data == root->data)
            cout << " " << ptr->data << "  ";
        else
            cout << ptr->data << " ";
        if (ptr->rc != NULL)
        {
            top += 1;
            stack[top] = ptr->rc;
        }
        if (ptr->lc != NULL)
        {
            ptr = ptr->lc;
        }
        else
        {
            ptr = stack[top];
            top -= 1;
        }
    }
}
void Tree::postorder()
{
    int top = 0;
    stack[top] = NULL;
    ptr = root;
    while (ptr != NULL)
    {
        top = top + 1;
        stack[top] = ptr;
        if (ptr->rc != NULL)
        {
            top = top + 1;
            // stack[top] = ptr->rc*(-1);
        }
    }
}
int main()
{
    Tree t;
    t.insertAtLc('B');
    t.insertAtRc('E');
    t.insertAtLc('F');
    t.insertAtRcRoot('C');
    t.insertAtRc('H');
    t.insertAtLc('J');
    t.insertAtLc('L');
    // t.insertAtRc(22);
    cout << endl
         << "Traversal using Inorder: \v";
    t.inorder();
    cout << endl
         << "Traversal using Preorder: \v";
    t.preorder();
}