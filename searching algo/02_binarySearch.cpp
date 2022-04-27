#include <iostream>
using namespace std;
int binarySearch(int key, int left, int right, int arr[])
{
    while (left <= right)
    {
        int mid = ((left + right) / 2);
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1, 4, 7, 11, 23, 45, 69, 100};
    int key;
    cout << "Enter element you want to search: ";
    cin >> key;
    cout << endl;
    int result = binarySearch(key, 0, 7, arr);
    if (result == -1)
    {
        cout << "Element not present in array" << endl;
    }
    else
    {
        cout << "Element present in array at index " << result << endl;
    }

    return 0;
}