#include <stdio.h> // �ڵ带 ������ �ϱ� ���� ��ó��(���� ó��) �ϴ� ����.

// ��� �Լ� ���丮��
int Factorial_Re(int iNumber)
{
	if (iNumber == 1)
	{
		return 1;
	}

	return iNumber * Factorial_Re(iNumber - 1);
	// 4 * 3!
	// 3 * 2!
	// 2 * 1!

	// 2 * 1
	// 3 * 2
	// 4 * 6
}

// �Ǻ���ġ ����
// 1 1 2 3 5 8 13 21 34 55...
// 1 + 1 = 2
// 1 + 2 = 3
// 2 + 3 = 5
// ...
// n>2�� ��, n��° ���� (n-2)�� ����Ѵ�.(3��° ���� �� ��, 4��° ���� �� ��)
int Fibonacci(int iNumber) // �Լ��� �Ǻ���ġ ���� ����
{
	if (iNumber == 1 || iNumber == 2)
	{
		return 1; // n��° �����߿� ù��°�� �ι�° ���� 1 ����
	}

	int iPrev1 = 1;
	int iPrev2 = 1;
	int iValue = 0;

	for (int i = 0; i < iNumber - 2; ++i)
	{               // (n-2)�� �ݺ�
		iValue = iPrev1 + iPrev2;
		iPrev1 = iPrev2;
		iPrev2 = iValue;
	}

	return iValue;
}

// ��� �Լ��� �Ǻ���ġ ���� ����
// n��° �� = (n-2)° �� + (n-1)° ��
int Fibonacci_Re(int iNumber)
{
	if (iNumber == 1 || iNumber == 2)
	{
		return 1; // ù��° �ι�° ���� 1 ����
	}

	return Fibonacci_Re(iNumber - 2) + Fibonacci_Re(iNumber - 1);
	// Fibonacci_Re(2) + Fibonacci_Re(3)
	// 1 + Fibonacci_Re(1) + Fibonacci_Re(2)
	// 1 + 1 + 1
	// = 3
}
// �Ϲ� ��� �Լ��� �ӵ��� ������ ������ ���ʹ�° ���� ���ϱ� ���� �ɸ��� �ð��� �������� �Ѿ��.
// �׷��Ƿ� ���߿� ��� �޸� ��뷮�� ���̴� ���� ��͸� Ȱ���ؾ� �Ѵ�.

int main()
{
	int iValue = Factorial_Re(4); // 4!
	printf("%d\n", iValue);

	iValue = Fibonacci(4); // 4��° ��
	printf("%d\n", iValue);

	iValue = Fibonacci_Re(4);
	printf("%d\n", iValue);

	return 0;
}