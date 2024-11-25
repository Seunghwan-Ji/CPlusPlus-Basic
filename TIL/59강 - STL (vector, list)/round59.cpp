#include <iostream>

#include <vector> // 표준 라이브러리로 제공하는 가변 배열
#include <list> // 표준 라이브러리로 제공하는 연결형 리스트
// 둘다 클래스 템플릿으로 구현되었다.

using std::vector;
using std::list;
using std::cout;
using std::endl;

int main()
{
	// 표준 가변 배열 기능
	vector<int> vecInt;
	vecInt.push_back(10);
	vecInt.push_back(20);

	// 연산자 오버로딩 함수도 구현되어있다.
	vecInt[0] = 100;

	vecInt.at(1); // 배열의 특정 인덱스로 접근해서 그 값을 레퍼런스로 반환해주는 함수이다.
	vecInt[1]; // 같은 표현이다.
	// 이처럼 함수로도 접근할 수 있고, 연산자 오버로딩 함수로도 접근할 수 있다.

	vecInt.data(); // 가변 배열의 데이터 시작 주소를 반환해주는 함수이다.
	// 클래스 템플릿 내 함수로 직접 구현: T* data() {return m_pData;}

	vecInt.size(); // 쌓인 데이터 개수를 반환해주는 함수이다.
	// 클래스 템플릿 내 함수로 직접 구현: int size() {return m_iCount;}

	vecInt.capacity(); // 데이터를 몇 칸 까지 집어넣을 수 있는지 알려주는 함수이다.
	// 클래스 템플릿 내 함수로 직접 구현: int capacity() {return m_iMaxCount;}

	// 배열 내 모든 데이터 순회하기
	for (size_t i = 0; i < vecInt.size(); ++i)
		// size_t 는 size 함수의 반환 타입이고, 타입을 맞춰준 것이다.
		// 따라서 size_t 는 자료형이며, long long 자료형을 타입 재정의한 이름이다.
		// 내부를 확인해보면 typedef unsigned __int64 size_t; 라고 명시되어 있다.
		// __int64 는 long long 과 같다.
	{
		// 데이터 출력
		cout << vecInt[i] << endl;
	}

	// 표준 연결형 리스트 기능
	list<int> listInt;
	listInt.push_back(10);
	listInt.push_front(20);

	listInt.size();
	// int size() {return m_iCount;

	// iterator(inner class)
	list<int>::iterator iter = listInt.begin();
	// list 클래스 안에 iterator 라는 클래스가 포함되어있다.
	// iterator 의 객체를 iter 라는 변수명으로 생성한 것이다.
	// begin 함수는 연결형 리스트 listInt 의 시작 데이터를 가리킨다.

	// 시작 데이터 확인하는법
	int iData = *iter;
	// iter 는 포인터가 아니라 클래스의 객체인데,
	// 포인터 변수를 역참조 하듯이 값을 확인하고 있다.
	// 사실 여기서 * 은 포인터가 아니라 연산자 오버로딩 함수(operator)로 설계되어있다.
	// 시작 노드를 가리키고 있던 것이었고, * 연산자를 만나면
	// 노드 내 멤버인 데이터 파트, 데이터 개수 파트 등 중에서
	// 데이터 파트를 반환해주는 원리이다.
	// 따라서 사용자로 하여금 iterator 클래스는 리스트의 해당 자료구조의 데이터를
	// 가리키고 지칭하는 포인터 같은 반복자 개념이다.

	return 0;
}