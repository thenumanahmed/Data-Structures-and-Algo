#include<iostream>
#include<list>
#include<string>


using namespace std;

class Folder {
	string name;
	Folder* parent = NULL;
	list<Folder*> subFolders;
public:
	Folder(string s, Folder* p = nullptr) {
		name = s;
		parent = p;
	}
	void addFolder(string name = "") {
		if (name == "") {
			string name;
			cout << "Enter the name of the folder: ";
			getline(cin, name);
		}
		subFolders.push_back(new Folder(name, this));
	}
	void displaySubFolders() {
		if (subFolders.empty())
			cout << endl << " Empty Folder" << endl;
		else {
			for (auto i = subFolders.begin(); i != subFolders.end(); i++) {
				cout << (*i)->name << endl;
			}
			cout << endl;
		}
	}
	Folder* getParent() {
		return parent;
	}
	string getName() {
		return name;
	}
	Folder* findSubFolder(string s) {
		for (auto i = subFolders.begin(); i != subFolders.end(); i++) {
			if ((*i)->name == s) return *i;
		}return nullptr;
	}
	char displayMenu() {
		cout << "		In Folder " << name << endl;
		displaySubFolders();
		char choice;
		cout << "1- Add Folder. " << endl;
		cout << "2- Open sub Folder. " << endl;
		cout << "3- Delete sub Folder. " << endl;
		cout << "4- Back. " << endl;
		cout << "5- Exit. " << endl;
		do {
			cout << "Enter choice: " ;
			cin >> choice;
			if (choice > '5' || choice < '1') {
				cout << "Invalid Choice Entered... " << endl;
			}
		} while (choice > '5' || choice < '1');
		return choice;
	}
	void deleteSubFolder(string s) {
		for (auto i = subFolders.begin(); i != subFolders.end(); i++) {
			if ((*i)->name == s) {
				subFolders.remove(*i);
				break;
			}
		}
	}
};

int main() {
	Folder* directory = new Folder("A");
	directory->addFolder("A/A");
	directory->addFolder("A/B");
	directory->addFolder("A/C");
	directory->addFolder("A/D");
	directory->addFolder("A/E");
	directory->addFolder("A/F");
	Folder* AA = directory->findSubFolder("A/A");
	Folder* AB = directory->findSubFolder("A/B");
	Folder* AC = directory->findSubFolder("A/C");
	Folder* AD = directory->findSubFolder("A/D");
	Folder* AE = directory->findSubFolder("A/E");
	Folder* AF = directory->findSubFolder("A/F");

	AA->addFolder("A/A/A");
	AA->addFolder("A/A/B");
	AA->addFolder("A/A/C");
	AA->addFolder("A/A/D");
	AA->addFolder("A/A/E");
	AA->addFolder("A/A/F");
	
	AB->addFolder("A/B/A");
	AB->addFolder("A/B/B");
	AB->addFolder("A/B/C");
	AB->addFolder("A/B/D");
	AB->addFolder("A/B/E");
	AB->addFolder("A/B/F");

	AC->addFolder("A/C/A");
	AC->addFolder("A/C/B");
	AC->addFolder("A/C/C");
	AC->addFolder("A/C/D");
	AC->addFolder("A/C/E");
	AC->addFolder("A/C/F");

	AD->addFolder("A/D/A");
	AD->addFolder("A/D/B");
	AD->addFolder("A/D/C");
	AD->addFolder("A/D/E");
	AD->addFolder("A/D/F");

	AE->addFolder("A/E/A");
	AE->addFolder("A/E/C");
	AE->addFolder("A/E/D");
	AE->addFolder("A/E/E");
	AE->addFolder("A/E/F");

	AF->addFolder("A/F/A");
	AF->addFolder("A/F/B");
	AF->addFolder("A/F/C");
	AF->addFolder("A/F/D");
	AF->addFolder("A/F/F");

	Folder* temp = directory;
	while (true) {
		cout << endl << endl;
		char choice = temp->displayMenu();
		cin.ignore();
		if (choice == '1') {
			string s;
			cout << "Enter the name of the folder: ";
			getline(cin, s);
			if (temp->findSubFolder(s)) {
				cout << "Folder with name " << s << " already exists. ";
			}
			else {
				temp->addFolder(s);
			}
		}
		else if (choice == '2') {
			string s;
			cout << "Enter the name of the folder: ";
			getline(cin, s);
			if (temp->findSubFolder(s)) {
				temp = temp->findSubFolder(s);
			}
			else {
				cout << "No Folder with name " << s << " found. ";
			}
		}
		else if (choice == '3') {
			string s;
			cout << "Enter the name of the folder: ";
			getline(cin, s);
			if (temp->findSubFolder(s)) {
				temp->deleteSubFolder(s);
			}
			else {
				cout << "No Folder with name " << s << " found. ";
			}
		}
		else if (choice == '4') {
			if (temp->getParent()) temp = temp->getParent();
			else { cout << "In main Directory can't go back... " << endl; }
		}
		else if (choice == '5')
			break;
	}



	return 0;
}