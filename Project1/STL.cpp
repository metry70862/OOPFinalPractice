/*
표준 템플릿 라이브러리 공통적으로 사용하는 자료구조와 알고리즘에 대한 클래스

STL의 3가지 컴포넌트
1. 컨테이너 : 자료를 저장하는 구조로, 벡터, 리스트, 맵, 집합, 큐, 스택과 같은 다양한 자료 구조가 제공됨
2. 반복자(iterator) : 컨테이너 안에 저장된 요소들을 순차적으로 처리하기 위한 컴포넌트
3. 알고리즘: 정렬이나 탐색과 같은 다양한 알고리즘을 구현

순차 컨테이너 : 자료를 순차적으로 저장 / 벡터, 데크 리스트
연관 컨테이너: 사전과 같은 구조를 사용하여서 자료를 저장, 자료들은 정렬되어 있음 /
 set : 중복이 없는 자료들이 정렬됨
 map : 키-값의 형식으로 저장됨
 multiset : 집합과 유사하지만 중복 허용
 multimap : 맵과 유사하지만 키가 중복될 수 있음

컨테이너 어댑터: 순차 컨테이너에 제약을 더해 데이터가 정해진 방식으로만 입출력
 stack : 먼저 입력된 데이터가 나중에 출력됨 (LIFO)
 queue : 데이터가 입력된 순서대로 출력됨 (FIFO)
 priority queue : 큐의 일종으로 큐의 요소들이 우선순위를 가지고 있고 순위가 높은 요소부터 출력됨
*/

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <iterator>

using namespace std;

int main1()
{
    // vector 예제
    vector<double> scores(10);
    for (int i = 0; i < scores.size(); i++)
    {
        cout << "성적을 입력하십시오: ";
        cin >> scores[i];
    }

    double highest = scores[0];
    for (int i = 1; i < scores.size(); i++)
    {
        if (scores[i] > highest)
        {
            highest = scores[i];
        }
    }
    cout << "최고성적은 " << highest << "입니다." << endl;
    return 0;
}

int main2()
{
    // deque 예제
    deque<int> dq;
    dq.push_back(99);
    dq.push_back(10);
    dq.push_front(11);
    dq.push_front(15);

    for (int i = 0; i < dq.size(); i++)
    {
        cout << dq[i] << endl;
    }
    cout << endl;
    dq.pop_back();
    dq.pop_front();
    for (int i = 0; i < dq.size(); i++)
    {
        cout << dq[i] << endl;
    }
    return 0;
}

void printList(list<int> &lst);
int main3()
{
    list<int> my_list;

    my_list.push_back(10);
    my_list.push_back(20);
    my_list.push_back(30);
    my_list.push_back(40);
    my_list.push_front(1);

    my_list.insert(my_list.begin(), 5); // 리스트 시작에 넣음
    my_list.insert(my_list.end(), 100); // 리스트 끝부분에 넣음
    printList(my_list);
    return 0;
}

void printList(list<int> &lst) // 함수 정의 올바르게 수정
{
    list<int>::iterator it;                       // iterator 선언
    for (it = lst.begin(); it != lst.end(); ++it) // 반복문에서 변수명 'i'를 'it'으로 수정
    {
        cout << *it << " ";
    }
    cout << endl; // 리스트 출력 후 개행 추가
}
template <typename T>
void print_list(T &container)
{
    typename T::iterator itr;
    for (itr = container.begin(); itr != container.end(); ++itr)
    {
        cout << *itr << endl;
    }
}

int main4()
{
    set<int> my_set;
    multiset<int> my_multiset;

    my_set.insert(1);
    my_set.insert(2);
    my_set.insert(3);

    my_multiset.insert(my_set.begin(), my_set.end());
    my_multiset.insert(4);
    my_multiset.insert(3);
    print_list(my_set);
    print_list(my_multiset);
    return 0;
}

int main5()
{
    map<string, string> dic;
    dic["boy"] = "소년";
    dic["school"] = "힉교";

    cout << "boy의 의미는 " << dic["boy"] << endl;
    return 0;
}

int main6()
{
    stack<string> st;
    string say[3] = {
        "Hello", "World", "!"};
    for (int i = 0; i < say->length(); i++)
    {
        st.push(say[i]);
    }
    while (!st.empty())
    {
        cout << st.top() << endl; // st.pop은 바로 cout 으로 사용할 수 없음
        st.pop();
    }
    return 0;
}

int main()
{
    queue<int> qu;
    qu.push(100);
    qu.push(200);
    qu.push(300);
    while (!qu.empty())
    {
        cout << qu.front() << endl;
        qu.pop();
    }
}