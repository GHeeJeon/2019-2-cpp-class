/*
// Practice 1
#include <iostream>
using namespace std;

int sum(int start_num, int end_num);

int main() {
	int n = { 0 };
	cout << "�� ���� �Է��ϼ���>";
	cin >> n;

	cout << "1����" << n << "������ ���� " << sum(1, n) << "�Դϴ�." << endl;
	return 0;
}

int sum(int start_num, int end_num) {
	int k, res = { 0 };
	for (k = start_num; k <= end_num; k++)
		res += k;

	return res;
}
*/
/*
// Practice 2
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//int main() {
//	char password[11];
//	cout << "���α׷��� �����Ϸ��� ��ȣ�� �Է��ϼ���." << endl;
//	while (true) {
//		cout << "��ȣ>>";
//		cin >> password;
//		if (strcmp(password, "C++") == 0) {
//			cout << "���α׷��� ���� �����մϴ�." << endl;
//			break;
//		}
//		else
//			cout << "��ȣ�� Ʋ���ϴ�~~" << endl;
//	}
//}

#include <iostream>
#include <string>
using namespace std;

int main() {
	string password;
	cout << "���α׷��� �����Ϸ��� ��ȣ�� �Է��ϼ���." << endl;
	while (true) {
		cout << "��ȣ>>";
		getline(cin, password);
		if (password == "C++") {
			cout << "���α׷��� ���� �����մϴ�." << endl;
			break;
		}
		else
			cout << "��ȣ�� Ʋ���ϴ�~~" << endl;
	}
}
*/

/*
// Practice 3
#include <iostream>
using namespace std;

int main() {
	int n;
	char name[100];
	while (true) {
		cout << "���� ID �Է� >>";
		cin >> n;
		if (n == -1)break;
		cout << "�̸� ���ڿ� �Է� >>";
		cin.ignore(1, '\n'); // also can use <<cin.get();>>
		cin.getline(name, 100);
		cout << "ID: " << n << ' ' << name << endl;
	}
	return 0;
}

*/

#include <iostream>
using namespace std;

class Rectangle {
public:
	int width;
	int height;
	int getArea();
};

int Rectangle::getArea() {
	return width * height;
}

int main() {
	Rectangle rect;
	rect.width = 3;
	rect.height = 5;

	cout << "�簢���� ������" << rect.getArea() << endl;
}

