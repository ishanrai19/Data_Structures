#include <iostream>
using namespace std;
int partition(int a[], int start, int end)
{
    int pivot = a[end];
    int pIndex = start;
    for (int i = start; i < end; i++)
    {
        if (a[i] < pivot)
        { //swap(a[i],pivot)
            int temp = a[i];
            a[i] = a[pIndex];
            a[pIndex] = temp;
            pIndex++;
        }
    }
    //swap (a[e],a[pIndex])
    int temp = a[end];
    a[end] = a[pIndex];
    a[pIndex] = temp;

    return pIndex;
}
void quickSort(int arr[], int s, int e)
{
    if (s < e)
    {
        int p = partition(arr, s, e);
        quickSort(arr, s, (p - 1));
        quickSort(arr, (p + 1), e);
    }
}
void display(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int size;
    cout << "Enter size of your array: " << endl;
    cin >> size;
    int array[size];
    cout << "Enter " << size << " elements in your array :" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    cout << "Before quick sort: ";
    display(array, size);
    quickSort(array, 0, (size - 1));
    cout << "\nAfter quick sort: ";
    display(array, size);

    return 0;
}