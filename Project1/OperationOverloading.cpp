/*연산자 중복
여러가지 연산을 클래스 객체에서도 적용할 수 있음
예를 들어 Vector v1 + Vector v2 와 같은 연산이 가능
연산자 + 의 중복함수는 operator+()과 같이 만들 수 있음
멤버함수로 구현 v1.oprrator+(v2) / 비멤버함수로 구현 operator+(v1,v2) 두가지 방법으로 구현가능
= , (), [], -> 연산자는 멤버함수로만 구현가능
:: . .* ?: 연산자는 오버로딩 불가능
*(곱셈 연산자) 구현할 때는 operator*(a,v2), operator(v2,a) 모두 구현해야 함
= 연산은 *this를 꼭 사용하여 해당 객체의 레퍼런스를 반환
"배열 연산자는 나중에 다시보기"
*/

#include <iostream>
using namespace std;
class Vector
{
    friend Vector operator+(Vector &v1, Vector &v2); // 연산자 중복을 비 멤버함수로 구현
    friend Vector operator*(Vector &v, double a);    //*연산 교환법칙 포함해서 구현하기
    friend Vector operator*(double a, Vector &v);
    friend ostream &operator<<(ostream &os, const Vector &v);

private:
    double x, y;

public:
    Vector(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    Vector(int a)
    {
        this->x = a;
        this->y = a;
    }
    void display()
    {
        cout << "x: " << x << "y: " << y << endl;
    }
    Vector operator-(Vector &v2) // 연산자를 멤버함수로 구현
    {
        Vector v(0.0, 0.0);
        v.x = this->x - v2.x;
        v.y = this->y - v2.y;
        return v;
    }
    Vector operator++() //++v 연산자 오버라이딩
    {
        x++;
        y++;
        return *this;
    }
    Vector operator++(int) // v++ 연산자 오버라이딩 둘다 해당객체의 레퍼런스를 반환해야야 함
    {
        Vector saveobj = *this;
        x++;
        y++;
        return saveobj;
    }

    operator int() const
    {
        return x + y;
    }
};

Vector operator+(Vector &v1, Vector &v2)
{
    Vector v(0.0, 0.0);
    v.x = v1.x + v2.x;
    v.y = v2.y + v2.y;
    return v;
}

Vector operator*(Vector &v, double a)
{
    return Vector(v.x * a, v.y * a);
}
Vector operator*(double a, Vector &v)
{
    return Vector(v.x * a, v.y * a);
}

ostream &operator<<(ostream &os, const Vector &v)
{
    os << "x: " << v.x << "y: " << v.y << endl;
    return os;
}

int main()
{
    Vector v1(1, 2), v2(3, 4);
    Vector v3 = v1 + v2;
    Vector v4 = v1 - v2;
    Vector v5 = 5.0 * v2;
    v3.display();
    v4.display();
    v5.display();
    Vector v6(5); // 변환 연산자 int -> Vector,
    int vToInt = v6;
    cout << vToInt << endl; // 변환 연산자 operator int() 를 통해 Vector -> int 로 형변환
    v6.display();
    cout << ++v4;
    cout << v4;
}