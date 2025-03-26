#include <iostream>
using namespace std;

class buku
{
    private:
        string judulBuku;

    public:
        buku(string judul)
        {
            judulBuku = judul;
            cout << "Buku " << judulBuku << " ditambahkan." << endl;
        }

        ~buku()
        {
            cout << "Buku " << judulBuku << " dihapus." << endl;
        }
};

int main()
{
    string judulBuku;
    cout << "Masukkan judul buku: ";

    getline(cin, judulBuku);

    buku buku1(judulBuku);

    return 0;
}