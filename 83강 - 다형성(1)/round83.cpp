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

	// ���� �Լ�
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

int main()
{
	// ��ü���� ����� Ư¡
	// 1. ĸ��ȭ (���м�)
	// 2. ���
	// 3. ������
	// 4. �߻�ȭ

	// ������
	CParent parent;
	CChild child;

	CParent* pParent = &child;
	// CChild* pChild = &parent; // ���� ����.

	// �θ� Ŭ������ ���� ��ӹ��� ��� Ŭ������, �θ� �����Ͱ� ����ų �� �ִ�.
	// �ڽ� Ŭ�������� �޸� �������� ���� �ּҰ� �θ� Ŭ�����̱� �����̴�.
	// ���� �θ� ������ ������ ������ �ּҴ�, ���� �ڽ��� ����� �޾�����
	// �Ļ��� �ڽ� Ŭ���� ��ü���� �ϳ��̴�.

	pParent = nullptr;

	parent.Output(); // �θ��� �Լ� ȣ��.
	pParent = &parent;
	pParent->Output(); // �θ��� �Լ� ȣ��.

	child.Output(); // �ڽ��� �Լ� ȣ��.
	pParent = &child;
	pParent->Output(); // �θ��� �Լ� ȣ��, �ڽ� ��ü�� �ּҰ� ����Ǿ�����,
	// ������ Ÿ���� �θ� Ÿ���̱� ������,
	// �������� �� �θ� �ڷ� Ÿ�Ա����� �о �θ��� �Լ��� ȣ��ȴ�.

	// �θ��� ��� �Լ��� �����Լ��� �����ϸ�, �ڽ� ��ü�� �ڷ� Ÿ�Ա���
	// ��� �о���� �� �־� �ڽ��� ��� �Լ��� ȣ���ų �� �ְԵȴ�.
	return 0;
}