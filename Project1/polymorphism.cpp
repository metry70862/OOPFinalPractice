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
};

int main() {
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

}