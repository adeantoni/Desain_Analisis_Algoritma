#include <iostream>
#include <string>
using namespace std;

class pelajaran
{
    public:
        pelajaran()
        {
            cout << "Ini adalah materi C++ tentang Constructors!";
        }
};

int main()
{
    pelajaran obj;
    return 0;
}