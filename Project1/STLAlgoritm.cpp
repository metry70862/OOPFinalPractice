/*
STL 알고리즘 - 탐색, 정렬, 계수 알고리즘
STL 알고리즘에는 두가지가 있음

불변경 알고리즘 - 주로 검색 작엄
계수 알고리즘
 count() : 주어진 값과 일치하는 요소의 개수
 count_if() : 조건에 맞는 요소들의 개수를 센다

탐색 알고리즘
 search() : 주어진 값과 일치하는 첫번째 요소를 반환
 search_n() : 주어진 값과 일치하는 n개의 요소를 반환
 find() : 주어진 값과 일치하는 첫번쨰 요소 반환
 find_if() : 주어진 조건과 일치하는 첫번째 요소 반환
 find_end() : 주어진 조건과 일치하는 마지막 요소 반환
 binary_search() : "정렬 된 경우" 이진탐색을 수행

비교 알고리즘
 equal() : 두개의 요소가 같은지 비교
 mismatch() : 두개의 컨테이너를 비교해서 일치하지 않는 첫번째 요소를 반환
 lexicographocal_compare : 두개의 순차 컨테이너를 비교하여 사전적으로 어떤 컨테이너가 작은지 반환

변경 알고리즘              ㅜ
초기화 알고리즘
 fill() : 지정된 범위의 모든 요소를 지정된 값으로 채운다.
 generate() :지정된 함수의 반환값을 할당한다
변경 알고리즘
 for_each() :지정된 범위의 모든 요소에 대하여 연산을 수행한다.
 transform() : 지정된 범위의 모든 요소에 대하여 함수를 적용한다.
복사 알고리즘
 copy() : 하나의 구간을 다른 구간으로 복사한다.
삭제 알고리즘
 remove() : 지정된 구간에서 지정된 값을 가지는 요소들을 삭제한다.
 unique() : 구간에서 중복된 요소들을 삭제한다.
대치 알고리즘
 replace() : 지정된 구간에서 요소가 지정된 값과 일치하면 대치값으로 바꾼다.
정렬 알고리즘
 sort() : 지정된 정렬 기준에 따라서 구간의 요소들을 정렬한다.
분할 알고리즘
 patition() : 지정된 구간의 요소들을 조건에 따라서 두개의 집합으로 나눈다.


반복자
 컨테이너에서 다음 요소를 가리키기 위한 ++, 이전요소를 가리키는 --연산자
 두개의 반복자가 같은 요소를 가리키고 있는지 보는 == != 연산자
 ex> it == container.begin it!= container.end it++ *i

*/
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
using namespace std;

void printVec(vector<int> &vec)
{
    vector<int>::iterator it;
    for (it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << " "; // 컨테이너이 모든 요소를 출력
    }
}

int main1() // vector iterator로 출력 및 초기화
{
    vector<int> intVec;
    for (int i = 0; i < 10; i++)
    {
        intVec.push_back(i); // vector에 뒤에서 부터 원소 삽입
    }
    printVec(intVec);
    cout << endl;
    vector<int>::iterator it;
    for (it = intVec.begin(); it != intVec.end(); it++)
    {
        *it = 0; // 컨테이너의 모든 요소를 0으로 설정
    }
    printVec(intVec);
    return 0;
}

int main2()
{
    const int wanted = 6;
    int values[9] = {1, 3, 5, 5, 5, 8, 11, 20, 30};
    // vevtor를 아래와 같은 방법으로 초기화 할 수 있음
    vector<int> intVec2(&values[0], &values[9]); // 9개 짜리 배열이면 values[9]로 해야 정상적인식 가능
    vector<int>::iterator it2;

    printVec(intVec2);
    bool isinit = binary_search(intVec2.begin(), intVec2.end(), wanted);
    if (isinit == true)
    {
        cout << wanted << "를 찾았음" << endl;
    }
    else
    {
        // lower_bound함수 처음, 끝, 원하는 수를 입력하면 해당 숫자가 들어갈 최소 위치를 알려줌
        it2 = lower_bound(intVec2.begin(), intVec2.end(), wanted);
        intVec2.insert(it2, wanted);
    }
    cout << endl;
    printVec(intVec2);
    return 0;
}

int main3()
{
    // 비교 알고리즘
    int values1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int values2[9] = {9, 9, 3, 4, 5, 9, 9, 9, 9};

    vector<int> vec1(&values1[0], &values1[9]);
    vector<int> vec2(&values2[0], &values2[9]);

    printVec(vec1);
    cout << endl;
    printVec(vec2);
    // equal (비교대상1.begin. 비교대상1.end, 비교대상.begin)
    // 첫번째 구간의 사이즈를 기준으로 두 구간의 값이 모두 같은지 비교해줌
    bool isEqual = equal(vec1.begin() + 2, vec1.begin() + 5, vec2.begin() + 2);
    if (isEqual == true)
    {
        cout << "두 구간의 값이 같습니다." << endl;
    }
    return 0;
}

