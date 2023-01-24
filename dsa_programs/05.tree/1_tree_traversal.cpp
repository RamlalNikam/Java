#include <iostream>
#include <string>
using namespace std;
class node
{
public:
    string data;
    node *left;
    node *right;
    node(){}
    node(string d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
    node *createTree(node *);
    void inorder(node *);
    void preorder(node *);
    void postorder(node *);
};
node *node::createTree(node *root)
{
    string data;
    cout << endl
         << "Enter data: ";
    cin >> data;
    root = new node(data);
    if (data == "NULL")
    {
        return NULL;
    }
    cout << endl
         << "Enter data for inserting in left of " << data << " : ";
    root->left = createTree(root->left);
    cout << endl
         << "Enter data for inserting in right of " << data << " : ";
    root->right = createTree(root->right);
    return root;
}
void node::inorder(node *root)
{
    node *stack[15];
    node *ptr;
    int top = 0;
    stack[top] = NULL;
    ptr = root;
step2:
    while (ptr != NULL)
    {
        top = top + 1;
        stack[top] = ptr;
        ptr = ptr->left;
    }
    ptr = stack[top];
    top -= 1;
    while (ptr != NULL)
    {
        if (ptr->data == root->data)
            cout << " " << ptr->data << "  ";
        else
            cout << ptr->data << " ";
        if (ptr->right != NULL)
        {
            ptr = ptr->right;
            goto step2;
        }
        ptr = stack[top];
        top -= 1;
    }
}
void node::preorder(node *root)
{
    node *ptr, *stack[20];
    ptr = root;
    int top = 0;
    stack[top] = NULL;
    ptr = root;
    while (ptr != NULL)
    {
        if (ptr->data == root->data)
            cout << ptr->data << "  ";
        else
            cout << ptr->data << " ";
        if (ptr->right != NULL)
        {
            top += 1;
            stack[top] = ptr->right;
        }
        if (ptr->left != NULL)
        {
            ptr = ptr->left;
        }
        else
        {
            ptr = stack[top];
            top -= 1;
        }
    }
}
void node::postorder(node *root)
{
    node *ptr=root;
    node post;
    if (root != NULL)
    {
        post.postorder(ptr->left);
        post.postorder(ptr->right);
        if(ptr->data==root->data)
            cout<<" "<<ptr->data<<"  ";
        else
            cout << " " << ptr->data;
    }
}
int main()
{
    // A B D NULL NULL E F NULL NULL NULL C G NULL NULL H J L NULL NULL NULL K NULL NULL.
    node tree;
    node *root = NULL;
    root = tree.createTree(root);
    cout << endl
         << "Traversal using inorder: " << endl;
    node *p_root = root;
    tree.inorder(p_root);
    cout << endl;
    cout << endl
         << "Traversal using preorder: " << endl;
    tree.preorder(p_root);
    cout << endl;
    cout << endl
         << "Traversal using postorder: " << endl;
    tree.postorder(p_root);
    return 0;
}