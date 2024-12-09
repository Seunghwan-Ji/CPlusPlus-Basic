#include <iostream>

using std::wcout;
using std::endl;

// 열거형
enum class MY_TYPE // class 키워드는 작성하지 않아도 되지만,
	// 다른 enum 클래스와 열겨형의 이름이 같으면 재정의 오류가 발생하므로,
	// class 키워드를 붙이고 아래에서 enum 클래스마다 '::' 키워드를 사용해
	// 구분을 지어서 사용하기 위함이다.
{
	// 열거형의 이름
	// 컴파일러는 연속적인 숫자로 받아들인다.
	TYPE_1, // 0
	TYPE_2, // 1
	TYPE_3, // 2
	TYPE_4, // 3
	TYPE_5 = 100, // 특정 숫자로 지정할 수도 있다.
	TYPE_6, // 101 지정한 숫자 다음부터는 다시 연속적으로 받아들인다.
};

enum class OTHER_TYPE
{
	TYPE_1,
};

// 전처리기 구문은 enum 과 흡사하다.
#define CLASS_1 0
#define CLASS_2 1
#define CLASS_3 2
#define CLASS_4 3
#define CLASS_5 4

int main()
{
	int a = (int)MY_TYPE::TYPE_1; // enum 을 클래스로 선언했을 경우,
	// enum 이라는 자료형으로 보기 때문에,
	// 지금과 같이 정수 자료형으로 바꾸려면
	// 같은 정수형 자료형으로 캐스팅 해줘야 한다.
	// 클래스 키워드를 작성하지 않았다면
	// int a = TYPE_1;

	OTHER_TYPE::TYPE_1; // 두 enum 모두 클래스로 선언했기 때문에 열거형 이름이 중복이어도 구별이 된다.

	// enum 이 전처리기 구문보다 나은점
	int b = CLASS_1; // 컴파일러는 CLASS_1 을 단순 0으로 본다.
	int b = (int)MY_TYPE::TYPE_1; // 반면에 이것은 같은 0이지만,
	// 컴파일러가 이 값이 어디 출신인지 기록하기 때문에
	// 디버깅 시 버그가 발생했을 때 기록한 곳을 참고하여
	// 문제 해결에 도움이 될 수 있다.

	return 0;
}