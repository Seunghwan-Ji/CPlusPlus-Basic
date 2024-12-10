#include <iostream>
#include "CArr.h"

using std::cout;
using std::endl;

class CTest
{
public:
	int m_i;

public:
	// �ڵ����� �����Ǵ� �Լ��� ������, �Ҹ��� �Լ� ���� ���� ������ �Լ��� �ִ�.
	// ����:
	CTest& operator =(const CTest& _other)
	{
		m_i = _other.m_i;

		return *this;
	}
	// ���� ���� Ŭ���� ��ü���� ������ �߻��Ǹ� ���������� �ڵ����� ������ �� �Լ��� �����Ѵ�.

public:
	// �����ڵ� ���� �������� �����ε� �� �� �ִٴ� ���� �������.
	// ���� ������
	// ���� �����ڵ� �⺻ ������ ó�� �ڵ����� ��������� �Լ��̴�.
	// ����:
	CTest(const CTest& _other)
		: m_i(_other.m_i) // ������ ������ �Ǵ� _other �� ���� �޾ƿͼ� �ʱⰪ���� ����Ѵ�.
	{

	}
	// �⺻, ���� ������ �Լ��� �����Ϸ��� �⺻������ ������ִµ�,
	// �� ���� ���α׷��Ӱ� �� ������ ���� ������ �Լ��� ������� ������,
	// �����Ϸ��� �⺻ ������ �Լ��� ��������� �ʴ´�.
	// ���� �⺻ �����ڴ� �����ڰ� �ϳ��� ���� �� ���������.

	// �� ��� ������ ���� �⺻ �����ڵ� �ۼ��ؾ��Ѵ�.
	CTest()
		: m_i(0)
	{

	}

	// ���� �⺻ �����ڸ� �ۼ����� ��쿣 ���� �����ڴ� �����Ϸ��� �ڵ����� ������ش�.
};

int main()
{
	CArr<int> myVector;

	myVector.push_back(1);
	myVector.push_back(2);
	myVector.push_back(3);

	CArr<int>::iterator myIter = myVector.begin();
	*myIter;

	for (; myIter != myVector.end(); ++myIter)
	{
		cout << *myIter << endl;
	}

	myIter = myVector.begin();

	// ����, ���� ������ �Լ� �׽�Ʈ
	int iData = *(myIter++);
	// int iData = *(++myIter);


	// ���� ������ Ȱ��
	CTest t1;
	t1.m_i = 100;

	CTest t2;
	t2 = t1;

	// ���� ǥ��
	CTest t2(t1); // ���� �����ڷ� ��ü ������ ������ ���ÿ� �Ѵ�.

	CTest t3 = t1; // t3 ��ü�� �����ʰ� ���ÿ� ������ �ް� �ִ�.
	// ���� �����ڿ� ���� �����̹Ƿ�, �� ��쿣 �����Ϸ��� �ڵ�����
	// ���� �����ڸ� ȣ���ؼ� ������ ���� �ȴ�.
	CTest t3(t1);


	return 0;
}