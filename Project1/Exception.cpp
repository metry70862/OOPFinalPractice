/*
예외 처리
try catch 구문
예를 들어 parentException, 이 클래스를 상속받은 childException이 있다면
cathc(parentException e) 했을 때 childException도 잡힘
*/

#include <iostream>
using namespace std;

class NoPersonException
{
private:
    int persons;

public:
    NoPersonException();
    NoPersonException(int x)
    {
        persons = x;
    };
    int get_persons()
    {
        return persons;
    }
};

int dividePizza(int pizza_slices, int person)
{
    try
    {
        if (person == 0)
            throw person;
        return pizza_slices / person;
    }
    catch (int e)
    {
        cout << "(divide Pizza) 사람이" << e << "명입니다. ";
        throw; // exeption catch 후 main 으로 다시 넘김
    }
}

int main()
{
    int pizza_slices = 0;
    int person = -1;
    int slices_per_person = 0;
    try
    {
        cout << "피자의 총 조각 수를 입력하세요." << endl;
        cin >> pizza_slices;
        cout << "사람수를 입력하세요." << endl;
        cin >> person;

        if (person == 0)
            throw NoPersonException(person);
        if (person < 0)
            throw person;
        cout << "한사람당 피자는 " << slices_per_person << "개 입니다. " << endl;
        slices_per_person = dividePizza(pizza_slices, person);
    }
    catch (int e) // throw 하는 것과 타입이 일치해야 함
    {
        cout << "사람이" << e << "명입니다. ";
    }
    catch (NoPersonException e)
    {
        cout << e.get_persons() << endl;
    }
    catch (...) // 모든 형식의 예외를 잡을 수 있음
    {
        cout << "Catch 'em all" << endl;
    }

    return 0;
}
