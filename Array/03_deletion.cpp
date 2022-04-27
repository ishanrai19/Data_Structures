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
void delete_element(int a[], int size, int ind)
{
    for (int i = ind; i < size - 1; i++)
    {
        a[i] = a[i + 1];
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
    cout << "Enter index at which you want to delete element in your array: " << endl;
    cin >> index;
    delete_element(a, s, index);
    s -= 1;
    get_arr(s, a);
    return 0;
}