#include <iostream>
#include "CArr.h"

class CTest
{
private:
	int a;

public:
	CTest()
		: a(10)
	{

	}

};

int main()
{
	// ����ü --> Ŭ����

	// ��ü���� ��� Ư¡
	// 1. ĸ��ȭ
	// ����� �����ϱ� ���� �ʿ��� ��� ����, ����, ���м�
	// ��� �Լ���

	// 2. ���

	// 3. ������

	// 4. �߻�ȭ

	// ����ü ���� �����迭 --> Ŭ���� ����


	// C++ �����Ҵ� new, delete
	CTest* pTest = new CTest;
	delete pTest;

	// CArr(C++ Ŭ������ ���� ���� �迭) ��� ����
	CArr carr;
	carr.push_back(10);
	carr.push_back(20);
	carr.push_back(30);

	// carr �� ���������̱� ������, ���� �Լ��� ����� �� �������.
	// ���� �� ������ �����Ϸ��� �Ҹ��ڸ� ȣ�����ֱ� ������ �������� �޸𸮸� �������� �ʿ䰡 ����.

	// ����(C ����ü�� ���� ���� �迭) ��� ����
	/*
	tArr arr = {};
	InitArr(&arr);

	push_back(&arr, 10);
	push_back(&arr, 20);
	push_back(&arr, 30);

	ReleaseArr(&arr);
	*/

	// ��ü�� �迭ó�� ����ϱ�
	int iData = carr[1];
	carr[1] = 100;

	return 0;
}