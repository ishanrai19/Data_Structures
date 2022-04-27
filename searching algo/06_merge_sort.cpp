#include <iostream>
using namespace std;
void merge(int a[], int left, int mid, int right, int size)
{
    int i = left;
    int j = mid + 1;
    int k = left;
    int temp[size];
    while (i <= mid && j <= right)
    {
        if (a[i] <= a[j])
        {
            temp[k] = a[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }
    while (j <= right)
    {
        temp[k] = a[j];
        j++;
        k++;
    }
    for (int p = left; p <= right; p++)
    {
        a[p] = temp[p];
    }
}
void mergeSort(int array[], int l, int r, int s)
{
    if (l < r)
    {
        int m = (l + r) / 2; // m is mid index
        mergeSort(array, l, m, s);
        mergeSort(array, m + 1, r, s);
        merge(array, l, m, r, s);
    }
}
int main()
{
    int size;
    cout << "Enter size of the array: ";
    cin >> size;
    cout << "Enter elements of your array: " << endl;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << endl;
    // int size = 5;
    // int arr[size] = {5, 3, 6, 7, 1};

    cout << "Before Merge Sort: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    // func call
    mergeSort(arr, 0, size - 1, size);
    // mergeSort(arr, 0, 6);
    cout << "\nAfter Merge Sort: " << endl;
    for (int z = 0; z < size; z++)
    {
        cout << arr[z] << " ";
    }

    return 0;
}