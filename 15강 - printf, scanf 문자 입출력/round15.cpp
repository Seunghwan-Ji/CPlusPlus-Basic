#include <stdio.h> // �ڵ带 ������ �ϱ� ���� ��ó��(���� ó��) �ϴ� ����.

int main()
{
	// �ܼ�: �Է�/��� ��ġ, �Է�/��� �ܼ�â, �����쿡���� ��� ������Ʈ��� �Ҹ�. ������������ ��.

	// printf: ��� �Լ�
	//printf("����\n");
	//printf("abcdef %d\n", 10); // %d: �ι�° ������ ������ ġȯ.
	//printf("abcdef %f\n", 3.14f); // %f: �ι�° ������ �Ǽ��� ġȯ.

	for (int i = 0; i < 10; ++i)
	{
		printf("Output i : %d\n", i);
	}

	// scanf: �Է� �Լ�
	int iInput = 0;
	scanf_s("%d", &iInput); // scanf �Լ� ��� ���

	return 0;
}