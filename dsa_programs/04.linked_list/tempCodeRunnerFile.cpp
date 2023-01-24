void insertAtHead(Node *&head, string x)
{
    Node *n2 = new Node(x); // Getting a new node from free pool of storage and inserting data into it with the help of constructor.
    n2->link = head->link;  // This will insert the address of first node into the link part of new node(n2).
    head->link = n2;        // This will move head pointer to the new node and now your 1st node will be the new node(n2).
}