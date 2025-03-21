#include <iostream>
using namespace std;

// menampilkan value array
void show(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}

void merge(int arr[], int l, int m, int r, int size)
{
    int x, y, z;
    int n1 = m - l + 1; // digunakan untuk iterasi untuk memecah array section kiri dengan n1 sebagai batas kanan
    // digunakan penambahan satu karena kita akan menggunakan logic < (exclusive), jika ingin menggunakan logic <= maka tidak perlu
    // menambahkan dengan 1
    int n2 = r - m; // digunakan untuk iterasi untuk memecah array pada section kanan dengan n2 sebagai batas kiri

    int L[n1], R[n2]; // membuat array sementara untuk menyimpan value pada array section kiri dan kanan

    for (x = 0; x < n1; x++) // looping dari kiri sampai tengah
        L[x] = arr[l + x]; // menyimpan array bagian kiri pada array sementara
    for (y = 0; y < n2; y++)  // looping dari tengah sampai kanan
        R[y] = arr[m + 1 + y]; // menyimpan array bagian kanan pada array sementara
        /* digunakan + 1 disini agar array tidak overlap satu sama lain, contoh
        [4, 6, 2, 3, 1, 7], karena m = left + (right - left) / 2, maka m = 2 yaitu (2),
        anggap n1 = m - l + 1 = 3, maka ia akan loop sampai value x mencapai 2, nah dikarenakan value 2 ini sudah diambil
        oleh array kiri, maka perlu ditambahkan 1 agar tidak overlap satu sama lain (tidak terjadi duplikat data) */
        
    x = 0; // digunakan untuk menandai target posisi pada array kiri
    y = 0; // digunakan untuk menandai target posisi pada array kanan
    z = l; // z digunakan untuk menandai target posisi yang akan ditukar untuk array asli

    while (x < n1 && y < n2) // proses sorting yang sebenarnya, melibatkan variable x dan y
    {
        if (L[x] <= R[y]) // apakah array kiri pada posisi L lebih kecil atau sama dengan array kanan pada posisi R
        {
            arr[z] = L[x];   // tukar array asli pada posisi z dengan array kiri pada posisi x
            x++; // lakukan increment pada x
        }
        else // jika array kiri pada posisi L lebih besar daripada array kanan pada posisi R
        {
            arr[z] = R[y]; // tukar array asli pada posisi z dengan array kanan pada posisi y
            y++; // lakukan increment pada y
        }
        z++; // lakukan increment pada z untuk maju pada value array asli selanjutnya
        show(arr, size); // melihat perubahan yang terjadi pada array
    }

    /* setelah proses tersebut selesai, array asli masih berantakan karena banyak variabel duplikat dikarenakan
    belum semua array pada kiri dan kanan dipindahkan ke array asli, lalu bagaimana memindahkannya?
    jawabannya adalah dibawah ini, dikarenakan kita memiliki variabel x dan y sebagai flag/penanda sudah sampai mana array pada bagian
    kiri atau kanan telah di iterasi/dipindahkan, maka kita hanya perlu menggunakan while loop sampai variabel x dan y mencapai batas */

    while (x < n1) // digunakan untuk memeriksa apakah masih ada value pada array kiri yang belum dipindahkan ke array asli
    {
        arr[z] = L[x];
        x++;
        z++;
        show(arr, size);
    }

    while (y < n2) // digunakan untuk memeriksa apakah masih ada value pada array kanan yang belum dipindahkan ke array asli
    {
        arr[z] = R[y];
        y++;
        z++;
        show(arr,size);
    }
}

void mergeSort(int arr[], int l, int r, int size)
{
    if (l < r) // cek apabila posisi right tidak lebih kecil daripada left
    {
        int m = l + (r - l) / 2; // membuat posisi penengah

        mergeSort(arr, l, m, size);  // memisahkan array untuk bagian kiri
        mergeSort(arr, m + 1, r, size); // memisahkan array untuk bagian kanan

        merge(arr, l, m, r, size); // the actual sorting, sorting yang terjadi pada bagian sini
    }
}

int main()
{
    int size;
    cout << "\nMasukan Banyak Data : ";
    cin >> size;

    int arr[size];

    for (int i = 0; i < size; ++i)
    {
        cout << "\nMasukan Data array ke-" << i << " : ";
        cin >> arr[i];
    }

    mergeSort(arr, 0, size - 1, size);

    cout << "Hasil\n";
    show(arr, size);

    return 0;
}