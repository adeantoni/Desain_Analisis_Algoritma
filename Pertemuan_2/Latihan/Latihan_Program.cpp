#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Masukkan total barang belanja (angka): ";
    cin >> n;
    cin.ignore();

    string daftarBarang[n];
    string barang;

    for (int i = 0; i < n; i++)
    {
        cout << "Barang ke-" << i + 1 << " : ";
        cin >> barang;
        daftarBarang[i] = barang;
    }

    cout << "\nDaftar Barang Belanja\n";
    cout << "----------------------------\n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". " << daftarBarang[i] << '\n';
    }
    cout << "----------------------------";

    return 0;
};