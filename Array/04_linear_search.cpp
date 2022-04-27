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
int search_element(int a[], int size, int el)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] == el)
        {
            cout << "Element found at index " << i << endl;
            return 1;
        }
    }
    return 0;
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
    cout << "Enter size of your array: ";
    cin >> s;
    set_arr(s, a);
    get_arr(s, a);
    cout << "Enter element you want to search in your array: " << endl;
    cin >> new_elemet;
    int result = search_element(a, s, new_elemet);
    if (result == 1)
    {
        cout << "Element found in array" << endl;
    }
    else
    {
        cout << "Element NOT found" << endl;
    }
    return 0;
}