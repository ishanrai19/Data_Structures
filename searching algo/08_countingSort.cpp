#include <iostream>
using namespace std;
int largest(int arr[], int s)
{
    int max = arr[0];
    for (int i = 1; i < s; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
void countingSort(int input_arr[], int size, int rangeOfCountArr)
{
    int output_arr[size];

    // int rangeOfCountArr = largest(input_arr, size);
    int count_arr[rangeOfCountArr];
    // initializing elements of count array to zero for the first time
    for (int a = 0; a < rangeOfCountArr; a++)
    {
        count_arr[a] = 0;
    }
    /*creating count array:storing number of time elements occur and storing it at index in count array which is equal to its value
    (just like frequency in statistics)*/
    for (int j = 0; j < size; j++)
    {
        //gives exact position of where elements in output array needs to be placed
        ++count_arr[input_arr[j]];
    }

    //creating cumulative count array by adding previous element with current one
    for (int i = 1; i < rangeOfCountArr; i++)
    {
        count_arr[i] = count_arr[i] + count_arr[i - 1];
    }
    //placing elements from input array to output array in sorted manner
    for (int b = 0; b < size; b++)
    {
        output_arr[--count_arr[input_arr[b]]] = input_arr[b];
    }
    // copy output array elements to input array
    for (int i = 0; i < size; i++)
    {

        input_arr[i] = output_arr[i];
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
    int range = 100;
    cout << "Enter size of your array: " << endl;
    cin >> size;
    int array[size];
    cout << "Enter " << size << " elements in your array in range 0-99:" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    cout << "Before counting sort: ";
    display(array, size);
    countingSort(array, size, range);
    // countingSort(array, size, largest(array, size));
    cout << "\nAfter counting sort: ";
    display(array, size);
    // cout << largest(array, size);
    return 0;
}