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

	void Output()
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

	// 상속받은 부모 클래스의 함수를 재정의(오버라이딩)함.
	void Output()
	{
		cout << "Child" << endl;
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

void FuncA()
{
	cout << "Function A" << endl;
}

void FuncB()
{
	cout << "Function B" << endl;

	FuncA();
}

int main()
{
	// 객체지향 언어의 특징
	// 1. 캡슐화 (은닉성)
	// 2. 상속
	// 3. 다형성
	// 4. 추상화

	CChild child;

	FuncB();
	// 함수 호출 순서  : FuncB -> FuncA
	// 실행이 끝난 순서: FuncB -> FuncA

	// 소멸자 호출 순서: 자식 클래스(CChild) -> 부모 클래스(CParent)
	// 소멸이 끝난 순서: 자식 클래스(CParent) -> 부모 클래스(CChild)
	return 0;
}