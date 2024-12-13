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
		m_i = 100; // 부모 클래스를 상속 받았지만, 부모 클래스 쪽에서
		// 이 멤버 변수가 비공개(private) 처리 되었다면 접근할 수 없다.
		// 이때 부모쪽 멤버 변수가 protected 처리 되었다면
		// 자식 클래스 내부에서만 접근할 수 있다.
	}

public:
	CChild()
		//  : CParent() 자신의 멤버를 초기화 하기전에 부모 생성자를 호출하는 과정이 숨어있다.(숨겨진 구문)
		//  : CParent(1000) 기본적으로 부모의 기본 생성자를 호출하지만, 이렇게 명시 해주면
		//                  오버로딩된 생성자를 호출할 수 있다.
		: m_f(0.f)
		//  , m_i(0) 멤버 변수 초기화는 각자 자기 클래스 내에서만 가능하다.
		//  , CParent() 부모 생성자를 늦게 호출했다고 해서 자식의 멤버 변수가 먼저 초기화 되는 것이 아니다.
	{
		m_i = 0; // 이 구문은 초기화 과정이 아니므로 부모의 멤버 변수 접근이 가능하다.
		cout << "자식 생성자" << endl;
	}

	~CChild()
	{
	}
};

class CChildChild : public CChild
{
private:
	long long m_ll;
};
// CChildChild 클래스 객체를 만들었을 떄의 메모리 구조가
// 순차적으로 CParent, CChild, CChildChild 파트들로 이루어진 사이즈의 객체가 생성된다.
// (부모 파트부터 자식 파트 까지)

void FuncA()
{
	cout << "Function A" << endl;
}

void FuncB()
{
	FuncA();

	cout << "Function B" << endl;
}

int main()
{
	// 객체지향 언어의 특징
	// 1. 캡슐화 (은닉성)
	// 2. 상속
	// 3. 다형성
	// 4. 추상화

	CParent parent;
	CChild child;

	parent.SetInt(10);
	// parent.m_i = 10; // 자식 클래스 내부에서만 접근할 수 있고, 외부에서는 접근할 수 없는 멤버 변수.
	child.SetInt(10); // 부모 클래스쪽 멤버 함수 호출 가능.

	FuncB();
	// 함수 호출 순서  : FuncB -> FuncA
	// 실행이 끝난 순서: FuncA -> FuncB

	CChild child2;
	// 생성자 호출 순서  : 자식 클래스(CChild) -> 부모 클래스(CParent)
	// 초기화가 끝난 순서: 부모 클래스(CParent) -> 자식 클래스(CChild)


	// 상속
	// 자식 or 부모 클래스는 상속 관계에서 다른 클래스의 멤버를 초기화 할 수 없다.

	return 0;
}