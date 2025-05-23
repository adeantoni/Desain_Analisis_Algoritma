#include <iostream>
#include <string>
using namespace std;

class Hewan
{
    public:
        virtual void bersuara()
        {
            cout << "..." << endl;
        }

        virtual void lari()
        {
            cout << "Running..." << endl;
        }

};

class Kucing : public Hewan
{
    public:
        
};

class Kambing : public Hewan
{
    public:
        void bersuara() 
        {
            cout << "mbekk" << endl;
        }
};

int main()
{
    Hewan *h1 = new Kucing();
    Hewan *h2 = new Kambing();

    h1 -> bersuara();
    h1 -> lari();

    h2 -> bersuara();
    h2 -> lari();
}