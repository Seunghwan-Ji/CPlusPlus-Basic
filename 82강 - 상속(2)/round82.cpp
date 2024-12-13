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
		cout << "�θ� ������" << endl;
	}

	CParent(int _a)
		: m_i(_a)
	{
		cout << "�θ� ������2" << endl;
	}

	~CParent()
	{
		cout << "�θ� �Ҹ���" << endl;
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

	// ��ӹ��� �θ� Ŭ������ �Լ��� ������(�������̵�)��.
	void Output()
	{
		cout << "Child" << endl;
	}

public:
	CChild()
		: m_f(0.f)
	{
		m_i = 0;
		cout << "�ڽ� ������" << endl;
	}

	~CChild()
	{
		cout << "�ڽ� �Ҹ���" << endl;
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
	// ��ü���� ����� Ư¡
	// 1. ĸ��ȭ (���м�)
	// 2. ���
	// 3. ������
	// 4. �߻�ȭ

	CChild child;

	FuncB();
	// �Լ� ȣ�� ����  : FuncB -> FuncA
	// ������ ���� ����: FuncB -> FuncA

	// �Ҹ��� ȣ�� ����: �ڽ� Ŭ����(CChild) -> �θ� Ŭ����(CParent)
	// �Ҹ��� ���� ����: �ڽ� Ŭ����(CParent) -> �θ� Ŭ����(CChild)
	return 0;
}