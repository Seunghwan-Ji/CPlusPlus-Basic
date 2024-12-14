#include <iostream>

using std::cout;
using std::endl;

class CParent
{
protected:
	int m_i;

public:
	void SetInt(int _a)
	{
		m_i = _a;
	}

	// 가상 함수
	virtual void Output()
	{
		cout << "Parent" << endl;
	}

public:
	CParent()
		: m_i(0)
	{
		cout << "부모 생성자" << endl;
	}

	CParent(int _a)
		: m_i(_a)
	{
		cout << "부모 생성자2" << endl;
	}

	~CParent()
	{
		cout << "부모 소멸자" << endl;
	}
};

class CChild : public CParent
{
private:
	float m_f;

public:
	void SetFloat(float _f)
	{
		m_f = _f;
		m_i = 100;
	}

	// 상속받은 부모 클래스의 함수를 재정의(오버라이딩) 함으로써 가상 함수를 자동으로 전달받음.
	void Output()
	{
		cout << "Child" << endl;
	}

	void NewFunc()
	{
	}

public:
	CChild()
		: m_f(0.f)
	{
		m_i = 0;
		cout << "자식 생성자" << endl;
	}

	~CChild()
	{
		cout << "자식 소멸자" << endl;
	}
};

int main()
{
	// 객체지향 언어의 특징
	// 1. 캡슐화 (은닉성)
	// 2. 상속
	// 3. 다형성
	// 4. 추상화

	// 다형성(다양한 형태의 성질)
	CParent parent;
	CChild child;

	CParent* pParent = nullptr;

	parent.Output(); // 부모쪽 함수 호출.
	pParent = &parent;
	pParent->Output(); // 부모쪽 함수 호출.

	child.Output(); // 자식쪽 함수 호출.
	pParent = &child;
	pParent->Output(); // 자식쪽 함수 호출.

	// 가상 함수
	// 1. virtual 키워드 사용:
	//    - 기본 클래스의 함수 앞에 virtual 키워드를 붙이면 가상 함수로 선언된다.
	// 2. 동적 바인딩:
	//    - 기본 클래스 포인터나 참조를 통해 호출되는 함수가, 포인터가 가리키는 실제 객체의 타입에 따라 동작한다.
	//    - 이를 통해 상속받은 클래스에서 함수의 동작을 재정의(override)할 수 있다.
	// 3. 가상 함수 테이블(Virtual Table, vtable):
	//    - 가상 함수는 내부적으로 vtable이라는 구조로 관리된다.
	//    - 객체마다 vtable의 참조가 저장되며, 함수 호출 시 vtable을 참조해 적절한 함수가 실행된다.

	// 가상 함수는 컴파일 시점이 아니라 실행 시점에 호출할 함수를 결정한다.
	// 이것이 정적 바인딩(static binding)과의 차이이다.

	// 부모쪽에서 가상 함수로 정의된 멤버 함수를, 자식쪽에서 재정의(override) 하면,
	// 상속 계층에서 자동으로 전달되는 성질에 따라 자식쪽 함수도 가상 함수가 된다.
	// 따라서 부모쪽의 가상 함수를 자식쪽에서 재정의 할 때, virtual 키워드를 생략해도 되지만
	// 명시적으로 적어주면 좋다.

	// 다운 캐스팅
	// 부모 클래스에서 선언되지 않은, 오직 자식쪽에서만 추가된 함수를 호출하고 싶을때
	// 자식 포인터 타입으로 일시적으로 캐스팅해서 호출한다.
	// 문제가 발생할 수 있기 때문에 dynamic_cast 로 안전하게 확인해 볼 수 있다.
	// RTTI(Run Time Type Identification or Information): 런타임 도중, 객체의 타입의 정보를 알다.
	pParent = &child;

	((CChild*)pParent)->NewFunc(); // C 스타일, 부모 포인터 타입을 자식 포인터 타입으로 강제 캐스팅 후, 함수 호출.

	// C++ 스타일
	// 부모 포인터 타입을 dynamic_cast 를 통해 자식 포인터 타입으로 캐스팅한다.
	// 만약 pParent = &parent; 이 구문이었다면, C 스타일 구문에서는
	// 부모 객체의 주소를 자식 포인터 타입으로 강제 캐스팅하여 접근 시도를 했기 때문에 오류가 발생한다.
	// 반면 C++ 구문에서는 dynamic_cast 를 활용했을 때, 잘못 접근하여 캐스팅을 실패 했다면 null 포인터를 반환한다.
	// 따라서 dynamic_cast 는 다운 캐스팅에 실패 했을때를 대비할 수 있다.
	CChild* pChild = dynamic_cast<CChild*>(pParent);
	if (nullptr != pChild)
	{
		pChild->NewFunc();
	}
	else
	{
		cout << "캐스팅 실패" << endl;
	}

	// dynamic_cast 동작 원리
	// 가상 함수 : 클래스가 다형성을 가지도록 설계하며, dynamic_cast의 기초를 제공.
	// 가상 테이블(vtable) : 객체의 실제 타입을 추적하기 위한 데이터 구조로, dynamic_cast가 이를 통해 RTTI 정보를 가져옴.
	// RTTI : 런타임에 객체의 실제 타입을 확인하여 안전한 형 변환을 가능하게 함.
	// dynamic_cast는 이 세 요소를 기반으로 다형성 객체의 타입을 런타임에 안전하게 변환할 수 있도록 설계된 도구이다.
	return 0;
}