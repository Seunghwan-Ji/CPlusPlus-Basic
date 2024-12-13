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
		m_i = 100; // �θ� Ŭ������ ��� �޾�����, �θ� Ŭ���� �ʿ���
		// �� ��� ������ �����(private) ó�� �Ǿ��ٸ� ������ �� ����.
		// �̶� �θ��� ��� ������ protected ó�� �Ǿ��ٸ�
		// �ڽ� Ŭ���� ���ο����� ������ �� �ִ�.
	}

public:
	CChild()
		//  : CParent() �ڽ��� ����� �ʱ�ȭ �ϱ����� �θ� �����ڸ� ȣ���ϴ� ������ �����ִ�.(������ ����)
		//  : CParent(1000) �⺻������ �θ��� �⺻ �����ڸ� ȣ��������, �̷��� ��� ���ָ�
		//                  �����ε��� �����ڸ� ȣ���� �� �ִ�.
		: m_f(0.f)
		//  , m_i(0) ��� ���� �ʱ�ȭ�� ���� �ڱ� Ŭ���� �������� �����ϴ�.
		//  , CParent() �θ� �����ڸ� �ʰ� ȣ���ߴٰ� �ؼ� �ڽ��� ��� ������ ���� �ʱ�ȭ �Ǵ� ���� �ƴϴ�.
	{
		m_i = 0; // �� ������ �ʱ�ȭ ������ �ƴϹǷ� �θ��� ��� ���� ������ �����ϴ�.
		cout << "�ڽ� ������" << endl;
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
// CChildChild Ŭ���� ��ü�� ������� ���� �޸� ������
// ���������� CParent, CChild, CChildChild ��Ʈ��� �̷���� �������� ��ü�� �����ȴ�.
// (�θ� ��Ʈ���� �ڽ� ��Ʈ ����)

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
	// ��ü���� ����� Ư¡
	// 1. ĸ��ȭ (���м�)
	// 2. ���
	// 3. ������
	// 4. �߻�ȭ

	CParent parent;
	CChild child;

	parent.SetInt(10);
	// parent.m_i = 10; // �ڽ� Ŭ���� ���ο����� ������ �� �ְ�, �ܺο����� ������ �� ���� ��� ����.
	child.SetInt(10); // �θ� Ŭ������ ��� �Լ� ȣ�� ����.

	FuncB();
	// �Լ� ȣ�� ����  : FuncB -> FuncA
	// ������ ���� ����: FuncA -> FuncB

	CChild child2;
	// ������ ȣ�� ����  : �ڽ� Ŭ����(CChild) -> �θ� Ŭ����(CParent)
	// �ʱ�ȭ�� ���� ����: �θ� Ŭ����(CParent) -> �ڽ� Ŭ����(CChild)


	// ���
	// �ڽ� or �θ� Ŭ������ ��� ���迡�� �ٸ� Ŭ������ ����� �ʱ�ȭ �� �� ����.

	return 0;
}