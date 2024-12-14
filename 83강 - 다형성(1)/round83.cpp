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
	/*virtual void Output()
	{
		cout << "Parent" << endl;
	}*/

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

int main()
{
	// 객체지향 언어의 특징
	// 1. 캡슐화 (은닉성)
	// 2. 상속
	// 3. 다형성
	// 4. 추상화

	// 다형성
	CParent parent;
	CChild child;

	CParent* pParent = &child;
	// CChild* pChild = &parent; // 문법 오류.

	// 부모 클래스로 부터 상속받은 모든 클래스는, 부모 포인터가 가리킬 수 있다.
	// 자식 클래스들은 메모리 구조에서 시작 주소가 부모 클래스이기 때문이다.
	// 따라서 부모 포인터 변수가 저장한 주소는, 여러 자식이 상속을 받았으면
	// 파생된 자식 클래스 객체들중 하나이다.

	pParent = nullptr;

	parent.Output(); // 부모쪽 함수 호출.
	pParent = &parent;
	pParent->Output(); // 부모쪽 함수 호출.

	child.Output(); // 자식쪽 함수 호출.
	pParent = &child;
	pParent->Output(); // 부모쪽 함수 호출, 자식 객체의 주소가 저장되었지만,
	// 포인터 타입이 부모 타입이기 때문에,
	// 역참조할 때 부모 자료 타입까지만 읽어서 부모쪽 함수가 호출된다.

	// 부모쪽 멤버 함수를 가상함수로 정의하면, 자식 객체의 자료 타입까지
	// 모두 읽어들일 수 있어 자식쪽 멤버 함수를 호출시킬 수 있게된다.
	return 0;
}