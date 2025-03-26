#include <iostream>
using namespace std;

class userData
{
	private:
		string username;
		int age;
		string NPM;

	public:
		userData(string name, int age, string NPM)
		{	
			this -> username = name;
			this -> age = age;
			this -> NPM = NPM;
		}
	
		void getUserData()
		{
			cout << "Nama : " << username << endl;
			cout << "Age : " << age << endl;
			cout << "NPM : " << NPM << endl;
		}

		~userData()
		{
			cout << "Initialization success." << endl;
		}

};		

int main()
{
	userData user1("Ade", 20, "242310010");

	user1.getUserData();

	return 0;
}