#include <iostream>
#include <cstdio>
using namespace std;

const int SIZE = 20;

class locket_queue
{
    private:
        int nomor_antri[SIZE];
        string nama_pengantri[SIZE];

        int front_index = 0;
        int rear_index = SIZE - 1;
        int total_value = 0;
        int nomor_antrian = 1;
    
    public:
        void enqueue(string nama)
        {
            if (total_value == SIZE)
            {
                cout << "Antrian penuh!" << endl;
                return;
            }

            rear_index = (rear_index + 1) % SIZE;
            nomor_antri[rear_index] = nomor_antrian;
            nama_pengantri[rear_index] = nama;
            total_value++;
            nomor_antrian++;
        }

        int dequeue()
        {
            if (total_value == 0)
            {
                cout << "Antrian kosong!" << endl;
                return -1;
            }

            int nomor = nomor_antri[front_index];
            front_index = (front_index + 1) % 100;
            total_value--;
            return nomor;
        }

        void resetQueue()
        {
            front_index = 0;
            rear_index = SIZE - 1;
            total_value = 0;
            nomor_antrian = 1;
        }

        void showQueue()
        {
            if (total_value == 0)
            {
                cout << "Antrian kosong." << endl;
                return;
            }
            
            for (int i = front_index; i <= rear_index; i++)
            {
                cout << "Antrian ke-" << nomor_antri[i] << " : " << nama_pengantri[i] << endl;
            }
        }
};

bool inArray(int target, int *arr, int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        if (target == arr[i]) return true;
    }

    return false;
}

int main()
{
    locket_queue LQ;
    int user_input;
    int valid_inputs[4] = {1, 2, 3, 4};

    do
    {
        cout << "Apa yang ingin dilakukan: " << endl;
        cout << "(1) Masukkan antrian" << endl;
        cout << "(2) Keluarkan antrian" << endl;
        cout << "(3) Reset antrian" << endl;
        cout << "(4) Tampilkan antrian" << endl;

        cin >> user_input;
        cin.ignore();

        if (user_input == 1)
        {
            string nama;
            cout << "Masukkan nama yang ingin dimasukkan ke antrian: " << endl;
            getline(cin, nama);

            LQ.enqueue(nama);
            cout << "Nama berhasil masuk antrian." << endl;
        }
        
        else if (user_input == 2)
        {
            int nomor = LQ.dequeue();
            if (nomor == -1) continue;
            cout << "Pengantri dengan nomor: " << nomor << " keluar." << endl;
        }

        else if (user_input == 3)
        {
            LQ.resetQueue();
            cout << "Antrian telah direset." << endl;
        }

        else if (user_input == 4)
        {
            LQ.showQueue();
        }

        cout << endl;
        
        system("pause");
        system("cls");
    } while (inArray(user_input, valid_inputs, SIZE));
    

    return 0;
}