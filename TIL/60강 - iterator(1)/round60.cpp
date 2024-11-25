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
	vector<int> vecInt; // 가변 배열
	vecInt.push_back(10);
	vecInt.push_back(20);

	// vector 도 iterator 라는 inner(내부) 클래스가 존재한다.
	vector<int>::iterator veciter = vecInt.begin();
	*veciter = 100; // 시작 데이터

	// 같은 표현
	vecInt[0] = 100;

	++veciter; // ++ 연산자를 만나면 다음 데이터를 가리킨다.

	list<int> listInt; // 연결형 리스트
	listInt.push_back(100);
	listInt.push_back(200);

	list<int>::iterator iter = listInt.begin();
	++iter; // 다음 데이터를 가리킨다.

	// 리스트 내 모든 데이터 순회하기
	for (iter = listInt.begin(); iter != listInt.end(); ++iter)
		// listInt.end() 는 마지막 데이터의 다음을 가리킨다.
		// 따라서 순회도중 iter 가 마지막 데이터가 되었을 때
		// listInt.end() 이 아니므로 조건에 충족한다.
	{
		cout << *iter << endl;
	}

	return 0;
}