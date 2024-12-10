int main()
{
	// 자료형 (크기 단위, byte) Data Type
	// 정수형: char(1), short(2), int(4), long(4), long long(8)
	// 실수형: float(4), double(8)

	// 연산자
	// 대입 연산자: =
	// 산술 연산자
	// +, -, *, /, %(모듈러스, 나머지, 피연산자가 모두 정수)
	// ++, -- (증감 연산자): 한 단계 증가 또는 감소(정수, 실수에서는 +1 증가, -1 감소로 볼 수 있다.)

	// 논리 연산자
	// !(역), &&(and), ||(or)
	// 참(true), 거짓(false)
	// 참  : 0 이 아닌 값, 주로 1
	// 거짓: 0
	// bool 자료형은 참과 거짓만 다루기 때문에 수치로 표현하면 0 과 1 로만 표현된다.

	// 비교 연산자
	// ==, !=, <, <=, >, >=
	// 참, 거짓

	// 구문
	// if, else
	// switch case
	int iTest = 20;
	
	switch (iTest)
	{
	case 10:

		break // 기본적으로 switch문은 조건이 맞는 case를 찾고나면, 그 이후에는 조건 검사를 다시 하지 않고 모든 case를 실행한다.
			  // 그러므로 break를 적어주면 다른 case들을 실행하지 못하게 할 수 있다.
	case 20:

		break
	default:

		break;
	}

	// 조건문으로 똑같이 표현
	if (iTest == 10)
	{

	}
	else if (iTest == 20)
	{

	}
	else
	{

	}

	// 여러 case를 묶는 경우
	switch (iTest)
	{
	case 10:
	case 20:
	case 30:
		// iTest 변수가 10 or 20 or 30일 경우 모두 수행.
		break
	default:

		break;
	}

	// 조건문으로 똑같이 표현
	if (iTest == 10 || iTest == 20 || iTest == 30) // or(||) 연산자 사용
	{

	}
	else
	{

	}

	// 삼항 연산자
	// :?
	iTest == 20 ? iTest = 100 : iTest = 200;
	//   조건       참일 경우    거짓일 경우

	// 조건문으로 똑같이 표현
	if (iTest == 20)
	{
		iTest = 100;
	}
	else
	{
		iTest = 200;
	}

	return 0;

}