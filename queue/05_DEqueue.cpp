#include <iostream>
using namespace std;
class Queue
{
    // int *arr;
    int arr[5];
    int front;
    int rear;
    // int size = 5;

public:
    Queue()
    {
        front = -1;
        rear = -1;
        // arr = new int[size];
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (rear == 4)
            return true;
        else
            return false;
    }
    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue is FULL!" << endl;
            return;
        }
        // else if (front == -1 && rear == -1)
        else if (isEmpty())
        {
            front = 0;
            rear = 0;
            arr[rear] = val;
        }
        else
        {
            rear++;
            arr[rear] = val;
        }
    }
    void enqueueFront(int val)
    {
        if (isFull())
        {
            cout << "Queue is FULL!" << endl;
            return;
        }
        // else if (front == -1 && rear == -1)
        else if (isEmpty())
        {
            front = 0;
            rear = 0;
            arr[rear] = val;
        }
        else
        {
            front--;
            arr[front] = val;
        }
    }
    int dequeue()
    {
        int x = 0;
        if (isEmpty())
        {
            cout << "Queue is EMPTY!!" << endl;
            return x;
        }
        else if (rear == front)
        {
            x = arr[front];
            arr[front] = 0;
            rear = -1;
            front = -1;
            return x;
        }
        else
        {
            x = arr[front];
            arr[front] = 0;
            front++;
            return x;
        }
    }
    int dequeueRear()
    {
        int x = 0;
        if (isEmpty())
        {
            cout << "Queue is EMPTY!!" << endl;
            return x;
        }
        else if (rear == front)
        {
            x = arr[front];
            arr[front] = 0;
            rear = -1;
            front = -1;
            return x;
        }
        else
        {
            x = arr[rear];
            arr[rear] = 0;
            rear--;
            return x;
        }
    }
    int count()
    {
        if (isEmpty())
            return 0;
        else
            return ((rear - front) + 1);
    }
    void display()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Queue q1;
    int option, value;
    do
    {
        cout << "Select option number that you want to perform. Press 0 to exit" << endl;
        cout << "1. EnqueueRear()" << endl;
        cout << "2. DequeueFront()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. count()" << endl;
        cout << "6. display()" << endl;
        cout << "7. Clear screen" << endl;
        cout << "8. EnqueueFront()" << endl;
        cout << "9. DequeueRear()" << endl;
        cin >> option;

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Enter value to want to insert in queue: " << endl;
            cin >> value;
            q1.enqueue(value);
            break;

        case 2:
            cout << "DequeueFront operation called" << endl;
            q1.dequeue();
            break;

        case 3:
            if (q1.isEmpty())
            {
                cout << "Queue is EMPTY" << endl;
            }
            else
            {
                cout << "Queue is not empty" << endl;
            }

            break;
        case 4:
            if (q1.isFull())
            {
                cout << "Queue is FULL" << endl;
            }
            else
            {
                cout << "Queue is not full" << endl;
            }
            break;
        case 5:
            cout << "Number of items are " << q1.count() << endl;
            break;
        case 6:
            cout << "Queue is: " << endl;
            q1.display();
            break;
        case 7:
            system("cls");
            break;
        case 8:
            cout << "Enter value to want to insert in front of queue: " << endl;
            cin >> value;
            q1.enqueueFront(value);
            break;
        case 9:
            cout << "DequeueaRear operation called" << endl;
            q1.dequeueRear();
            break;
        default:
            break;
        }
    } while (option != 0);
    return 0;
}