#include <stdio.h> // �ڵ带 ������ �ϱ� ���� ��ó��(���� ó��) �ϴ� ����.

// ���� ����� ���� ���� �� ���ٸ�, �Լ��� �ۼ��ؼ� ���ȭ����
// ���丮��, n! ��� �Լ�
// ex) 4! = 1 * 2 * 3 * 4
int Factorial(int iNumber) // iNumber = n
{
	int iValue = 1;

	for (int j = 0; j < iNumber - 1; ++j)
	{
		iValue *= (j + 2);
	}

	printf("%d! = %d\n", iNumber, iValue);

	return iValue; // ���丮�� ��� ���
}

int main()
{
	// ���丮�� ��� �Լ� ȣ��
	int iValue = Factorial(4);
	iValue = Factorial(10);

	return 0;
}