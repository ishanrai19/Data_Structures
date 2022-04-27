#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    int key;
    Node *next;
    Node()
    {
        data = 0;
        key = 0;
        next = NULL;
    }
    Node(int d, int k)
    {
        data = d;
        key = k;
    }
};
class circularLinkedList
{
public:
    Node *head;
    circularLinkedList()
    {
        head = NULL;
    }
    // circularLinkedList(Node *n)
    // {
    //     head = n;
    // }
    Node *nodeExist(int k)
    {
        Node *temp = NULL;
        Node *ptr = head;
        if (ptr == NULL)
        {
            return temp;
        }
        else
        {
            do
            {
                if (ptr->key == k)
                {
                    temp = ptr;
                }

                ptr = ptr->next;
            } while (ptr != head);
            return temp;
        }
    }
    void insertAtEnd(Node *n)
    {
        // append
        if (nodeExist(n->key) != NULL)
        {
            cout << "node already exists" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                n->next = head; // edited
                cout << "Node inserted at head" << endl;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != head)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->next = head;
                // head = n;//edited
                cout << "Node inserted at head" << endl;
            }
        }
    }
    void insertAtHead(Node *n)
    { // prepend
        if (nodeExist(n->key) != NULL)
        {
            cout << "Node already exists with key " << n->key << endl;
        }
        else
        {

            {
                if (head == NULL)
                {
                    head = n;
                    n->next = head;
                    cout << "Node inserted at head" << endl;
                    return;
                }
                else
                { // edited
                    Node *ptr = head;
                    while (ptr->next != head)
                    {
                        ptr = ptr->next;
                    }
                    ptr->next = n;
                    n->next = head;
                    head = n;
                    cout << "Node prepended" << endl;
                }
            }
        }
    }
    void insertAfterNode(int k, Node *n)
    {
        Node *ptr = nodeExist(k);
        if (ptr == NULL)
        {
            cout << "Node does not exist" << endl;
        }
        else
        {
            // Node *nextNode = ptr->next;
            if (nodeExist(n->key) != NULL)
            {
                cout << "Node already exists with key " << n->key << endl;
            }
            else
            {
                if (ptr->next == head)
                {
                    // checking for insertion at end
                    n->next = head;
                    ptr->next = n;
                    cout << "Node inserted successfully" << endl;
                }
                else
                {
                    // in between
                    n->next = ptr->next;
                    ptr->next = n;
                    cout << "Node inserted successfully" << endl;
                }
            }
        }
    }
    void deleteNodeByKey(int k)
    {
        Node *ptr = nodeExist(k);
        if (ptr == NULL)
        {
            cout << "Node doesn't exist with entered key" << endl;
        }
        else
        {
            if (ptr == head) // for deleting head node
            {
                if (ptr->next == head)
                { // for only single head node
                    head = NULL;
                    cout << "Head node unlinked" << endl;
                }

                else
                {
                    // head node deletion when list has other nodes also
                    Node *endPtr = head;
                    while (endPtr->next != head)
                    {
                        endPtr = endPtr->next;
                    }
                    endPtr->next = head->next;
                    head = head->next;
                    cout << "Node unlinked" << endl;
                }
            }
            else
            {
                // deletion in between
                Node *temp = NULL;
                Node *beforePtr = head;
                Node *currentPtr = head->next;
                while (currentPtr != NULL)
                {
                    if (currentPtr->key == k)
                    {
                        temp = currentPtr;
                        currentPtr = NULL;
                    }
                    else
                    {
                        currentPtr = currentPtr->next;
                        beforePtr = beforePtr->next;
                    }
                }

                beforePtr->next = temp->next;
                cout << "Node in between deleted" << endl;
            }
        }
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "Empty list" << endl;
        }
        else
        {
            cout << "Head address: " << head << endl;
            cout << "Circular linked list:" << endl;
            Node *ptr = head;
            do
            {
                cout << "[" << ptr->key << "," << ptr->data << "," << ptr->next << "] --> ";
                ptr = ptr->next;
            } while (ptr != head);
        }
    }
};
int main()
{
    circularLinkedList c1;
    int option;
    int data1, key1, k1;
    do
    {
        cout << "\nEnter the option for the operation you want to perform\nPress 0 to exit" << endl;
        cout << "1.insertAtHead()" << endl;
        cout << "2.insertAtEnd()" << endl;
        cout << "3.insertAfterNode()" << endl;
        cout << "4.deleteNodeByKey()" << endl;
        cout << "5.displayCircularLinkedList()" << endl;
        cout << "6.clearScreen()" << endl;
        cin >> option;
        cout << endl;
        Node *n1 = new Node();
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Insertion at head" << endl;
            cout << "Enter key and data of the node you want to insert" << endl;
            cin >> key1 >> data1;
            n1->key = key1;
            n1->data = data1;
            c1.insertAtHead(n1);
            break;
        case 2:
            cout << "Insertion at end" << endl;
            cout << "Enter key and data of the node you want to insert" << endl;
            cin >> key1 >> data1;
            n1->key = key1;
            n1->data = data1;
            c1.insertAtEnd(n1);
            break;
        case 3:
            cout << "Insertion in between called" << endl;
            cout << "Enter key of node after which you want to insert:" << endl;
            cin >> k1;
            cout << "Enter key and data of the node you want to insert" << endl;
            cin >> key1 >> data1;
            n1->key = key1;
            n1->data = data1;
            c1.insertAfterNode(k1, n1);
            break;
        case 4:
            cout << "Enter key of node after which you want to delete:" << endl;
            cin >> k1;
            c1.deleteNodeByKey(k1);
            break;
        case 5:
            c1.display();
            break;
        case 6:
            system("cls");
            break;

        default:
            cout << "\nEnter valid option !!!" << endl;
            break;
        }
    } while (option != 0);

    return 0;
}