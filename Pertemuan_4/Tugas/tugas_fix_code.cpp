#include <iostream>
using namespace std;

class Mahasiswa
{
	private:
		string nama;
		string npm;
		double ipk;
	
	public:
		Mahasiswa(string n, string id, double i)
		{
			nama = n;
			npm = id;
			ipk = i;	
		}
		
		void tampilkanData()
		{
			cout << "Nama: " << nama << "\nNPM: " << npm << "\nIPK: " << ipk << "\n\n";
		}
		
		~Mahasiswa()
		{
			cout << "Data mahasiswa " << nama << " telah dihapus.\n";
		}
};

int main()
{
	int jumlah;
	
	cout << "Masukkan jumlah mahasiswa: ";
	cin >> jumlah;
	
	Mahasiswa* daftarMahasiswa[jumlah];
	
	for (int i = 0; i < jumlah; i++)
	{
		string nama, npm;
		double ipk;
		
		cout << "\nMasukkan data mahasiswa ke-" << (i + 1) << ":\n";
		cout << "Nama: ";
		cin.ignore();
		getline(cin, nama);
		
		cout << "NPM: ";
		cin.ignore();
		cin >> npm;
		
		cout << "IPK: ";
		cin.ignore();
		cin >> ipk;
		
		daftarMahasiswa[i] = new Mahasiswa(nama, npm, ipk);
	}
	
	cout << "\nDaftar Mahasiswa:\n";
	for (int i = 0; i < jumlah; i++)
	{
		daftarMahasiswa[i] -> tampilkanData();
	}
	
	for (int i = 0; i < jumlah; i++)
	{
		delete daftarMahasiswa[i];
	}
	
	return 0;
}
