#include <stdio.h>
#include <wchar.h> // ���̵� ���� ��Ʈ�� ���� ���

// �޸� ����
// 1. ����
// 2. ������
// 3. ��
// 4. ROM(�ۼ� �ڵ�)

unsigned int GetLength(const wchar_t* _pStr)
{
	int icount = 0; // ���� ���� üũ �뵵

	while (true)
	{
		// wchar_t c = *(_pStr + icount); ���� �ּҷ� ���� 2����Ʈ ������ icount ��ŭ ����.
		wchar_t c = _pStr[icount]; // ���ڷ� ���� �迭�� ���� �ּҴ� �迭�� �̸��̱� ������ �̷��Ե� �ۼ��غ� �� �ִ�.

		// if (c == 0) 0 = '\0'(null ����), 0 ��� '\0' �̷��� �ۼ��ص� �ȴ�.
		if (0 == c) // == �� = ���� �߸� �Է��ϴ� �Ǽ��� �����ϱ� ���� ���������� ����� ���� ���� �ڿ� �������� ���°� ����.
		{
			break;
		}

		++icount;
	}

	// ����(�ۼ��� �ǵ� �ľ��� ������ �ݺ��� ���°� ���� ����.)
	/*while (0 != _pStr[icount])
	{
		++icount;
	}*/

	return icount;
}

int main()
{
	wchar_t szName[10] = L"Raimond";

	int iLen = GetLength(szName);
	printf("���ڿ��� ����: %d", iLen);

	return 0;
}