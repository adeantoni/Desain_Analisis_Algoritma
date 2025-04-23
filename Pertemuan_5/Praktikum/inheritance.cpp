#include <iostream>
using namespace std;

// class induk
class BangunDatar
{
    protected:
        int lebar, tinggi;
    
    public:
        void setValue(int a, int b)
        {
            lebar = a;
            tinggi = b;
        }
};

// class turunan
class PersegiPanjang : public BangunDatar 
{
    public:
        int getValue()
        {
            return (lebar * tinggi);
        }
};

// class turunan
class Segitiga : public BangunDatar
{
    public:
        int getValue()
        {
            return (lebar * tinggi / 2);
        }
};

// program utama
int main()
{
    // inisialisasi objek
    PersegiPanjang persegi_panjang;
    Segitiga segitiga;

    // inisialisasi nilai
    persegi_panjang.setValue(4, 5);
    segitiga.setValue(10, 5);

    // mendapatkan nilai kembalian
    cout << persegi_panjang.getValue() << endl;
    cout << segitiga.getValue() << endl;

    return 0;
}