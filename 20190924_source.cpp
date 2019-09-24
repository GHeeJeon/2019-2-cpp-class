#include <iostream>
#include <string>
using namespace std;

class Person {
	string name, tel;

public:
	Person();
	string getName() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel);
};

class PersonManager {
	Person* p;
	int size;

public:
	PersonManager(int n) {
		string name, tel;
		size = n;
		p = new Person[size];
		cout << "Enter names and phone numbers" << endl;
		for (int i = 0; i < size; i++) {
			cout << "Person " << i + 1 << ">> ";
			cin >> name >> tel;
			(p + i)->set(name, tel);
		}
	}
	void show() {
		cout << "names of phonebook: ";
		for (int i = 0; i < size; i++) {
			cout << (p + i)->getName() << " ";
		}
		cout << endl;
	}
	void search() {
		string name;
		cout << "Searching name initiate. Please enter the name: ";
		cin >> name;

		int i = 0;
		while (i < size) {
			if (name == (p + i)->getName()) {
				cout << "phone number: " << (p + i)->getTel() << endl;
				break;
			}
			i++;
		}
		if (i == size) cout << "Empty" << endl;
	}
	~PersonManager() {
		delete[] p;
		cout << "bye" << endl;
	}
};


Person::Person() {
	this->name = "";
	this->tel = "";
}

int main() {
	int n;
	cout << "Enter the number for phonebook(N value): ";
	cin >> n;
	PersonManager pm(n);
	pm.show();
	pm.search();
}

void Person::set(string name, string tel) {
	this->name = name;
	this->tel = tel;
}