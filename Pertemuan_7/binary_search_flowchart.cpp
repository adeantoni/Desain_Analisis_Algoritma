#include <iostream>
using namespace std;

int main()
{
    const int x = 5;
    int input[x] = {0, 6, 12, 18, 24};
    
    int target;
    cout << "Masukkan target data yang dicari: ";
    cin >> target;

    int tm = 0, R = x - 1, L = 0;
    for (int r = x - 1; r >= 1; r--)
    {
        int midIndex = L + (R - L) / 2;
        int mid = input[midIndex];
        if (mid == target)
        {
            cout << "Bilangan ditemukan";
            return 0;
        }
        else if (target > mid)
        {
            L = midIndex + 1;
        }
        else if (target < mid)
        {
            R = midIndex - 1;
        }
    }

    cout << "Bilangan tidak ditemukan";
    return 0;
}