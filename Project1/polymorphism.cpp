#include <iostream>
using namespace std;
class Shape {
protected:
	int x, y;
public:
	void draw() {
		cout << "Shape Draw" << endl;
	}
	void setOrigin(int x, int y) {
		this->x = x;
		this->y = y;
	}
	virtual void draw2() {
		cout << "Shape Draw2" << endl;
	}
};

class Rectangle : public Shape {
private:
	int width, height;
public:
	void setWidth(int w) {
		this->width = width;
	}

	void setHeight(int h) {
		this->height = h;
	}
	void draw() {
		cout << "Draw Rectangle" << endl;
	}
	void draw2() {
		cout << "Rectangle Draw2" << endl;
	}
};

class Circle :public Shape {
private:
	int radius;
public:
	void setRadius(int r) {
		this->radius = r;
	}
	void draw() {
		cout << "Circle Draw" << endl;
	}
	void draw2() {
		cout << "Circle Draw2" << endl;
	}
};

class Triangle :public Shape {
private:
	int base, height;
public:
	void draw2() {
		cout << "Draw Triangle2" << endl;
	}
};



void move(Shape& s, int sx, int sy) { //매개변수로 받을 때 부모 클래스로 받는 것이 더 좋다
	s.setOrigin(sx, sy);
};




class Animal {
public:
	virtual void speak() { cout << "Animal speak" << endl; }
};

class Dog : public Animal{
public:
	void speak() { cout << "Dog Speak" << endl; }
};





class Phone { //abstact Clss 순수 가상함수 하나라도 가지고 있으면 추상클래스임
public:
	virtual void turnOn() = 0;//순수 가상함수
};

class iPhone :public Phone {
public:
	void turnOn() {
		cout << "iPhone Turn On" << endl;
	}
};

class Galaxy :public Phone {
public:
	void turnOn() {
		cout << "Galaxy Turn ON" << endl;
	}
};

int main() {
	//형변환
	//상향 형변환
	Shape* ps = new Rectangle();
	ps->setOrigin(10, 10); 
	//shape 포인터로 접근하게 되면 rectangle의 정의된 부분은 사용할 수 없음

	//하향 형변환
	Rectangle* pr = (Rectangle*)ps;
	pr->setWidth(100);
	//또는
	((Rectangle*)ps)->setHeight(100);
	//이렇게 하면 rectangle의 모든 멤버에 접근할 수 있음

	Shape* ps2 = new Circle();
	//ps2->draw(); 접근 불가능
	((Circle*)ps2)->draw();
	delete ps;
	delete ps2;




	//가상함수
	/*그렇다면 shape포인터를 통하여 멤버함수를 호출 해도 원하는 도형의 draw()를 호출 할 수는 없을까?
	* 가상함수는 부모클래스에서 원형을 만들고 자식클래스에서 메서드를 재정의 함
	* 이러한 과정을 통해 Shape 포인터 클래스 안에 담겨 있어도 각각 다른 메서드 호출 가능
	* 가상함수는 정적 바인딩(컴파일 시간에 호출)이 아닌 동적 바인딩(실행 시간에 호출)이 되기 때문에 속도가 늦다.
	*/

	Shape* ps3 = new Rectangle();
	ps3->draw(); //shape의 함수가 호출됨
	ps3->draw2(); //부모클래스에서 가상함수 rectangle에서 재정의한 draw2 호출

	Shape* ps4 = new Circle();
	ps4->draw2();//Circle에서 재정의한 가상함수 호출

	//Shape 포인터가 담겨있는 배열에서 각각 다른 가상함수 호출해보기
	Shape* arrayOfShapes[3];

	arrayOfShapes[0] = new Rectangle();
	arrayOfShapes[1] = new Circle();
	arrayOfShapes[2] = new Triangle();

	for (int i = 0; i < 3; i++)
	{
		arrayOfShapes[i]->draw2();
	}



	//참조자와 가상함수
	/*
	int a = 1;
	int &another_a = a;
	이렇게 a에 별명을 붙일 수 있음
	*/
	Dog d;
	Animal& a1 = d;
	d.speak();
	a1.speak(); //참조자도 가상함수가 정상적으로 동작함



	//순수 가상함수
	//virtual 반환형 함수이름(매개변수) = 0; 이렇게 선언함
	Phone* p = new iPhone();
	Galaxy g;
	Phone& p2 = g;

	p->turnOn(); //Phone포인터에서 iPhone객체 생성뒤 함수 호출
	p2.turnOn(); //참조자로 가상함수 호출
	

}