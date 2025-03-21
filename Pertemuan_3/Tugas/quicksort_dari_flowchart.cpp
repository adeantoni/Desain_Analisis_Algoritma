#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void swap(int arr[], int pos1, int pos2)
{
    int temp;
    temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

int partition(int arr[], int left, int right)
{
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }

    swap(arr, i + 1, right);

    return i + 1;
}

void quickSort(int arr[], int left, int right)
{
    int batch_size = right - left + 1;

    if (batch_size == 1)
    {
        return;
    }

    if (left < right)
    {
        int pivot_index = partition(arr, left, right);

        quickSort(arr, left, pivot_index - 1);
        quickSort(arr, pivot_index + 1, right);
    }
}

int main()
{
    int n;
    cout << "Input array size: ";
    cin >> n;
    cin.ignore();

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int val;
        cout << "Input value-" << i + 1 << " : ";  
        cin >> val;
        arr[i] = val;
    }

    cout << "Unsorted array: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}