#include <iostream>
using namespace std;
void linearSearch(int arr[], int k, int s)
{
    for (int i = 0; i < s; i++)
    {
        if (arr[i] == k)
        {
            cout << "Element " << k << " present in array at index value " << i << endl;
            return;
        }
    }
    cout << "Element not found " << endl;
}
int main()
{
    int key, size;
    int a[size];
    cout << "Enter size of your array: ";
    cin >> size;
    cout << endl;
    cout << "Enter " << size << " elements in your array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    cout << "Enter element you want to search in array: ";
    cin >> key;
    cout << endl;
    linearSearch(a, key, size);
    return 0;
}