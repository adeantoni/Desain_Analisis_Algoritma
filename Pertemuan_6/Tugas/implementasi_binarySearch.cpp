#include <iostream>
using namespace std;

int partition(string *arr, int low, int high)
{
    char pivot = arr[high][0];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j][0] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(string *arr, int low, int high)
{
    if (low < high)
    {
        int pivot_index = partition(arr, low, high);

        quickSort(arr, low, pivot_index - 1);
        quickSort(arr, pivot_index + 1, high);
    }
}

int binarySearch()
{
    return 1;
}

int main()
{
    int size;
    cout << "Masukkan jumlah buku: ";
    cin >> size;

    string buku[size];
    for (int i = 0; i < size; i++)
    {
        string namaBuku;
        cout << "Input nama buku ke-" << i << " : ";
        cin.ignore();
        getline(cin, namaBuku);
        buku[i] = namaBuku;
    }


    quickSort(buku, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        cout << buku[i] << ' ';
    }

    return 0;
}