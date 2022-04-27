#include <iostream>
using namespace std;
void bubbleSort(int a[], int s)
{
    int count = 0;
    for (int i = 0; i < s; i++)
    {

        count++;
        for (int j = 0; j < s - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    cout << "\nRounds = " << count << endl;
}
void omptimizedBubbleSort(int a[], int s)
{
    int count = 0;
    for (int i = 0; i < s; i++)
    {
        bool flag = false;
        count++;
        for (int j = 0; j < s - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                flag = true;
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        if (flag == false)
        {
            break;
        }
    }
    cout << "\nRounds = " << count << endl;
}
int main()
{
    int arr[] = {213, 56, 4, 1, 23, 49, 98, 67, 73};
    int size = 9;
    cout << "Before Bubble sort: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    bubbleSort(arr, size);
    // omptimizedBubbleSort(arr, size);
    cout << "\nAfter Bubble sort: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
