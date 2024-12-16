int global = 0; // 전역변수

int Add(int left, int right) // 함수명 Add 앞에 데이터 타입 표기는 반환할 때 값의 데이터 타입이다.
							 // 인자로 전달 받은 left, right는 지역변수이다.(함수 안에서 선언된 변수이기 때문이다.)
{
	return left + right;
}

int main() // 함수
{
	// 변수
	// 1. 지역변수
	// 2. 전역변수
	// 3. 정적변수
	// 4. 외부변수

	// 지역변수
	int iName = 0;

	// 괄호 안에 선언된 변수(함수, 지역)
	{ // { } 지역 생성
		// 변수명 규칙
		int iName = 100;
		iName = 200; // 이 지역의 변수 int iName = 100; 의 값을 수정한다.
		{ // 지역 생성
			{ // 지역 생성, 내부적으로 지역안에 지역을 계속 생성할 수 있다.

			}
		}
	}

	iName = 100; // 이 지역의 변수 int iName = 0; 의 값을 수정한다.

	// 함수
	int data = 0;
	
	data = Add(10, 20);

	return 0;

}