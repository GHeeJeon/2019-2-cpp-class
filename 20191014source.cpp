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
	//Circle(const Circle&& c); // �̵�������
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
Circle::Circle(const Circle& c) { // ���������
	int len = strlen(c.color);
	radious = c.radious;
	color = new char(len + 1);
	strcpy(color, c.color);
	//c.color = nullptr;
}

Circle::Circle(const Circle&& c) { // �̵�������
	int len = strlen(c.color);
	radious = c.radious;
	color = new char(len + 1);
	strcpy(color, c.color);
	//c.color = nullptr;
}
*/


Circle& Circle::operator=(const Circle&& op2) { // �̵����Կ�����
	if (this == &op2) // ���� �ּҰ� �������
		return *this; // ��ü ��ü�� ��ȯ�ع���
	delete[] color;
	radious = op2.radious;
	color = new char(strlen(op2.color) + 1);
	strcpy(color, op2.color);
	return *this;
}

Circle& Circle::operator=(const Circle& op2) { // ������Կ�����
	if (this == &op2) // ���� �ּҰ� �������
		return *this; // ��ü ��ü�� ��ȯ�ع���
	delete[] color;
	radious = op2.radious;
	color = new char(strlen(op2.color) + 1);
	strcpy(color, op2.color);
	return *this;
}

void Circle::print() {
	int len = strlen(color);
	cout << "���� ��ü�� radious: " << radious << endl;
	cout << "���� ��ü�� color: ";
	for (int i = 0; i < len; i++)
		cout << *(color + i) << endl;
	//cout << "���� ��ü�� count: " << count << endl;
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
	Book a("��ǰ C++", 30000, 500), b("��ǰ C++", 30000, 500);
	if (a == 30000) cout << "���� 30000��" << endl;
	if (a == "��ǰ C++") cout << "��ǰ C++ �Դϴ�." << endl;
	if (a == b) cout << "�� å�� ���� å�Դϴ�." << endl;
}
*/
