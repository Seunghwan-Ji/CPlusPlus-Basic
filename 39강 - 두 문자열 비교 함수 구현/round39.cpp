#include <stdio.h>
#include <wchar.h> // ���̵� ���� ��Ʈ�� ���� ���
#include <assert.h> // ����ó�� �뵵

// �޸� ����
// 1. ����
// 2. ������
// 3. ��
// 4. ROM(�ۼ� �ڵ�)

// �� ���ڿ� ������ �� �Լ� ����
char StrBalance(const wchar_t* _str1, const wchar_t* _str2)
{
	char result = 0;
	int strIndex = 0;

	while (true)
	{
		// �ּҷ� ������������ �� ���� �ƽ�Ű �ڵ�ǥ���� ���ε� �����̱⿡, �� �������� ����.
		// ���ε� ���ڰ� �� �۰ų� ū���� ��.
		if (_str1[strIndex] < _str2[strIndex]) // ���� ���ڿ� ��
		{
			result = -1;
			break;
		}
		else if (_str1[strIndex] > _str2[strIndex]) // ������ ���ڿ� ��
		{
			result = 1;
			break;
		}
		else if (0 == _str1[strIndex] || 0 == _str2[strIndex]) // �� ���ڿ��� ���̰� �����鼭 ��ġ�� ����� ����
		{
			break;
		}
		else // �� ���ڰ� ���� ���
		{
			++strIndex;
		}
	}

	return result;
}

int main()
{
	int iRet2 = StrBalance(L"cb", L"abc");
	printf("%d\n", iRet2);

	return 0;
}