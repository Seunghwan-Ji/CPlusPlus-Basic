#include <iostream>
#include "CArr.h"

using std::cout;
using std::endl;

int main()
{
	CArr<int> myVector;

	myVector.push_back(1);
	myVector.push_back(2);
	myVector.push_back(3);

	// 구현한 연산자 오버로딩 함수 테스트(++(전위), --(전위), ==, !=)
	CArr<int>::iterator myIter = myVector.begin();
	*myIter;

	for (; myIter != myVector.end(); ++myIter)
	{
		cout << *myIter << endl;
	}
	/*for (; 조건식; 증감식)의 의미
	초기식을 비워두면 루프가 시작될 때 아무 것도 하지 않는다는 의미입니다.
	그러나 조건식과 증감식은 여전히 정상적으로 작동합니다.
	이는 초기값을 이미 설정해 둔 경우나 반복 변수의 초기화가 필요하지 않은 경우에 유용합니다.*/

	myIter = myVector.begin();

	// 디버깅을 통해 아래 연산자들이 어떤 멤버 함수를 호출하는지 확인해보자.
	myIter++;
	++myIter;

	return 0;
}