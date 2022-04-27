#include <iostream>
using namespace std;
int getMax(int arr[], int s)
{
    int max = arr[0];
    for (int i = 1; i < s; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
void countingSort(int a[], int s, int d)
{
    int output_arr[s];
    int count_arr[10] = {0}; // initializing all elements of count sort to zero
    // int range = 10;//for decimal numbers
    for (int i = 0; i < s; i++)
    { //incrementing value in count array by taking count of digits starting form right to left or LSB to MSB
        count_arr[(a[i] / d) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    { //creating cumulative count array
        // count_arr[i] = count_arr[i - 1] + count_arr[i];
        count_arr[i] += count_arr[i - 1];
    }

    for (int i = s - 1; i >= 0; i--)
    {
        output_arr[count_arr[(a[i] / d) % 10] - 1] = a[i];
        count_arr[(a[i] / d) % 10]--;
    }
    for (int i = 0; i < s; i++)
    {
        a[i] = output_arr[i];
    }
}
void radixSort(int input_arr[], int size)
{
    int m = getMax(input_arr, size);
    for (int div = 1; (m / div) > 0; div *= 10)
    {
        // counting sort for every digit
        countingSort(input_arr, size, div);
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
    cout << "Enter " << size << " elements in your array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    cout << "Before Radix sort: ";
    display(array, size);

    radixSort(array, size);

    cout << "\nAfter Radix sort: ";
    display(array, size);
    return 0;
}