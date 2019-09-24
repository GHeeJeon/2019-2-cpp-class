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
		cout << "�̸��� ��ȭ ��ȣ�� �Է��� �ּ���" << endl;
		for (int i = 0; i < size; i++) {
			cout << "��� " << i + 1 << ">> ";
			cin >> name >> tel;
			(p + i)->set(name, tel);
		}
	}
	void show() {
		cout << "��� ����� �̸��� ";
		for (int i = 0; i < size; i++) {
			cout << (p + i)->getName() << " ";
		}
		cout << endl;
	}
	void search() {
		string name;
		cout << "��ȭ��ȣ �˻��մϴ�. �̸��� �Է��ϼ���>>";
		cin >> name;

		int i = 0;
		while (i < size) {
			if (name == (p + i)->getName()) {
				cout << "��ȭ ��ȣ�� " << (p + i)->getTel() << endl;
				break;
			}
			i++;
		}
		if (i == size) cout << "���� ����Դϴ�" << endl;
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
	cout << "��� ���� �Է��ϼ���(n��): ";
	cin >> n;
	PersonManager pm(n);
	pm.show();
	pm.search();
}

void Person::set(string name, string tel) {
	this->name = name;
	this->tel = tel;
}