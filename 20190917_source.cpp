/*
// 20190917 Chapter3 Practice 1-1

#include <iostream>

using namespace std;

class Pearson {
public:
	string name;
	int age;

	void show();
};

int main() {
	Pearson p1, p2;

	p1.name = "Mike";
	p1.age = 20;
	p1.show();
}

void Pearson::show() {
	cout << name << "   " << age << endl;
}
*/

/*
// 20190917 Chapter3 Practice 1-2

#include <iostream>

using namespace std;

class Pearson {
private:
	string name;
	int age;
public:
	Pearson();
	Pearson(string s, int age);
	Pearson(string s);
	void show();
};

Pearson::Pearson() : Pearson("", 1) {}
Pearson::Pearson(string s, int number) : name(s), age(number) {}
Pearson::Pearson(string s) : Pearson(s, 20) {}

int main() {
	Pearson p1("Max", 25), p2("Mary"), p3;
	p1.show();
	p2.show();
	p3.show();
}

void Pearson::show() {
	cout << name << "   " << age << endl;
}
*/
/*
// 20190917 Chapter3 Practice 1-3

#include <iostream>

using namespace std;

class Pearson {
private:
	string name;
	int age;
public:
	Pearson();
	Pearson(string s, int age);
	Pearson(string s);
	void show();
	string getName();
	void setName(string s);
	int getAge();
	void setAge(int n);
};

Pearson::Pearson() : Pearson("", 1) {}
Pearson::Pearson(string s, int number) : name(s), age(number) {}
Pearson::Pearson(string s) : Pearson(s, 20) {}

int main() {
	Pearson p1("Zerk", 25), p2("Mary"), p3;
	p1.show();
	p2.show();
	p3.show();

	p1.setName("Jerk");
	p1.setAge(10);
	p3.setName(p2.getName());
	p3.setAge(p2.getAge());

	cout << "\n*****After Using Getter. Setter Method*****\n" << endl;
	p1.show();
	p2.show();
	p3.show();

}

void Pearson::show() {
	cout << name << "   " << age << endl;
}

int Pearson::getAge() {
	return age;
}

void Pearson::setAge(int n) { age = n; }

string Pearson::getName() {
	return name;
}

void Pearson::setName(string s) { name = s; }

*/

/*
// 20190917 Chapter3 Practice 2

#include <iostream>

using namespace std;

class Rectangle {
	int width, height, area;

public:
	int computeArea(int w, int h);
	int getWidth();
	int getHeight();
	int getArea();
	Rectangle(int w, int h);
};

Rectangle::Rectangle(int w, int h) : width(w),height(h), area(computeArea(w,h)) {}

int main() {
	Rectangle rect1(15, 23), rect2(27, 33);
	cout << "Area of rect1: " << rect1.getArea() << endl;
	cout << "Area of rect2: " << rect2.getArea() << endl;
}

int Rectangle::computeArea(int w, int h) {
	return w * h;
}

int Rectangle::getArea() {
	return area;
}

int Rectangle::getHeight() {
	return height;
}

int Rectangle::getWidth() {
	return width;
}
*/

/*
// 20190917 Chapter3 Practice 3-1

#include <iostream>

using namespace std;

class Point {
	double x, y;

public:
	Point();
	Point(double xx, double yy);
	void ShowPoint();
};

Point::Point() : Point(0, 0) {}
Point::Point(double xx, double yy) : x(xx), y(yy) {}


int main() {
	Point p10, p11;
	Point p20(10,20), p21(5,5);

	p10.ShowPoint();
	p11.ShowPoint();
	p20.ShowPoint();
	p21.ShowPoint();
}

void Point::ShowPoint() {
	cout << "point of x : " << x << endl;
	cout << "Point of y : " << y << endl;
}
*/

// 20190917 Chapter3 Practice 3-2

#include <iostream>

using namespace std;

class Point {
	double x, y;

public:
	Point();
	Point(double xx, double yy);
	double getX();
	double getY();
	void setX(double xx);
	void setY(double yy);
	void ShowPoint();
};

Point::Point() : Point(0, 0) {}
Point::Point(double xx, double yy) : x(xx), y(yy) {}


int main() {
	Point p10, p11;
	Point p20(10, 20), p21(5, 5);

	cout << "Befor changing\n" << endl;
	p10.ShowPoint();
	p11.ShowPoint();
	p20.ShowPoint();
	p21.ShowPoint();

	cout << "After changing p10, p20\n" << endl;

	p10.setX(11);
	p10.setY(11);
	p20.setX(p10.getX());
	p20.setY(p10.getY());

	p10.ShowPoint();
	p11.ShowPoint();
	p20.ShowPoint();
	p21.ShowPoint();


}

void Point::ShowPoint() {
	cout << "point of x : " << x << endl;
	cout << "Point of y : " << y << endl;
}

double Point::getX() { return x; }
double Point::getY() { return y; }
void Point::setX(double xx) { x = xx; }
void Point::setY(double yy) { y = yy; }


