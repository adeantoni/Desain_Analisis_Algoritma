#include <iostream>
using namespace std;

// merupakan contoh penerapan constructor
class contoh
{
    private:
        int nilai; // variable nilai yang ada pada class
    
    public:
        contoh (int n) // constructor class contoh
        {
            nilai = n;
        }

        int getNum() // function untuk mengambil variable nilai
        {
            return nilai;
        }
};

int main()
{
    contoh obj(10); // deklarasi class contoh yaitu "obj" dengan parameter 10
    cout << "Nilai yang diinput: " << obj.getNum() << endl; // memanggil fungsi yang ada pada objek "obj"

    return 0;
}   
