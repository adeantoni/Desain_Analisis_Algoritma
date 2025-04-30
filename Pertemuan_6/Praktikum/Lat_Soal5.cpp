/*
Kelompok 5
- Ade Antoni Sugiarto
- Yunita Puspitasari
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Mahasiswa
{
    public:
        string nama;
        float ipk;
};

int sequential_search(Mahasiswa *arr, string target, int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        if (target == arr[i].nama)
        {
            return i;
        }
    }

    return -1;
}

void selectionSort(Mahasiswa arr[], int n)
{
    int i, j, maxIndex;
    float temp;
    for (i = 0; i < n - 1; i++)
    {
        maxIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j].ipk > arr[maxIndex].ipk)
            {
                maxIndex = j;
            }   
        }

        temp = arr[maxIndex].ipk;
        arr[maxIndex].ipk = arr[i].ipk;
        arr[i].ipk = temp;
    }
}

int main()
{
    int jumlah_siswa;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlah_siswa;

    Mahasiswa mahasiswa[jumlah_siswa];

    for (int i = 0; i < jumlah_siswa; i++)
    {
        string namaSiswa;
        float ipk;

        cin.ignore();
        cout << "Masukkan nama mahasiswa: ";
        getline(cin, namaSiswa);

        cout << "Masukkan IPK: ";
        cin >> ipk;
        
        mahasiswa[i].nama = namaSiswa; mahasiswa[i].ipk = ipk;
    }

    selectionSort(mahasiswa, jumlah_siswa);

    string targetNama;
    cin.ignore();
    cout << "Masukkan nama yang ingin dicari: ";
    getline(cin, targetNama);

    int indexDitemukan = sequential_search(mahasiswa, targetNama, jumlah_siswa);

    if (indexDitemukan == -1)
    {
        cout << "DATA TIDAK DITEMUKAN";
    }
    else
    {
        cout << "DATA DITEMUKAN DI INDEX KE-" << indexDitemukan;
    }

    return 0;
}