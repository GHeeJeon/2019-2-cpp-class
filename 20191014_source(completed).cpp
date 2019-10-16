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

	Circle(int radious) { 
		this->radious = radious; 
		color = nullptr;
		count++;
	}

	Circle(int radious, const char* color) {
		int len = strlen(color);
		this->radious = radious;
		this->color = new char(len + 1);
		strcpy(this->color, color);
		count++;
	}

	~Circle() {
		count--;
		cout << count << endl;
	} // �Ҹ���

	Circle(const Circle& c); // ���������

	Circle& operator=(const Circle& op2); // ������Կ�����

	Circle(Circle&& c); // �̵�������

	Circle& operator=(Circle && op2); // �̵����Կ�����

	
	
	Circle operator+(Circle& op2); // ����������
	
	void setRadious(int r) { radious = r; };
	int getRadious() { return radious; };
	int getArea();
	int getPerimeter();
	void print();

	friend bool is_equal(Circle& c1, Circle& c2);


	static int getCount() { return count; }
};

int Circle::count = 0;

Circle::Circle(const Circle& c) { // ���������
	int len = strlen(c.color);
	radious = c.radious;
	color = new char(len + 1);
	strcpy(color, c.color);
	count++;
	cout << "��������� �����Ǿ����ϴ�." << endl;
}

Circle& Circle::operator=(const Circle& op2) { // ������Կ�����
	if (this == &op2) // ���� �ּҰ� �������
		return *this; // ��ü ��ü�� ��ȯ�ع���
	delete[] this->color;
	radious = op2.radious;
	color = new char(strlen(op2.color) + 1);
	strcpy(color, op2.color);
	cout << "������Կ����� �����Ǿ����ϴ�." << endl;
	return *this;
}

Circle::Circle(Circle&& c) { // �̵�������
	radious = c.radious;
	color = c.color;
	c.color = nullptr;
	count++;
	cout << "�̵������� �����Ǿ����ϴ�." << endl;
}

Circle& Circle::operator=(Circle && op2) { // �̵����Կ�����
	if (this == &op2) // ���� �ּҰ� �������
		return *this; // ��ü ��ü�� ��ȯ�ع���
	//delete[] color;
	radious = op2.radious;
	//color = op2.color;
	//op2.color = nullptr;
	cout << "�̵����Կ����� �����Ǿ����ϴ�." << endl;
	return *this;
}





Circle Circle::operator+(Circle& op2) { // �������� Circle&�� �ƴ϶�, Circle�� ��ȯ�ؾ� �ȴٴ°��̾���. 
	Circle tmp;
	tmp.radious = radious + op2.getRadious();
	tmp.color = new char(8);
	strcpy(tmp.color, "chagned");
	return tmp;
}

void Circle::print() {
	int len = strlen(color);
	cout << "���� ��ü�� radious: " << radious << endl;
	cout << "���� ��ü�� color: ";
	for (int i = 0; i < len; i++)
		cout << *(color + i);
	cout << endl;
	cout << "���� ��ü�� count: " << count << endl;
}

int Circle::getArea() {
	return POW(radious) * PI;
}

int Circle::getPerimeter() {
	return 2 * PI * radious;
}

bool is_equal(Circle& c1, Circle& c2) {
	if (c1.radious == c2.radious &&
		!strcmp(c1.color, c2.color))
		return true;
	else return false;
}


int main() {
	
	Circle c2(10, "RED");
	Circle c1(10, "CPP");
	c2.print();
	cout << "c2�� ����" << c2.getArea() << endl;
	cout << "c2�� �ѷ�" << c2.getPerimeter() << endl;
	if (is_equal(c1, c2))
		cout << "c1�� c2�� �����ϴ�." << endl;
	else
		cout << "c1�� c2�� �ٸ��ϴ�." << endl;
	Circle copy(c2);
	copy.print();

	Circle c3, c4;
	c3 = c1; // ������Կ�����
	c4 = c3 + c2;  // �������� Circle&�� �ƴ϶�, Circle�� ��ȯ�ؾ� �ȴٴ°��̾���. -> �̵������� �� �̵����Կ����� ��� ����
	
	return 0;

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