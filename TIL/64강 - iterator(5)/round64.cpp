#include <iostream>
#include "CArr.h"

using std::cout;
using std::endl;

class CTest
{
public:
	int m_i;

public:
	// 자동으로 생성되는 함수는 생성자, 소멸자 함수 말고도 대입 연산자 함수도 있다.
	// 형태:
	CTest& operator =(const CTest& _other)
	{
		m_i = _other.m_i;

		return *this;
	}
	// 따라서 같은 클래스 객체끼리 대입이 발생되면 내부적으로 자동으로 생성된 위 함수가 동작한다.

public:
	// 생성자도 여러 버전으로 오버로딩 할 수 있다는 것을 배웠웠다.
	// 복사 생성자
	// 복사 생성자도 기본 생성자 처럼 자동으로 만들어지는 함수이다.
	// 형태:
	CTest(const CTest& _other)
		: m_i(_other.m_i) // 복사의 원형이 되는 _other 의 값을 받아와서 초기값으로 사용한다.
	{

	}
	// 기본, 복사 생성자 함수는 컴파일러가 기본적으로 만들어주는데,
	// 이 경우는 프로그래머가 한 종류의 복사 생성자 함수를 만들었기 때문에,
	// 컴파일러는 기본 생성자 함수를 만들어주지 않는다.
	// 따라서 기본 생성자는 생성자가 하나도 없을 때 만들어진다.

	// 이 경우 다음과 같이 기본 생성자도 작성해야한다.
	CTest()
		: m_i(0)
	{

	}

	// 물론 기본 생성자만 작성했을 경우엔 복사 생성자는 컴파일러가 자동으로 만들어준다.
};

int main()
{
	CArr<int> myVector;

	myVector.push_back(1);
	myVector.push_back(2);
	myVector.push_back(3);

	CArr<int>::iterator myIter = myVector.begin();
	*myIter;

	for (; myIter != myVector.end(); ++myIter)
	{
		cout << *myIter << endl;
	}

	myIter = myVector.begin();

	// 전위, 후위 연산자 함수 테스트
	int iData = *(myIter++);
	// int iData = *(++myIter);


	// 복사 생성자 활용
	CTest t1;
	t1.m_i = 100;

	CTest t2;
	t2 = t1;

	// 같은 표현
	CTest t2(t1); // 복사 생성자로 객체 생성과 대입을 동시에 한다.

	CTest t3 = t1; // t3 객체가 생성됨과 동시에 대입을 받고 있다.
	// 복사 생성자와 같은 개념이므로, 이 경우엔 컴파일러가 자동으로
	// 복사 생성자를 호출해서 다음과 같이 된다.
	CTest t3(t1);


	return 0;
}