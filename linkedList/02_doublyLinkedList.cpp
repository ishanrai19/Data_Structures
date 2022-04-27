#include <iostream>
using namespace std;
class node
{
public:
    int key;
    int data;
    node *prev;
    node *next;
    node()
    {
        key = 0;
        data = 0;
        prev = NULL;
        next = NULL;
    }
    node(int k, int d)
    {
        key = k;
        data = d;
    }
};
class doublyLinkedList
{
public:
    node *head;
    doublyLinkedList()
    {
        head = NULL;
    }
    doublyLinkedList(node *n)
    {
        head = n;
    }
    // check if node exists
    node *nodeExists(int k)
    {
        node *temp = NULL;
        node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }
    void append(node *n)
    {

        if (nodeExists(n->key) != NULL)
        {
            cout << "Node already exists with key " << n->key << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "Node appended as head node" << endl;
            }
            else
            {

                node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->prev = ptr;
                cout << "Node appended :)" << endl;
            }
        }
    }
    void prepend(node *n)
    {
        if (nodeExists(n->key) != NULL)
        {
            cout << "Node already exists with key " << n->key << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
                cout << "Node appended as head node" << endl;
            }
            else
            {
                head->prev = n;
                n->next = head;
                head = n;
                cout << "Node appended" << endl;
            }
        }
    }
    void insertNodeAfter(int k, node *n)
    {
        node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "No node exists with key value" << endl;
        }
        else
        {

            if (nodeExists(n->key) != NULL)
            {
                cout << "Node already exists with key " << n->key << endl;
            }
            else
            {
                node *nextNode = ptr->next;
                // insert at end
                if (nextNode == NULL)
                {
                    ptr->next = n;
                    n->prev = ptr;
                    cout << "Node inserted at end" << endl;
                }
                // insert in between
                else
                {
                    n->next = nextNode;
                    nextNode->prev = n;
                    n->prev = ptr;
                    ptr->next = n;
                    cout << "Node inserted in between" << endl;
                }
            }
        }
    }
    void deleteNodeByKey(int k)
    {
        node *ptr = nodeExists(k);
        if (ptr == NULL)
        {
            cout << "No node exists with this key" << endl;
        }
        else
        {
            if (head->key == k)
            {
                head = head->next;
                cout << "Node deleted" << endl;
            }
            else
            {

                node *nextNode = ptr->next;
                node *prevNode = ptr->prev;
                // delete at end
                if (nextNode == NULL)
                {
                    // ptr->prev->next=NULL;
                    prevNode->next = NULL;
                    // delete nextNode;
                    cout << "Node at end deleted" << endl;
                }
                // delete in between
                else
                {
                    prevNode->next = nextNode;
                    nextNode->prev = prevNode;
                    // delete ptr;
                    cout << "Node in between deleted" << endl;
                }
            }
        }
    }
    void update(int k, int d)
    {
        node *ptr = nodeExists(k);
        if (ptr != NULL)
        {
            ptr->data = d;
            cout << "Node updated" << endl;
        }
        else
        {
            cout << "Node doesn't exist" << endl;
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
            cout << "Doubly linked list:" << endl;
            node *ptr = head;
            while (ptr != NULL)

            {
                cout << "[" << ptr->key << "," << ptr->data << "] <==> ";
                ptr = ptr->next;
            }
        }
    }
};
int main()
{
    doublyLinkedList obj;
    int option;
    int key1, k1, data1;
    do
    {
        cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. appendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. insertNodeAfter()" << endl;
        cout << "4. deleteNodeByKey()" << endl;
        cout << "5. updateNodeByKey()" << endl;
        cout << "6. print()" << endl;
        cout << "7. Clear Screen" << endl;

        cin >>
            option;
        node *n1 = new node();
        //Node n1;

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            obj.append(n1);
            //cout<<n1.key<<" = "<<n1.data<<endl;
            break;

        case 2:
            cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            obj.prepend(n1);
            break;

        case 3:
            cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
            cin >> k1;
            cout << "Enter key & data of the New Node first: " << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;

            obj.insertNodeAfter(k1, n1);
            break;

        case 4:

            cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
            cin >> k1;
            obj.deleteNodeByKey(k1);

            break;
        case 5:
            cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
            cin >> key1;
            cin >> data1;
            obj.update(key1, data1);

            break;
        case 6:
            obj.display();

            break;
        case 7:
            system("cls");
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}