#include <iostream>
#include "LinkedList.h"

int main()
{
	CList<int> list; // int ������ ����Ʈ�� ��尡 ���������.
	// CList: Ŭ���� ���ø�
	// CList<int>: ������ Ŭ����

	// ���� 0~3 ���� ����, ������� ���� ����Ʈ�� Ȯ���غ���.
	for (int i = 0; i < 4; ++i)
	{
		list.push_back(i);
	}

	// printf(): C��� ��� �Լ�
	// std::cout: C++ ��� ���
	std::cout << "�ȳ�" << 10 << std::endl; // std::endl: �ٹٲ�
	// Ư¡: %d, %s ���� ����� �ʿ���� �ڵ����� �ڷ����� �м��Ͽ� ������ش�.

	// scanf(): C��� �Է� �Լ�
	// std::cin: C++ �Է� ���
	int iInput = 0;
	std::cin >> iInput;

	return 0;
}