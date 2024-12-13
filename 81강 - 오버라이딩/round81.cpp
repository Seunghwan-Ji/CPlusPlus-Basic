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
	}
};

int main()
{
	// ��ü���� ����� Ư¡
	// 1. ĸ��ȭ (���м�)
	// 2. ���
	// 3. ������
	// 4. �߻�ȭ

	CParent parent;
	CChild child;

	// �������̵�
	// �θ� Ŭ������ ����Լ��� �ڽ��ʿ��� ������ �����ν�, �ڽ� Ŭ������ ������ ����� ȣ��ǵ��� �Ѵ�.
	parent.Output();
	child.Output(); // �ڽ� Ŭ�������� Output �Լ��� ȣ��ȴ�.
	// �θ��ʿ��� ���� �Լ��� ������, �����Ϸ��� �ڽ� Ŭ�����ʿ��� ������ �ߴٰ� �Ǵ��Ѵ�.
	// �̷��� �Լ��� �������̵� �Լ���� �Ѵ�.

	child.CParent::Output(); // �� ��쿣 �θ��� �Լ��� ȣ���Ѵ�.

	return 0;
}