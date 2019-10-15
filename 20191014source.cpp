#include <iostream>
#define PI 3.141592
#define POW(a) a*a

using namespace std;

class Circle {
	int radious;
	char* color;
	static int count;
public:
	Circle() { radious = 0, color = nullptr; count++; }

	Circle(int radious, const char* color) {
		int len = strlen(color);
		this->radious = radious;
		this->color = new char(len + 1);
		strcpy(this->color,color);
		count++;
	}

	~Circle() { 
		count--;
		cout << count << endl;
	} // 소멸자

	Circle(const Circle& c); // 복사생성자
	Circle(Circle&& c); // 이동생성자
	Circle& operator=(const Circle& op2);
	Circle& operator=(Circle&& op2);
	Circle& operator+(Circle& op2);
	void setRadious(int r) { radious = r; };
	int getRadious() { return radious; };
	int getArea();
	int getPerimeter();
	void print();

	friend bool is_equal(Circle& c1, Circle& c2);

	
	static int getCount() { return count; }
};

int Circle::count = 0;

Circle::Circle(const Circle& c) { // 복사생성자
	int len = strlen(c.color);
	radious = c.radious;
	color = new char(len + 1);
	strcpy(color, c.color);
	count++;
	cout << "복사생성자 생성되었습니다." << endl;
}

Circle::Circle(Circle&& c) { // 이동생성자
	radious = c.radious;
	color = c.color;
	c.color = nullptr;
	count++;
	cout << "이동생성자 생성되었습니다." << endl;
}

Circle& Circle::operator=(const Circle& op2) { // 복사대입연산자
	if (this == &op2) // 서로 주소가 같은경우
		return *this; // 객체 자체를 반환해버림
	delete[] color;
	radious = op2.radious;
	color = new char(strlen(op2.color) + 1);
	strcpy(color, op2.color);
	cout << "복사대입연산자 생성되었습니다." << endl;
	return *this;
}

Circle& Circle::operator=(Circle&& op2) { // 이동대입연산자
	if (this == &op2) // 서로 주소가 같은경우
		return *this; // 객체 자체를 반환해버림
	delete[] color;
	radious = op2.radious;
	color = op2.color;
	op2.color = nullptr;
	cout << "이동대입연산자 생성되었습니다." << endl;
	return *this;
}

Circle& Circle::operator+(Circle& op2) {
	Circle tmp;
	tmp.radious = radious + op2.getRadious();
	//tmp.color = op2.color;
	return tmp;
}

void Circle::print() {
	int len = strlen(color);
	cout << "현재 객체의 radious: " << radious << endl;
	cout << "현재 객체의 color: ";
	for (int i = 0; i < len; i++)
		cout << *(color + i);
	cout << endl;
	cout << "현재 객체의 count: " << count << endl;
}

int Circle::getArea() {
	return POW(radious) * PI;
}

int Circle::getPerimeter() {
	return 2 * PI * radious;
}

bool is_equal(Circle& c1, Circle& c2) {
	if (c1.radious == c2.radious &&
		!strcmp(c1.color,c2.color))
		return true;
	else return false;
}


int main() {
	Circle c2(10, "RED");
	Circle c1(10, "CPP");
	c2.print();
	cout << "c2의 넓이" << c2.getArea() << endl;
	cout << "c2의 둘레" << c2.getPerimeter() << endl;
	if (is_equal(c1, c2))
		cout << "c1과 c2가 같습니다." << endl;
	else
		cout << "c1과 c2가 다릅니다." << endl;
	Circle copy(c2);
	copy.print();
	
	Circle c3, c4;
	c3 = c1;
	c4 = c3 + c2;
}




/* 7-1 Practice
#include <iostream>
using namespace std;
class Book {
	string title;
	int price;
	int pages;
public:
	Book(string title = "", int price = 0, int pages = 0) {
		this->title = title;
		this->price = price;
		this->pages = pages;
	}
	friend bool operator ==(Book book, int price);
	friend bool operator ==(Book book, string title);
	friend bool operator ==(Book book1, Book book2);
};
bool operator ==(Book book, int price) {
	if (book.price == price) return true;
	else return false;
}
bool operator ==(Book book, string title) {
	if (book.title == title) return true;
	else return false;
}
bool operator ==(Book book1, Book book2) {
	if (book1.pages == book2.pages &&
		book1.price == book2.price &&
		book1.title == book2.title)
		return true;
	else return false;
}
int main() {
	Book a("명품 C++", 30000, 500), b("고품 C++", 30000, 500);
	if (a == 30000) cout << "정가 30000원" << endl;
	if (a == "명품 C++") cout << "명품 C++ 입니다." << endl;
	if (a == b) cout << "두 책이 같은 책입니다." << endl;
}
*/