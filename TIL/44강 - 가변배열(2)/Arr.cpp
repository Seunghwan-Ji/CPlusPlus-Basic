#include "Arr.h"
#include <iostream>

void InitArr(tArr* _pArr)
{
	// �� 12����Ʈ �ڷ��� tArr ���� �� ����� �Ҵ��ϰ� �ִ� ���� ����.
	_pArr->pInt = (int*)malloc(sizeof(int) * 2); // int �����͸� �޴� ��Ʈ�� int�� ĳ������ �� �޸� ���� �ּ� ����(���÷� 8����Ʈ �Ҵ�)
	// _pArr->pInt = (int*)malloc(8); ���� ǥ��, �� �Ű����� ǥ������ �ܼ��� ����� ǥ��, int ũ����� * 2 = 4 * 2 = 8

	_pArr->iCount = 0; // ���� ������ ����.
	_pArr->iMaxCount = 2; // 8����Ʈ�� int�� 2ĭ�̹Ƿ�, �Ѱ�ġ ������ 2�� ����.
}

void Reallocate(tArr* _pArr)
{

}

void PushBack(tArr* _pArr, int _iData)
{
	// �� ������ �Ҵ��� ������ �� á�� ����� ����
	if (_pArr->iMaxCount <= _pArr->iCount)
	{
		// ���Ҵ�
		Reallocate(_pArr);
	}

	// ������ �߰�
	_pArr->pInt[_pArr->iCount++] = _iData; // �߰��� ������ ��ġ = ���� ������ ����, iCount++: ���� ������, �տ� ������ ������ ++ ����.
}                                          // �� �޸𸮵� �迭ó�� ���ӵ� �޸� ������� �Ҵ�Ǳ� ������ [] �����ڷ� �ε��� ǥ���� �����ϴ�.

void ReleaseArr(tArr* _pArr)
{
	free(_pArr->pInt); // �� �޸� ����
	_pArr->iCount = 0;
	_pArr->iMaxCount = 0;
	// �����߱� ������ ����Ű�� ������ �����Ƿ� ��� 0.
}
