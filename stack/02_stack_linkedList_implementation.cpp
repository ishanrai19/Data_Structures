#include <iostream>
using namespace std;
class Node
{
public:
    int key;
    int data;
    Node *next;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }
    Node(int k, int d)
    {
        key = k;
        data = d;
        next = NULL;
    }
};
class Stack
{
public:
    Node *top;
    Stack()
    {
        top = NULL;
    }
    bool isEmpty()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            return true;
        }
        else
        {
            cout << "Stack is NOT empty" << endl;
            return false;
        }
    }
    bool checkIfNodeExists(Node *n)
    {
        Node *temp = top;
        bool exist = false;
        while (temp != NULL)
        {
            if (n->key == temp->key)
            {
                cout << "Node with same key already exists" << endl;
                exist = true;
            }
            temp = temp->next;
        }
        return exist;
    }
    void push(Node *n)
    {
        if (top == NULL)
        {
            top = n;
            cout << "Node pushed" << endl;
        }
        else if (checkIfNodeExists(n))
        {
            cout << "Node with same key exists, Enter a different key" << endl;
        }
        else
        {

            Node *temp = top;
            top = n;
            n->next = temp;
            cout << "Node pushed" << endl;
        }
    }
    void peek()
    {
        if (isEmpty())
        {
            cout << "Stack UNDERflow!" << endl;
            // return NULL;
        }
        else
        {
            cout << "(" << top->key << "," << top->data << ")" << endl;
            // return top;
        }
    }
    void count()
    {
        int count = 0;
        if (isEmpty())
        {
            cout << "Stack is EMPTY" << endl;
            // return;
        }
        else
        {
            Node *temp = top;
            while (temp != NULL)
            {
                count++;
                temp = temp->next;
            }
        }
        cout << "No. of elements in Stack = " << count << endl;
    }
    Node *pop()
    {
        Node *temp = NULL;
        if (isEmpty())
        {
            // cout << "Stack is empty" << endl;
            return temp;
        }
        else
        {
            temp = top;
            top = top->next;
            return temp;
            delete temp;
        }
    }
    void display()
    {
        if (top == NULL)
        {
            cout << "Empty Stack!!" << endl;
        }
        else
        {
            cout << "Stack: " << endl;
            Node *temp = top;
            while (temp != NULL)
            {
                cout << "(" << temp->key << "," << temp->data << "," << temp->next << ")" << endl;
                temp = temp->next;
            }
            cout << endl;
        }
    }
};
int main()
{
    Stack s;
    int option, k, d;
    do
    {
        cout << "Stack Counter Enter your choice and 0 to exit the counter:" << endl;
        cout << "1. push()\n 2. pop()\n 3. isEmpty()\n 4. peek()\n 5. count()\n 6. display()\n 7. clear screen" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> option;
        Node *new_node = new Node();
        switch (option)
        {

        case 0:
            break;
        case 1:
            cout << "Enter key of new node: " << endl;
            cin >> k;
            cout << "Enter value of new node: " << endl;
            cin >> d;
            // Node* pushNode= new Node(k,d)
            new_node->key = k;
            new_node->data = d;
            s.push(new_node);
            break;
        case 2:
            new_node = s.pop();
            if (s.isEmpty() == true)
            {
                cout << "Stack underflow" << endl;
            }
            else
            {
                cout << "Popped Value: " << endl;
                cout << "(" << new_node->key << "," << new_node->data << "," << new_node->next << ")" << endl;
                delete new_node;
            }
            break;
        case 3:
            s.isEmpty();
            break;
        case 4:
            s.peek();
            break;
        case 5:
            s.count();
            break;
        case 6:
            s.display();
            break;
        case 7:
            system("cls");
            break;

        default:
            cout << "Enter valid option number" << endl;
            break;
        }
    } while (option != 0);

    return 0;
}