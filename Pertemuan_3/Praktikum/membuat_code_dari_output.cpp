#include <iostream>
#include <conio.h>
using namespace std;

string genap_ganjil(int val)
{
    if (val % 2 == 0){return "GENAP";}
    else{return "GANJIL";}
}

int main()
{
    int array[5];

    cout << "Masukkan " << sizeof(array) / 4 << " angka:" << endl;

    for (int i = 0; i < sizeof(array)/4; i++)
    {
        int val;
        cin >> val;
        array[i] = val;
    }

    cout << "\nIsi array dan statusnya:" << endl;
    
    for (int i = 0; i < sizeof(array) / 4; i++)
    {
        cout << "angka[" << i << "] = " << array[i] << " adalah " << genap_ganjil(array[i]) << endl;
    }
    
    getch();
    return 0;
}