#pragma once

// ����ü�� �����ߴ� ���� �迭�� Ŭ������ �����غ���.
class CArr
{
private: // private Ű����� ���� �ʾƵ� ������� ����������, ��������� ���� ���̴�.
	int* m_pInt; // m_ �� ����� ���ڸ� �ǹ�.
	int  m_iCount;
	int  m_iMaxCount;

public:
	void push_back(int _Data);
	void resize(int _iResizeCount);

	int& operator[] (int idx); // ��ü�� ���� [] ������ ��� �� ȣ��Ǵ� �Լ�
	// ��ü�� ���� �迭�� �Ϲ� �迭ó�� ���� ���� �� �ε����Ͽ� ���� ������ �� �ֵ��� �ϴ� ���.

public:
	CArr(); // ������ �Լ��� ���� ó���ؾ� ��ü�� ������ �� �����ڸ� ȣ���� �� �ִ�.
	~CArr(); // �Ҹ��� �Լ��� ����������.
};