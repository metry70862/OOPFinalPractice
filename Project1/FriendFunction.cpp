#include <iostream>
#include <string>
using namespace std;

class Company
{
private:
    int sales, profit;
    friend void sub(Company &c); // sub()는 Company private에 접근할 수 있음
    friend class Manager;        // 프렌드로 클래스도 선언할 수 있음

public:
    Company() : sales(0), profit(0) {}
};

void sub(Company &c)
{
    cout << c.profit << endl;
}

class Date
{
    friend bool equals(Date d1, Date d2); // 멤버함수 아님 d1.equals와 같이 호출할 수 없음

private:
    int year, month;

public:
    Date(int y, int m)
    {
        year = y;
        month = m;
    }
};

bool equals(Date d1, Date d2)
{
    return d1.year == d2.year && d1.month == d2.month;
}

int main()
{
    // 프렌드 함수: 클래스 내부 데이터에 접근할 수 있는 함수
    // 원형만 클래스 안에 있고 본체는 외부에서 정의, 멤버함수 아님
    Company c1;
    sub(c1);

    // 프렌드 함수로 equals 오버로딩
    Date d1(2024, 05), d2(2024, 05);
    cout << equals(d1, d2) << endl;
    return 0;
}