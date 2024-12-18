int main()
{
	// 연산자
	// 대입 연산자: =
	// 산술 연산자
	// +, -, *, /, %(모듈러스, 나머지, 피연산자가 모두 정수)
	// ++, -- (증감 연산자): 한 단계 증가 또는 감소
	// 정수, 실수에서는 +1 증가, -1 감소로 볼 수 있다.
	int data = 0;
	++data; // 전위(전치)
	data++; // 후위(후치)
	// 후위 연산자로 사용하는 경우, 연산자 우선순위가 가장 나중으로 밀린다.

	data = 0;
	int a = 0;
	a = 10;
	data = ++a; // 전위 연산자이기 때문에 전위 연산자가 먼저 사용되어
	            // data 변수에는 11이 저장된다.
	data = a++; // 후위 연산자이기 때문에 대입 연산자가 먼저 사용되어
	            // data 변수에는 10이 저장된다.
	
	data = 0;
	data--;
	--data--;

	// 특별한 사유가 없다면 전위 연산자를 사용하는 습관을 갖는게 좋다.

	return 0;
}