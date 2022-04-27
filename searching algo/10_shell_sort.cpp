#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n)
{
    int totalPasses = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                // totalPasses++;
            }
            totalPasses++;
        }
        totalPasses++;
    }
    cout << "Total passes = " << totalPasses << endl;
}
void shellSort(int arr[], int n)
{
    int totalPasses = 0;
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int j = gap; j < n; j++)
        {
            int temp = arr[j];
            int i = 0; //because we want its scope outside the loop also
            for (i = j; i >= gap && arr[i - gap] > temp; i -= gap)
            {
                arr[i] = arr[i - gap];
            }
            arr[i] = temp;
            totalPasses++;
        }
        totalPasses++;
    }
    cout << "Total passes = " << totalPasses << endl;
}
int main()
{
    int size;
    cout << "Enter size of your array: ";
    cin >> size;
    int arr[size], arr2[size];
    cout << "\nEnter " << size << " elements in your array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
        arr2[i] = arr[i];
    }
    cout << "Before sort: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    // bubbleSort(arr, size);
    cout << "\nAfter SHELL sort: " << endl;
    shellSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n\n\nAfter BUBBLE sort: " << endl;
    bubbleSort(arr2, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}