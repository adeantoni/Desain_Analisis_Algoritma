#include <iostream>
using namespace std;

// fungsi ini digunakan untuk menukar value array
void swap(int arr[], int pos1, int pos2)
{
    int temp;
    temp = arr[pos1];
    arr[pos1] = arr[pos2];
    arr[pos2] = temp;
}

int partition(int arr[], int low, int high, int pivot, int size)
{
    int i = low;
    int j = low;
    // i dan j digunakan untuk melakukan iterasi pada setiap value pada array

    while(i <= high) // lakukan loop sampai i mencapai pivot
    {
        if(arr[i] > pivot) // jika value array pada index i lebih besar dari pivot,
        {
            i++; // maka increment i
        }
        else // namun jika value array pada index i lebih kecil dari pivot,
        {
            swap(arr, i, j); // maka tukar value array pada index i dengan value array pada index j
            i++; 
            j++;
            // lakukan increment pada kedua index i dan j

            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << "\t"; // menampilkan array
            }
            cout << endl;
        }
    }

    // setelah sort selesai, maka fungsi akan mengembalikan index j - 1 untuk dijadikan penengah untuk membagi array menjadi 2 section
    return j-1;
}

void quickSort(int arr[], int low, int high, int size)
{
    if (low < high) // cek apabila...
    {
        int pivot = arr[high]; // mengambil nilai pivot dengan nilai array paling kanan
        int pos = partition(arr, low, high, pivot, size);  // menentukan posisi untuk memisahkan array menjadi dua bagian + sorting terjadi disini
        
        quickSort(arr, low, pos - 1, size); // sorting pada section kiri
        quickSort(arr, pos + 1, high, size); // sorting pada section kanan
    }
}

int main()
{
    int n;
    cout << "Tentukan panjang array: ";
    cin >> n;
    
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // menampilkan array
    }

    quickSort(arr, 0, n - 1, n); // melakukan quicksort
    cout << "Berikut adalah array yang telah di sortir: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t"; // menampilkan array yang telah di sortir
    }

    return 0;
}

// basically sorting ini akan melakukan proses untuk bagian kiri dulu, lalu setelah kiri selesai semua maka akan dilanjut ke
// sorting paling kiri percabangan kanan (dari paling bawah/rekursif terdalam), dan akan melakukan semua percabangan kanan 
// setelah semua percabangan kiri selesai
// setelah bagian kiri selesai lanjutlah sorting pada bagian kanan, dan algoritmanya tetap sama yaitu semua bagian kiri pada array kanan
// dilanjut dengan bagian kanan setelah selesai