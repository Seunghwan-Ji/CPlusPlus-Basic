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
	iterator erase(iterator& _iter);

public:
	CArr();
	~CArr();

	class iterator
	{
	private:
		CArr* m_pArr; // iterator �� ����ų �����͸� �����ϴ� ���� �迭 �ּ�
		// �� �޸𸮰� ���Ҵ�Ǹ� �迭�� ���� �ּҰ� �ٲ�Ƿ�,
		// CArr�� ��ü ��ü�� �ּҸ� �޴´�.
		T* m_pData; // �����͵��� ���� �ּ�
		int   m_iIdx; // ����Ű�� �������� �ε���
		bool m_bValid; // iterator ��ȿ�� üũ

	public:
		T& operator * ()
		{
			// iterator �� �˰��ִ� �ּҿ� ���� �迭�� �˰��ִ� �ּҰ� ���� �ٸ� ����� ����
			// (���� Ȯ������ ���� �ּҰ� �޶��� ���)
			// �Ǵ� iterator �� end iterator �� ���(�ε��� -1)
			// ��ȿ�� iterator ����.
			if (m_pArr->m_pData != m_pData || -1 == m_iIdx || false == m_bValid)
			{
				assert(nullptr); // ����ó��
			}

			return m_pData[m_iIdx];
		}

		// ++(����)
		iterator& operator ++()
		{
			if (m_pArr->m_pData != m_pData || -1 == m_iIdx)
			{
				assert(nullptr); // ����ó��
			}

			// iterator �� ������ �����͸� ����Ű�� �ִ� ���
			// --> end iterator �� �ȴ�.
			if (m_pArr->size() - 1 == m_iIdx)
			{
				m_iIdx = -1;
			}
			else
			{
				++m_iIdx;
			}

			return *this;
		}

		// ++(����)
		iterator operator ++(int)
		{
			iterator copy_iter = *this;

			++(*this);

			return copy_iter;
		}

		// ����, ���� -- �����ڸ� ���� �����غ���
		iterator& operator --()
		{
			return *this;
		}

		// �� ������ ==
		bool operator ==(const iterator& _otherIter)
		{
			// �� iterator ��ü�� ����Ű�� ���� �ּҰ� ����, �ε����� ���� ���.
			if (m_pData == _otherIter.m_pData && m_iIdx == _otherIter.m_iIdx)
			{
				return true;
			}

			return false;
		}

		// �� ������ !=
		bool operator !=(const iterator& _otherIter)
		{
			return !(*this == _otherIter);
		}

	public:
		iterator()
			: m_pArr(nullptr)
			, m_pData(nullptr)
			, m_iIdx(-1)
			, m_bValid(false)
		{

		}

		iterator(CArr* _pArr, T* _pData, int _iIdx)
			: m_pArr(_pArr)
			, m_pData(_pData)
			, m_iIdx(_iIdx)
			, m_bValid(false)
		{
			if (nullptr != _pArr && 0 <= _iIdx)
			{
				m_bValid = true;
			}
		}

		~iterator()
		{

		}

		friend class CArr; // friend: iterator Ŭ������ CArr Ŭ������ ģ���� �����ϰ� �Ǹ�,
		// CArr Ŭ������ iterator Ŭ������ private ������� ������ �� �ְ� �ȴ�.
	};
};

template<typename T>
typename CArr<T>::iterator CArr<T>::begin()
{
	// ������ ����Ű�� iterator �� ���� ��ȯ����.
	if (0 == m_iCount) // �����Ͱ� �ƹ��͵� �� ���� ���� ���.
	{
		return iterator(this, m_pData, -1); // begin() == end()
	}
	else
	{
		return iterator(this, m_pData, 0);
	}
}

template<typename T>
typename CArr<T>::iterator CArr<T>::end()
{
	// ���� ������ ����Ű�� iterator �� ���� ��ȯ����.
	return iterator(this, m_pData, -1);
}

template<typename T>
typename CArr<T>::iterator CArr<T>::erase(iterator& _iter)
{
	// iterator �� �ٸ� ���� �迭(CArr) �� ��Ҹ� ����Ű�� ���.
	// iterator �� end iterator �� ���.
	// ���� �迭�� ������ �������� iterator �� ����Ű�� �ε����� ũ�ų� ���� ���.
	if (this != _iter.m_pArr || end() == _iter || m_iCount <= _iter.m_iIdx)
	{
		assert(nullptr);
	}

	// iterator �� ����Ű�� �����͸� �迭 ������ �����Ѵ�.
	int iLoopCount = m_iCount - (_iter.m_iIdx + 1);
	// �����͸� ���� �� ���� �����͵��� ��ܿ��� Ƚ���� �ݺ� Ƚ���� �Ѵ�.
	// ��ܿ��� Ƚ�� = �����͸� ������ ��ġ�� �ε��� + 1

	for (int i = 0; i < iLoopCount; ++i)
	{
		m_pData[i + _iter.m_iIdx] = m_pData[i + _iter.m_iIdx + 1];
		// ���ŵ� ���� ��ġ(���� �����͸� �Űܹ޴� ��ġ)��
		// i �� 0 ���� �����ϹǷ� i �� �����ش�.
		// ���ŵ� ���� ���� ��ġ�� +1 �� ���ش�.
	}

	_iter.m_bValid = false; // �� iterator �� ����Ű�� �����Ͱ� �ٲ������,
	// ���� ����Ű�� �����Ͱ� ���� �Ǿ����Ƿ�
	// �Ѽյ� iterator �� �����ϱ�� �Ѵ�.

// ī��Ʈ ����
	--m_iCount;

	return iterator(this, m_pData, _iter.m_iIdx);
	// �Ѽյ� iterator ����Ű�� �� ������ ������ ��ȯ�ϰ�,
	// ���α׷��Ӵ� ȣ���� �ʿ��� �� iterator �� �� ������ ���� �Ѵ�.
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