int main4()
{
    // fill : 연속성을 띄는 자료구조에서 일정 범위를 하나의 값이나 객체로 지정할 수 있음
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    cout << "fill()이전의 값" << endl;
    printVec(v1);
    // fill(시작점, 끝점, 채울 값)
    fill(v1.begin(), v1.end(), 0);
    cout << "fill()이후의 값" << endl;
    printVec(v1);
    return 0;
}

int main5()
{
    // 수치 알고리즘
    // copy: 복사, for_each():범위 내의 원소에 대해 함수를 실행
    string name[5] = {"사과", "배", "키위", "레몬", "포도"};
    vector<string> fruits(5);
    vector<string>::iterator its;
    // copy 복사할 대상의 첫, 끝, 복사할 위치의 시작
    copy(&name[0], &name[5], fruits.begin());
    // reverse 배열을 뒤집어줌, 첫번째와 끝 부분을 입력하면 됨
    reverse(fruits.begin(), fruits.end());
    for (its = fruits.begin(); its != fruits.end(); its++)
    {
        cout << *its << " ";
    }
    cout << endl;
    return 0;
}

void display(int element)
{
    cout << element << " ";
}
int main6()
{
    // for_each(): 원소들에 대해 각각 함수를 실행시킴
    vector<int> intVec3;
    for (int i = 0; i < 10; i++)
    {
        intVec3.push_back(i);
    }
    for_each(intVec3.begin(), intVec3.end(), display);

    return 0;
}

int increament(int element)
{
    return ++element;
}

int main7()
{
    // transform(): 반복자 구간에 대해 함수 객체를 적용후 그 결과를 다른 구간에 복사
    vector<int> intVec4;
    vector<int> result(10);
    for (int i = 0; i < 10; i++)
    {
        intVec4.push_back(i);
    }
    printVec(intVec4);
    cout << endl;
    // 적용대상의 첫, 끝, 도착지점의 첫, 적용할 함수
    // for each는 해당 벡터의 원소 자체를 수정하고 Transform은 이ㅇ
    transform(intVec4.begin(), intVec4.end(), result.begin(), increament);
    printVec(result);
    return 0;
}

int main8()
{
    // remove(): 반복자들과 삭제할 원소 값을 받으며 해당 원소를 찾아 삭제
    string names[5] = {"사과", "배", "키위", "레몬", "포도"};
    vector<string> fruits(5);
    copy(&names[0], &names[5], fruits.begin());
    vector<string>::iterator it;
    for (it = fruits.begin(); it != fruits.end(); it++)
    {
        cout << *it << " ";
    }

    cout << "remove()후" << endl;
    // remove는 it에 적용시켜야함
    // remove는 원소를 실제로 삭제하는 것이 아닌 그냥 뒤로 미루는 것
    it = remove(fruits.begin(), fruits.end(), "레몬");
    for (it = fruits.begin(); it != fruits.end(); it++)
    {
        cout << *it << " ";
    }

    // erase는 실제로 원소를 지우는 것임
    cout << "erase후" << endl;
    fruits.erase(it, fruits.end());
    for (it = fruits.begin(); it != fruits.end(); it++)
    {
        cout << *it << " ";
    }
    return 0;
}

int main()
{
    // sort Alogoritm
    int value[10] = {82, 25, 26, 7, 67, 55, 31, 19, 99};

    // 일반 sort
    vector<int> v1(&value[0], &value[10]);
    printVec(v1);
    cout << endl;
    sort(v1.begin(), v1.end());
    printVec(v1);
    cout << endl;

    // stable Sort
    vector<int> v2(&value[0], &value[10]);
    printVec(v2);
    cout << endl;
    sort(v2.begin(), v2.begin());
    printVec(v2);
    cout << endl;

    // partial Sort
    // begin ~ mid 까지만 정렬함
    vector<int> v3(&value[0], &value[10]);
    partial_sort(v3.begin(), v3.begin() + 3, v3.end());
    printVec(v3);
    cout << endl;

    // nth_element
    vector<int> v4(&value[0], &value[10]);
    // 예를 들어 4번째 요소를 선택하면 3번 째 앞에는 그 요소보다 작은것들이, 뒤에는 큰것들이 오게 됨

    nth_element(v4.begin(), v4.begin() + 4, v4.end());
    printVec(v4);
    cout << endl;
}
// sort(): 정렬