#include <iostream>
using namespace std;
int binary_search(int a[], int size, int key)
{
    int low, high, mid;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == key)
        {
            return mid;
        }
        if (a[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1, 7, 9, 11, 20, 26, 69, 72, 80, 102, 109, 150};
    int key, size = sizeof(arr) / sizeof(int);
    cout << "Array : ";
    for (int i = 0; i < 12; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Enter element you want to search in array :";
    cin >> key;
    int result = binary_search(arr, size, key);
    cout << "Element " << key << " was found at index " << result << endl;

    return 0;
}