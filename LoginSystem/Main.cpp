#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsLoggedIn()
{
	string username, password, un, pw;
	cout << "Enter username: "; cin >> username;
	cout << "Enter password: "; cin >> password;

	ifstream read(username + ".txt");
	getline(read, un);
	getline(read, pw);

	return (un == username && pw == password);
}

int main()
{
	int choice;

	cout << "1: Register\n2: Login\nYour choice: "; cin >> choice;
	if (choice == 1)
	{
		string username, password;

		cout << "Select a username: "; cin >> username;
		cout << "Select a password: "; cin >> password;

		ifstream myFile(username + ".txt");
		if (!myFile.fail())
		{
			cout << "Username is already taken" << endl;
			main();
		}
		else
		{
			ofstream file;
			file.open(username + ".txt");

			if (!file.is_open()) {
				cout << "Account not created!" << endl;
				file.close();
				main();
			}
			else
			{
				file << username << endl << password;
				file.close();
				cout << "Account created!" << endl;
				main();
			}
		}
	}
	else if (choice == 2)
	{
		bool status = IsLoggedIn();

		if (!status)
		{
			cout << "Incorrect username or password" << endl;
			main();
		}
		else
		{
			cout << "Succefully logged in!" << endl;
			system("PAUSE");
			return 1;
		}
	}
	else
	{
		cout << "Unknown choice give" << endl;
		main();
	}
}