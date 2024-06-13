/*
형변환 연산자 종류
1. static_cast<>(): 기본 타입이나 상속 관계에 있는 클래스 포인터를 변환할 때 사용 - 컴파일 시간에 작동
2. dynamic_cast<>(): 상속관계에 잇는 클래스  포인터를 변환 할때 - 실행시간에 식별 / 상향 형변환만 허용
3. const_cast<>(): 상수 속성을 변경
4. interpret_cast<>(): 관련없는 포인터 사이의 무조건 변환 ex> 정수형과 포인터 사이의 변환
*/

#include <iostream>
using namespace std;

class Car
{
};

class Bus : public Car
{
};

int main()
{
    // static_cast 예제
    int i = 9;
    double f = 3.141592;

    int *pi;
    double *pf = &f;

    i = static_cast<int>(f);
    // pi = static_cast<int *>(pf); 포인터 변수는 static_cast로 변환 불가

    cout << i;

    // dynamic_cast 예제
    Bus *pBus = new Bus;
    Car *pCar = dynamic_cast<Car *>(pBus); // 상향 형변환으로 가능

    Car *pCar2 = new Car;
    // Bus *pBus2 = dynamic_cast<Bus *>(pCar2); //하향 형변환은 불가능

    Car *pCar3 = new Bus; // 부모 클래스에 자식클래스 넣음
    // Bus *pBus = dynamic_cast<Bus *>(pCar3); //Car 포인터 형식이지만 처음에 Bus 형태로 넣었으므로 하향 형변환 불가능

    // const_cast
    const char *test = "s";
    char *test2 = const_cast<char *>(test);

    // reinterpret_cast
    char *pc;
    pc = reinterpret_cast<char *>(0x10000ef); // int 를 char*로 변환

    Car *pCar4 = new Car;
    Bus *pBox = reinterpret_cast<Bus *>(pCar4); // Car을 Bus 포인터로 형변환

    // typeid 는 실행시간에 객체의 타입을 식별할 수 있음
    cout << typeid(pCar4).name() << endl;
    cout << typeid(*pCar4).name() << endl;
    cout << typeid(pBox).name() << endl;
    cout << typeid(*pBox).name() << endl;

    // Bus* pd = new SportsCar;
    // Car* pb = pd;
    // pb == Car* (대입 전), *pb = SportsCar(대입 후)
    return 0;
}