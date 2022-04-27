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
    Node(int k, int d)
    {
        key = k;
        data = d;
        // next = NULL;
    }
};
class singlyLinkedList
//to link objects of class node
{
public:
    Node *head;
    singlyLinkedList()
    {
        head = NULL;
    }
    singlyLinkedList(Node *n)
    {
        head = n;
    }
    Node *nodeExists(int k)
    {
        Node *temp = NULL;
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }

            // ptr = (*ptr).next; or
            ptr = ptr->next;
        }
        return temp;
    }
    void appendNode(Node *n)
    {
        // insert at end
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node with same key already exists!" << endl;
            return;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "Node appended" << endl;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                // n->next = NULL;
                cout << "Node appended" << endl;
            }
        }
    }
    void prependNode(Node *n)
    {
        // insert at head
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node with same key already exists!" << endl;
            return;
        }
        else
        {
            n->next = head;
            head = n;
            cout << "Node prepended" << endl;
        }
    }
    void insertAfterNode(Node *n, int k)
    {
        Node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "No node exist with key " << k << endl;
        }
        else
        {
            if (nodeExists(n->key) != NULL)
            {
                cout << "Node with same key already exists!" << endl;
                return;
            }
            else
            {
                n->next = ptr->next;
                ptr->next = n;
                cout << "Node inserted" << endl;
            }
        }
    }
    void deleteNodeByKey(int k)
    {
        if (head == NULL)
        {
            cout << "Empty list" << endl;
        }
        else if (head != NULL)
        {
            if (head->key == k)
            {
                Node *todel = head;
                head = head->next;
                delete todel;
                cout << "Node with key " << k << " deleted" << endl;
            }
            else
            {
                // node in between
                Node *temp = NULL;
                Node *prev = head;
                Node *todel = head->next;
                while (todel != NULL)
                {
                    if (todel->key = k)
                    {
                        temp = todel;
                        todel = NULL;
                    }
                    else
                    {
                        todel = todel->next;
                        prev = prev->next;
                    }
                }
                if (temp != NULL)
                {
                    prev->next = temp->next;
                    delete todel;
                    cout << "Node with key " << k << " deleted" << endl;
                }
                else
                {
                    cout << "Node doesn't exist with key value " << k << endl;
                }
            }
        }
    }
    void updateNodeByKey(int k, int d)
    {
        Node *ptr = nodeExists(k);
        if (ptr != NULL)
        {
            ptr->data = d;
            cout << "Node data updated" << endl;
        }
        else
        {
            cout << "Node doesn't exist with key value " << k << endl;
        }
    }
    void printSinglyLinkedList()
    {
        if (head == NULL)
        {
            cout << "No Node present in list" << endl;
        }
        else
        {
            cout << "values in list:" << endl;
            Node *temp = head;
            do
            {
                cout << "[" << temp->key << "," << temp->data << "]--->";
                temp = temp->next;
            } while (temp != NULL);
        }
    }
};

int main()
{
    // Node n1(1, 5);
    // Node n2(3, 7);
    // Node n3(3, 9);
    singlyLinkedList s;
    int key1, k1, data1, option;
    do
    {
        cout << "\nWhat operation you want to perform? select respective option and Enter 0 to exit" << endl;
        cout << "1. appendNode() " << endl;
        cout << "2. prependNode() " << endl;
        cout << "3. insertAfterNode() " << endl;
        cout << "4. deleteNodeByValue() " << endl;
        cout << "5. updateNodeByKey() " << endl;
        cout << "6. display() " << endl;
        cout << "7. ClearScreen() " << endl;
        cin >> option;
        Node *n1 = new Node();
        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Enter key & data of the Node to be appended: " << endl;
            cin >> key1;
            cin >> data1;
            n1->data = data1;
            n1->key = key1;
            s.appendNode(n1);
            break;
        case 2:
            cout << "Enter key & data of the Node prepended: " << endl;
            cin >> key1;
            cin >> data1;
            n1->data = data1;
            n1->key = key1;
            s.prependNode(n1);
            break;
        case 3:
            cout << "Enter key of existing node after which you want to insert new node: " << endl;
            cin >> k1;
            cout << "Enter key & data of the Node to be inserted: " << endl;
            cin >> key1;
            cin >> data1;
            n1->data = data1;
            n1->key = key1;
            s.insertAfterNode(n1, k1);
            break;
        case 4:
            cout << "enter key of node to be deleted: " << endl;
            cin >> k1;
            s.deleteNodeByKey(k1);
            break;
        case 5:
            cout << "Enter key and NEW data to be updated:" << endl;
            cin >> key1;
            cin >> data1;
            s.updateNodeByKey(key1, data1);
            break;
        case 6:
            s.printSinglyLinkedList();
            break;
        case 7:
            system("cls");
            break;
        default:
            cout << "Enter proper option!!!!" << endl;
            break;
        }
    } while (option != 0);
    return 0;
}