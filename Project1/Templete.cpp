/*
함수 템플릿 : 함수를 찍어내기 위한 형틀
일반적인 코드를 작성하고 이 코드를 다양한 타입의 객체에 대하여 재사용하는 프로그래밍 기법
클래스 템플리: 함수템플릿과 동일하고 외부에 함수를 정의하는 기능도 사용가능
*/
#include <iostream>
using namespace std;
/*
int get_max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}
*/

template <typename T>
T get_max(T x, T y)
{
    if (x > y)
        return x;
    else
        return y;
}

template <typename T>
void print_array(T a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

template <> // 템플릿 특수화
void print_array<char>(char a[], int n)
{
    cout << a << endl;
}

template <typename T>
void swap_values(T &x, T &y)
{
    T temp;
    temp = x;
    x = y;
    y = temp;
}

void swap_values(char *c1, char *c2)
{
    int len;

    len = (strlen(c1) >= strlen(c2)) ? strlen(c1) : strlen(c2); // 긴 char의 len 고르기
    char *tmp = new char[len + 1];                              // 임시 char 배열 만들기

    strcpy(tmp, c1);
    strcpy(c1, c2);
    strcpy(c2, tmp);
    delete[] tmp;
}

template <typename T>
class Box // 클래스 템플릿
{
    T data;

public:
    Box() {}
    void set(T value)
    {
        data = value;
    }

    T get()
    {
        return data;
    }

    T delData();
};

// 클래스 외부에도 템플릿 적용가능
template <typename T>
T Box<T>::delData()
{
    data = NULL;
}
int main()
{
    // 함수 템플릿 예제
    cout << get_max(1, 3) << endl;     // 정수 버전 getMax를 호출한다.
    cout << get_max(1.5, 1.2) << endl; // 실수 버전 getMax 호출한다.

    int a[] = {1, 2, 3, 4, 5};
    print_array(a, 5);
    char c[] = "char";
    print_array(c, 4);

    int x = 100, y = 200;
    swap_values(x, y);
    cout << "x: " << x << "y:" << y << endl;
    char d[] = "char2";

    swap_values(c, d);
    cout << c << d << endl;

    // 클래스 템플릿 예제
    Box<int> box;
    box.set(100);
    cout << box.get() << endl;

    Box<double> box1;
    box1.set(3.1);
    cout << box1.get() << endl;
}