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
	}
};

int main()
{
	// 객체지향 언어의 특징
	// 1. 캡슐화 (은닉성)
	// 2. 상속
	// 3. 다형성
	// 4. 추상화

	CParent parent;
	CChild child;

	// 오버라이딩
	// 부모 클래스의 멤버함수를 자식쪽에서 재정의 함으로써, 자식 클래스에 구현된 기능이 호출되도록 한다.
	parent.Output();
	child.Output(); // 자식 클래스쪽의 Output 함수가 호출된다.
	// 부모쪽에도 같은 함수가 있지만, 컴파일러는 자식 클래스쪽에서 재정의 했다고 판단한다.
	// 이러한 함수를 오버라이딩 함수라고 한다.

	child.CParent::Output(); // 이 경우엔 부모쪽 함수를 호출한다.

	return 0;
}