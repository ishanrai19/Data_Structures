#include <iostream>
using namespace std;
void selectionSort(int arr[], int s)
{
    for (int i = 0; i < s - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < s; j++)
        {
            if (arr[j] < arr[min])
            // if (arr[j] > arr[min])// for descending order
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = 0;
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}
int main()
{
    int arr[] = {23, 67, 4, 8, 12, 49, 63, 100};
    int size = 8;
    cout << "Unsorted array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    selectionSort(arr, size);
    cout << "\nSorted array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}