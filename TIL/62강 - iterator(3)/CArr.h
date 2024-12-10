#pragma once

#include <assert.h>

template<typename T>
class CArr
{
private:
	T* m_pData;
	int  m_iCount;
	int  m_iMaxCount;

public:
	void push_back(const T& _Data);
	void resize(int _iResizeCount);
	T* data() { return m_pData; }
	int size() { return m_iCount; }
	int capacity() { return m_iMaxCount; }
	T& operator[] (int idx);

	class iterator;
	iterator begin();
	iterator end();

public:
	CArr();
	~CArr();

	// inner Ŭ������ �� Ŭ������ �����ϰ� �ִ� Ŭ������ private ����� ������ �����ϴ�.
	class iterator
	{
	private:
		CArr* m_pArr; // iterator �� ����ų �����͸� �����ϴ� ���� �迭 �ּ�
		// �� �޸𸮰� ���Ҵ�Ǹ� �迭�� ���� �ּҰ� �ٲ�Ƿ�,
		// CArr�� ��ü ��ü�� �ּҸ� �޴´�.
		T* m_pData; // �����͵��� ���� �ּ�
		int   m_iIdx; // ����Ű�� �������� �ε���

	public:
		T& operator * () // CArr�� ��� �ڷ������� ��ü�� ���� �� �ִ� Ŭ�����̹Ƿ�,
			// ��ȯŸ���� T ���Ѵ�.
			// �׷��� �׳� T �� ������ �ִ� ���� �ƴϴ�.
			// ���� ����ڰ� ��ȯ���� �޾Ƽ� ������ �� �� �ְ� T& ���·� ��ȯ�Ѵ�.
		{
			// iterator �� �˰��ִ� �ּҿ� ���� �迭�� �˰��ִ� �ּҰ� ���� �ٸ� ����� ����
			// (���� Ȯ������ ���� �ּҰ� �޶��� ���)
			// �Ǵ� iterator �� end iterator �� ���(�ε��� -1)
			if (m_pArr->m_pData != m_pData || -1 == m_iIdx)
			{
				assert(nullptr); // ����ó��
			}

			return m_pData[m_iIdx];
		}

		iterator& operator ++()
			// ��ȯŸ���� iterator �ڱ� �ڽ��� ����:
			// ���� ++(++k) �̷� ��Ȳ�� ��� ��ȣ �ȿ��� ������ �Լ��� ȣ���� ����
			// �ڱ� �ڽ��� ��ȯ�� ��� ��ȣ �ۿ��� ������ �Լ��� ���޾� ����� �� �ֱ� �����̴�.
		{
			return *this; // �ڱ� �ڽ��� ������ �� ���� ���۷��� ���·� ��ȯ.
		}

		iterator& operator --()
		{
			return *this;
		}

	public:
		iterator()
			: m_pArr(nullptr)
			, m_pData(nullptr)
			, m_iIdx(-1)
		{

		}

		iterator(CArr* _pArr, T* _pData, int _iIdx)
			: m_pArr(_pArr)
			, m_pData(_pData)
			, m_iIdx(_iIdx)
		{

		}

		~iterator()
		{

		}
	};
};

template<typename T>
typename CArr<T>::iterator CArr<T>::begin()
{
	// ������ ����Ű�� iterator �� ���� ��ȯ����.
	if (0 == m_iCount) // �����Ͱ� �ƹ��͵� �� ���� ���� ���.
	{
		return iterator(this, m_pData, -1); // begin() == end()
		// ǥ�� vector ���� end() �� ���� ������ �ε����� �� �����̰� �� ������ �ƹ��͵� ����.
		// �ε��� -1�� end() �� ���� ����ϱ�� �ϰڴ�.
		// ���� �ε����� -1�� ��ȯ ���ֱ�� �Ѵ�.
	}
	else
	{
		return iterator(this, m_pData, 0); // begin �Լ��� ȣ���Ѱ� CArr�� ��ü�̹Ƿ�,
		// ù��° ���ڴ� �迭�� �ּ��� this �� �����Ѵ�.
	}
}

template<typename T>
typename CArr<T>::iterator CArr<T>::end()
{
	// ���� ������ ����Ű�� iterator �� ���� ��ȯ����.
	return iterator(this, m_pData, -1);
}

template<typename T>
CArr<T>::CArr()
	: m_pData(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	m_pData = new T[2]; // ġȯ �ڷ����� T Ÿ������ �����Ҵ�.
}

template<typename T>
CArr<T>::~CArr()
{
	delete[] m_pData; // ���� ���� int ������ ������ ������, [] ��ȣ�� �ٿ���� �Ѵ�.
	// �迭 ������ �޸𸮸� ���� �� [] ��ȣ�� ����.
}

template<typename T>
void CArr<T>::push_back(const T& _Data)
{
	// �� ������ �Ҵ��� ������ �� á�� ����� ����
	if (this->m_iMaxCount <= this->m_iCount)
	{
		// ���Ҵ�
		resize(this->m_iMaxCount * 2);
	}

	// ������ �߰�
	this->m_pData[this->m_iCount++] = _Data;
}

template<typename T>
void CArr<T>::resize(int _iResizeCount)
{
	// ���� �ִ� ���뷮 ���� �� ���ų� ���� ��ġ�� Ȯ���Ϸ��� ����� ����.
	if (m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr); // ���� ó��
	}

	// 1. �������� ��ų ������ŭ �����Ҵ� �Ѵ�.
	T* pNew = new T[_iResizeCount]; // T Ÿ������ ���Ҵ��ϰ�, T Ÿ�� �����ͷ� �ּҸ� �޴´�.

	// 2. ���� ������ �ִ� �����͵��� ���� �Ҵ��� �������� �����Ų��.
	for (int i = 0; i < m_iCount; ++i)
	{
		pNew[i] = m_pData[i];
	}

	// 3. ���� ������ �޸𸮴� �����Ѵ�.
	delete[] m_pData;

	// 4. ���� �Ҵ�� ������ ����Ű�� �Ѵ�.
	m_pData = pNew;

	// 5. iMaxCount �� ���� �����Ѵ�.
	m_iMaxCount = _iResizeCount;
}

template<typename T>
T& CArr<T>::operator[](int idx) // ���� �迭���� ������ �ε����� ���ڷ� �޴´�.
{
	return m_pData[idx]; // ��ȯ Ÿ��: ����Ű�� �ּҸ� ���ȭ�� T Ÿ�� ���� ����.
}
