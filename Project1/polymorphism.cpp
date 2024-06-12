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

int main() {
	//상향 형변환
	Shape* ps = new Rectangle();
	ps->setOrigin(10, 10); //shape 포인터로 접근하게 되면 rectangle의 정의된 부분은 사용할 수 없음

	//하향 형변환
	Rectangle* pr = (Rectangle*)ps;
	pr->setWidth(100);
	//또는
	((Rectangle*)ps)->setHeight(100);
	//이렇게 하면 
}