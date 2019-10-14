#include <iostream>
#define PI 3.141592
#define POW(a) a*a

using namespace std;

class Circle {
	int radious;
	char* color;
	//static int count;
public:
	Circle() { radious = 0, color = nullptr; }
	Circle(int radious, char* color) {
		int len = strlen(color);
		this->radious = radious;
		color = new char(len + 1);
		strcpy(this->color, color);
		//this->color = color;
	}
	~Circle() { }//count = 0; }//count++; }
	//Circle(const Circle& c);
	//Circle(const Circle&& c); // 이동생성자
	Circle& operator=(const Circle& op2);
	Circle& operator=(const Circle&& op2);
	void setRadious(int r) { radious = r; };
	int getRadious() { return radious; };
	int getArea();
	int getPerimeter();
	//int getCount() {} //return count; };
	void print();
	bool is_equal(Circle& c1, Circle& c2);
};

/*
Circle::Circle(const Circle& c) { // 복사생성자
	int len = strlen(c.color);
	radious = c.radious;
	color = new char(len + 1);
	strcpy(color, c.color);
	//c.color = nullptr;
}

Circle::Circle(const Circle&& c) { // 이동생성자
	int len = strlen(c.color);
	radious = c.radious;
	color = new char(len + 1);
	strcpy(color, c.color);
	//c.color = nullptr;
}
*/


Circle& Circle::operator=(const Circle&& op2) { // 이동대입연산자
	if (this == &op2) // 서로 주소가 같은경우
		return *this; // 객체 자체를 반환해버림
	delete[] color;
	radious = op2.radious;
	color = new char(strlen(op2.color) + 1);
	strcpy(color, op2.color);
	return *this;
}

Circle& Circle::operator=(const Circle& op2) { // 복사대입연산자
	if (this == &op2) // 서로 주소가 같은경우
		return *this; // 객체 자체를 반환해버림
	delete[] color;
	radious = op2.radious;
	color = new char(strlen(op2.color) + 1);
	strcpy(color, op2.color);
	return *this;
}

void Circle::print() {
	int len = strlen(color);
	cout << "현재 객체의 radious: " << radious << endl;
	cout << "현재 객체의 color: ";
	for (int i = 0; i < len; i++)
		cout << *(color + i) << endl;
	//cout << "현재 객체의 count: " << count << endl;
}

int Circle::getArea() {
	return POW(radious) * PI;
}

int Circle::getPerimeter() {
	return 2 * PI * radious;
}

bool Circle::is_equal(Circle& c1, Circle& c2) {
	if (c1.radious == c2.radious &&
		c1.color == c2.color)
		return true;
	else return false;
}


int main() {
	Circle c1(10,"CPP");
	c1.print();



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
