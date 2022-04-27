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
void get_arr(int size, int a[])
{
    cout << "Array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int a[10];
    int s;
    cout << "Enter size of your array: " << endl;
    cin >> s;
    set_arr(s, a);
    get_arr(s, a);
    return 0;
}