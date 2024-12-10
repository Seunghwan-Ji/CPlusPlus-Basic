#include <iostream>
#include "Arr.h"
#include <time.h> // �ð� Ȯ�ΰ� ���� �Լ� ��� ����

void BubbleSort(int* _pData, int _iCount)
{
	// �����Ͱ� 1�� ���ϸ� �������� ����.
	if (_iCount <= 1)
		return;

	// �������� ����(���� ���� �˰��� ���)
	while (true)
	{
		bool bFinish = true; // ���� �����߿� ��ü�� �Ͼ���� Ȯ�ο�.

		int iLoop = _iCount - 1; // ������ ���� n�����, ���ϴ� Ƚ���� n-1���̴�.

		// ���� ���� �� ����Ŭ ���� ����.
		for (int i = 0; i < iLoop; ++i)
		{
			if (_pData[i] > _pData[i + 1])
			{
				int iTemp = _pData[i]; // �ű� ���� ���������� �ӽ� ����.
				_pData[i] = _pData[i + 1]; // ��ü.
				_pData[i + 1] = iTemp; // �����ص� �� ����.

				bFinish = false; // ��ü�� �Ͼ�� �˸�.
			}
		}

		if (bFinish)
			break; // ���� ���� �� ����Ŭ�� ������ �� ��ü�� �Ͼ�� �ʾҴٸ�, ��ü������ ������ �������Ƿ� ���� ����.
	}
}

void Test()
{

}

int main()
{
	// �Լ� ������
	// �Լ��� �ּҸ� ������ �ٸ� �Լ����� ������ �Լ��� ����� ���.
	// �Լ��� �̸� ��ü�� �ּҷ� �����ȴ�.

	// �Լ� ������ ���� ���
	void(*pFunc)(void) = nullptr; // ��ȯ Ÿ�� void, �Լ� ������ ����, ���� void
	// ���� ��ÿ� �ּҿ� �ش��ϴ� �Լ��� ����(��ȯ Ÿ��, ���� Ÿ��)�� ������� �Ѵ�.
	pFunc = Test;

	// �Ǵ� void(*pFunc)(void) = Test;

	pFunc(); // Test �Լ��� ȣ���Ѵ�.

	int iArr[10] = { 87, 644, 21, 55, 879, 654, 55, 131 };

	BubbleSort(iArr, 10);

	tArr s1 = {};

	InitArr(&s1);

	srand(time(nullptr));

	// 1 ~ 100 ������ ������ ���� ������ ����.
	for (int i = 0; i < 10; ++i)
	{
		int iRand = rand() % 100 + 1;
		PushBack(&s1, iRand);
	}

	// ������ Ȯ��.
	printf("���� ��\n");
	for (int i = 0; i < s1.iCount; ++i)
	{
		printf("%d\n", s1.pInt[i]);
	}

	// ������ ���� �� ��Ȯ��.
	printf("\n���� ��\n");

	Sort(&s1, &BubbleSort); // �Լ� �̸� ��ü�� �ּ�������, & �����ڸ� �ٿ� �ǵ��� ��������� ǥ���ص� �ȴ�.

	for (int i = 0; i < s1.iCount; ++i)
	{
		printf("%d\n", s1.pInt[i]);
	}

	// ���α׷� �����ϱ� ��, �Ҵ���� �� �޸� ����.
	ReleaseArr(&s1);

	return 0;
}

// ���������� ���� ���� �ܿ� �پ��� ���� ����� ������ ����
// - ���� ����
// - ���� ����
// - �պ� ����(merge)
// - ��� ����(quick)
// - �� ����(���� ����Ʈ��, �迭)

// �� �Լ����� �����ؼ� Sort �Լ��� ������ �׽�Ʈ �غ���.