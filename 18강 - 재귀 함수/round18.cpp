#include <stdio.h> // �ڵ带 ������ �ϱ� ���� ��ó��(���� ó��) �ϴ� ����.

// ��� �Լ�
// �ڱ� �ڽ� �Լ��� ȣ���ص� �ٸ� �Լ��� ȣ���ϴ� ��ó�� ���� �޸� �������� ���ο� ������ ����Ѵ�.
int Factorial(int iNumber) // iNumber = n
{
	int iValue = 1;

	for (int j = 0; j < iNumber - 1; ++j)
	{
		iValue *= (j + 2);
	}

	// Factorial(10);
	// ����, �ӵ��� ������.
	// ��� �Լ��� �߸� ���� �Լ� ���� �޸𸮰� �׿��� '���� ���� �÷ο�' ������ �߻��Ѵ�.

	// ��� �Լ��� �ùٸ��� ����� �� ����
	// ������, ������ ����

	printf("%d! = %d\n", iNumber, iValue);

	return iValue;
}

int main()
{
	int iValue = Factorial(4);

	return 0;
}