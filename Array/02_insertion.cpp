#include <iostream>
using namespace std;
void set_arr(int size, int a[])
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element number a[" << i << "] = ";
        cin >> a[i];
    }
}
void insert(int a[], int size, int el, int ind)
{
    if (ind <= size)
    {
        cout << "Insertion Successful...." << endl;

        for (int i = size - 1; i >= ind; i--)
        {
            a[i + 1] = a[i];
        }
        a[ind] = el;
    }
    else
    {
        cout << "Insertion not possible enter valid index" << endl;
    }
}
void get_arr(int size, int a[])
{
    cout << "Array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    int a[20];
    int s, new_elemet, index;
    cout << "Enter size of your array: " << endl;
    cin >> s;
    set_arr(s, a);
    get_arr(s, a);
    cout << "Enter element you want to insert in your array: " << endl;
    cin >> new_elemet;
    cout << "Enter index at which you want to insert element in your array: " << endl;
    cin >> index;
    insert(a, s, new_elemet, index);
    s += 1;
    get_arr(s, a);

    return 0;
}