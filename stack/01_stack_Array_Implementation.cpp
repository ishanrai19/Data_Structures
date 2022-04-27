#include <iostream>
#include <string>
#define size 5
using namespace std;
class stack
{
    int top;
    // int size = 5;
    int *arr;

public:
    stack()
    {
        top = -1;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (top == size - 1)
            return true;
        else
            return false;
    }
    void push(int val)
    {
        if (isFull() == true)
        {
            cout << "Stack overflow!" << endl;
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }
    int pop()
    {
        if (isEmpty() == true)
        {
            cout << "Stack underflow!" << endl;
            return 0;
        }
        else
        {
            int popVal = arr[top];
            arr[top] = 0;
            top--;
            return popVal;
        }
    }
    int count()
    {
        return (top + 1);
    }
    int peek(int position)
    {
        if (isEmpty() == true)
        {
            cout << "Stack underflow!" << endl;
            return 0;
        }
        else
        {
            return arr[position];
        }
    }
    void change(int position, int val)
    {
        arr[position] = val;
        cout << "Value at position " << position << " changed" << endl;
    }
    void display()
    {
        for (int i = 4; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
};
int main()
{
    stack s1;
    int option, value, position;
    do
    {
        cout << "Select option number that you want to perform. Press 0 to exit" << endl;
        cout << "1. push()" << endl;
        cout << "2. pop()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. peek()" << endl;
        cout << "6. count()" << endl;
        cout << "7. change()" << endl;
        cout << "8. display()" << endl;
        cout << "9. Clear screen" << endl;
        cin >> option;

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Enter value you want to push in stack: ";
            cin >> value;
            s1.push(value);
            break;
        case 2:
            cout << "Value popped: " << s1.pop() << endl;
            break;
        case 3:
            if (s1.isEmpty())
            {
                cout << "Stack is empty" << endl;
            }
            else
            {
                cout << "Stack is not empty" << endl;
            }
            break;
        case 4:
            if (s1.isFull())
            {
                cout << "Stack is full" << endl;
            }
            else
            {
                cout << "Stack is not full" << endl;
            }
            break;
        case 5:
            cout << "Enter position you want to peek" << endl;
            cin >> position;
            cout << "Value at position " << position << " is " << s1.peek(position) << endl;
            break;
        case 6:
            cout << "Number of items in stack are " << s1.count() << endl;
            break;
        case 7:
            cout << "Chnage value called" << endl;
            cout << "Enter the position of item you want to change: ";
            cin >> position;
            cout << endl;
            cout << "Enter value of item you want to change: ";
            cin >> value;
            cout << endl;
            s1.change(position, value);
            break;
        case 8:
            cout << "display function called: " << endl;
            s1.display();
            break;
        case 9:
            system("cls");
            break;
        default:
            cout << "Enter proper choice!!" << endl;
            break;
        }
    } while (option != 0);

    return 0;
}