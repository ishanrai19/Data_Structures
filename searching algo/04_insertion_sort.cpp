#include <iostream>
using namespace std;
void insertionSort(int a[], int size)
{
    int key, j;
    for (int i = 0; i < size; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}
int main()
{
    int arr[] = {12, 4, 56, 9, 2, 1, 43, 10};
    int size = 8;
    cout << "\nArray before Insertion sort: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    insertionSort(arr, size);
    cout << "\nArray after Insertion sort: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}