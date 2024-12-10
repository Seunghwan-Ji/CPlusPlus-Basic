#include <stdio.h>
#include <wchar.h> // ���̵� ���� ��Ʈ�� ���� ���
#include <assert.h> // ����ó�� �뵵

// �޸� ����
// 1. ����
// 2. ������
// 3. ��
// 4. ROM(�ۼ� �ڵ�)

// �Լ� �����ε�
// �̸��� ���� �Լ��� ������ ����, ������ Ÿ���̳� ������ ���̿� ���� ������ �̸��� �Լ��� ������ �ۼ��� �� �ִ�.
// Ŭ�������� �ٷ�� '�Լ� �������̵�'�� �ٸ� �����̴�.
void Test(int a)
{

}

void Test(float a)
{

}

unsigned int GetLength(const wchar_t* _pStr)
{
	int icount = 0; // ���� ���� üũ �뵵

	while (true)
	{
		wchar_t c = _pStr[icount];

		if (0 == c)
		{
			break;
		}

		++icount;
	}

	return icount;
}

// ���ڿ� �̾� ���̱� �Լ� ����
void StrCat(wchar_t* _pDest, unsigned int _iBufferSize, const wchar_t* _pSrc) // �迭 ������� ����� ���̱� ������ unsigned �� ���δ�.
{
	// ����ó��
	// �̾���� ���� ���ڿ� ���̰�, ������ ���� ������ �Ѿ���� ���.
	int iDestLen = GetLength(_pDest);
	int iSrcLen = GetLength(_pSrc);

	if (_iBufferSize < iDestLen + iSrcLen + 1) // NULL ���� �������� ���
	{
		assert(nullptr); // ���ڷ� ���� _iBufferSize ������ ���� �ʰ��� ����ó��
	}

	// ���ڿ� �̾� ���̱� ����
	// 1. Dest ���ڿ��� ���� Ȯ��(���ڿ��� �̾� ���� ���� ��ġ)
	// 2. �ݺ������� Src ���ڿ��� Dest �� ��ġ�� �����ϱ�
	// 3. Src ���ڿ��� ���� ������ �ݺ� ����

	// iDestLen: Dest ���ڿ��� �� �ε���
	for (int i = 0; i < iSrcLen + 1; ++i) // iSrcLen + 1: null(�޸� ������ 0) ���ڸ� ���Խ�Ű�� ���� �� ���� �ݺ�.
	{
		_pDest[iDestLen + i] = _pSrc[i];
	}
}

int main()
{
	Test(10);
	Test(4.15f);

	// ���ڿ� �̾� ���̱�
	wchar_t szString[100] = L"abc";

	wcscat_s(szString, 100, L"def"); // �Ű�����: ���ڿ� �迭�� ���� �ּ�, ���� �迭�� ������, �̾���� ���̵� ����Ʈ(�����ڵ�)�� ���ڿ�
	wprintf(L"%s\n", szString);

	wcscat_s(szString, 100, L"ghi");
	wprintf(L"%s\n", szString);


	wchar_t szString2[5] = L"abc";

	// wcscat_s(szString2, 5, L"defghi"); �̾� ���� ������ ���°� ����� �ʰ��ؼ� ����ó�� �߻�.

	StrCat(szString2, 5, L"d");
	wprintf(L"%s\n", szString2);

	// StrCat(szString2, 5, L"de"); null ���ڸ� ������ ����� 6���� �ʰ��ϹǷ� ���� ������ �Լ����� ����ó�� �߻�.

	// wcscmp: �� ���ڿ��� ��ġ�ϸ� 0, ���������� ������ ������ -1, �������� ������ 1 �� ��ȯ�ϴ� �Լ�.
	int iRet = wcscmp(L"abc", L"abc");
	printf("%d\n", iRet);

	return 0;
}