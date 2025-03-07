#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<string> &vec)
{
    for (int i = 1; i < vec.size() - 1; i++)
    {
        string key = vec[i];
        int j = i - 1;
        while(j >= 0 && vec[j] > key)
        {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

int main()
{
    vector<string> books;
    int n;
    string book;

    cout << "Masukkan jumlah buku: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cout << "Masukkan judul buku: ";
        getline(cin, book);
        books.push_back(book);
    }

    insertion_sort(books);

    cout << "Buku setelah di sort secara lexicographical: " << endl;

    for (auto book : books)
    {
        cout << book << endl;
    }

    return 0;
}