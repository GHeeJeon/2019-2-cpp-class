/*
// Practice 1
#include <iostream>
using namespace std;

int sum(int start_num, int end_num);

int main() {
	int n = { 0 };
	cout << "끝 수를 입력하세요>";
	cin >> n;

	cout << "1에서" << n << "까지의 합은 " << sum(1, n) << "입니다." << endl;
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
//	cout << "프로그램을 종료하려면 암호를 입력하세요." << endl;
//	while (true) {
//		cout << "암호>>";
//		cin >> password;
//		if (strcmp(password, "C++") == 0) {
//			cout << "프로그램을 정상 종료합니다." << endl;
//			break;
//		}
//		else
//			cout << "암호가 틀립니다~~" << endl;
//	}
//}

#include <iostream>
#include <string>
using namespace std;

int main() {
	string password;
	cout << "프로그램을 종료하려면 암호를 입력하세요." << endl;
	while (true) {
		cout << "암호>>";
		getline(cin, password);
		if (password == "C++") {
			cout << "프로그램을 정상 종료합니다." << endl;
			break;
		}
		else
			cout << "암호가 틀립니다~~" << endl;
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
		cout << "정수 ID 입력 >>";
		cin >> n;
		if (n == -1)break;
		cout << "이름 문자열 입력 >>";
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

	cout << "사각형의 면적은" << rect.getArea() << endl;
}

