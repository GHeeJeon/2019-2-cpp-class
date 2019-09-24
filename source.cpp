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
		cout << "이름과 전화 번호를 입력해 주세요" << endl;
		for (int i = 0; i < size; i++) {
			cout << "사람 " << i + 1 << ">> ";
			cin >> name >> tel;
			(p + i)->set(name, tel);
		}
	}
	void show() {
		cout << "모든 사람의 이름은 ";
		for (int i = 0; i < size; i++) {
			cout << (p + i)->getName() << " ";
		}
		cout << endl;
	}
	void search() {
		string name;
		cout << "전화번호 검색합니다. 이름을 입력하세요>>";
		cin >> name;

		int i = 0;
		while (i < size) {
			if (name == (p + i)->getName()) {
				cout << "전화 번호는 " << (p + i)->getTel() << endl;
				break;
			}
			i++;
		}
		if (i == size) cout << "없는 사람입니다" << endl;
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
	cout << "사람 수를 입력하세요(n값): ";
	cin >> n;
	PersonManager pm(n);
	pm.show();
	pm.search();
}

void Person::set(string name, string tel) {
	this->name = name;
	this->tel = tel;
}