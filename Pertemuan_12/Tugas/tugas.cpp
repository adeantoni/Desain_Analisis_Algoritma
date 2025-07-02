#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

class HashTable
{
    private:
        int size;
        int *hashTable;
        int totalValue = 0;
        
        int h1(int val)
        {
            return val % size;
        }

        int h2(int val)
        {
            int primeNum = 7;
            return primeNum - (val % primeNum);
        }

        int upperPrime(int val)
        {
            int val_ = val;

            if (val_ % 2 == 0)
            {
                val_++;
            }
            else
            {
                val_ = val_ + 2;
            }

            int isFound = false;
            while (!isFound)
            {
                bool isPrime = true;

                // cek jika val_ merupakan genap
                if (val_ % 2 == 0)
                {
                    isPrime = false;
                }
                else
                {
                    int i = 3;
                    // cek apakah i <= akar dari val_, dan apakah val_ masih prime setelah i di increment 2
                    while (isPrime && i <= sqrt(val_))
                    {
                        if (val_ % i == 0)
                        {
                            isPrime = false;
                        }

                        i = i + 2;
                    }
                }

                if (isPrime) isFound = true;
                else val_ = val_ + 2;
            }
            return val_;
        }

    public:
        HashTable(int size_ = 100)
        {
            // bikin sizenya jadi prima
            size = upperPrime(size_);
            hashTable = new int[size];

            // inisialisasi dulu biar gak error valuenya
            for (int i = 0; i < size; i++)
            {
                hashTable[i] = 0;
            }
        }

        void double_hashing(int val)
        {
            if (size == totalValue)
            {
                cout << "Tabel penuh." << endl;
                return;
            }

            int i = 0;
            bool success = false;

            while (i < size && !success)
            {
                int index = (h1(val) + i * h2(val)) % size;
                if (hashTable[index])
                {
                    i++;
                }
                else
                {
                    hashTable[index] = val;
                    success = true;
                    totalValue++;
                }
            }

            if (!success)
            {
                cout << "Error hashing " << val << '.' << endl;
            }
        }

        void printTable()
        {
            for (int i = 0; i < size; i++)
            {
                cout << hashTable[i] << ' ';
            }
            cout << endl;
        }

        void remove(int val)
        {
            if (totalValue == 0)
            {
                cout << "Tabel kosong." << endl;
                return;
            }

            int i = 0;
            bool success = false;

            while (i < size && !success)
            {
                int index = (h1(val) + i * h2(val)) % size;
                if (hashTable[index] == val)
                {
                    hashTable[index] = 0;
                    success = true;
                    cout << "Data berhasil di-remove." << endl;
                }
                else if (!hashTable[index])
                {
                    cout << "Error, tidak ada value " << val << '.' << endl;
                    return;
                }
                else
                {
                    i++;
                }
            }

            if (!success)
            {
                cout << "Error removing " << val << '.' << endl;
            }
        }
};
    
int main()
{
    int size;
    cout << "----------- Program double hashing sederhana -----------" << endl;
    cout << "Masukkan ukuran tabel: ";
    cin >> size;

    HashTable ht(size);
    
    vector<int> validInputs = {0, 1, 2, 3};
    int userInput;
    bool inputIsValid = false;

    do {
        do {
            cout << "Apa yang ingin anda lakukan:" << endl;
            cout << "(1) Input data" << endl;
            cout << "(2) Remove data" << endl;
            cout << "(3) Print Table" << endl;
            cout << "(0) Exit" << endl;
            cin >> userInput;

            inputIsValid = find(validInputs.begin(), validInputs.end(), userInput) != validInputs.end();

            if (!inputIsValid)
            {
                cout << "error";
            }
        } while (!inputIsValid);

        if (userInput == 1)
        {
            int totalVal;
            cout << "Masukkan berapa data yang ingin di-input: ";
            cin >> totalVal;

            for (int i = 0; i < totalVal; i++)
            {
                int temp;
                cout << "Masukkan data ke-" << i + 1 << ": ";
                cin >> temp;
                ht.double_hashing(temp);
            } 
        }

        else if (userInput == 2)
        {
            int temp;
            cout << "Masukkan data yang ingin di remove: ";
            cin >> temp;

            ht.remove(temp);
        }
        
        else if (userInput == 3)
        {
            cout << "Table:" << endl;
            ht.printTable();
        }

    } while (userInput != 0);

    return 0;
}