#pragma once

template <typename T1, typename T2>
struct tPair
{
	T1 first;
	T2 second;
};

template <typename T1, typename T2>
struct tBSTNode
{
	tPair<T1, T2> pair; // data(pair)
	tBSTNode* pParent; // �θ���
	tBSTNode* pLeftChild; // �ڽĳ��
	tBSTNode* pRightChild;
};

template <typename T1, typename T2>
class CBST
{
private:
	tBSTNode<T1, T2>* m_pRoot; // ��Ʈ��� �ּ�
	int			      m_iCount; // ������ ����

public:
	bool insert(const tPair<T1, T2>& _pair); // ������ �߰� �Լ�

public:
	CBST()
		: m_pRoot(nullptr)
		, m_iCount(0)
	{
	}
};

template<typename T1, typename T2>
inline bool CBST<T1, T2>::insert(const tPair<T1, T2>& _pair)
{
	tBSTNode<T1, T2>* pNewNode = new tBSTNode<T1, T2>();
	pNewNode->pair = _pair;
	pNewNode->pParent = nullptr;
	pNewNode->pLeftChild = nullptr;
	pNewNode->pRightChild = nullptr;

	// ó�� ���� �������� ���
	if (nullptr == m_pRoot)
	{
		m_pRoot = pNewNode;
	}
	else
	{
		tBSTNode<T1, T2>* pNode = m_pRoot;

		// ��Ʈ��� ���� Ű ���� ���ϸ� �������� ��带 ������ ������ ���� �ݺ�.
		while (true)
		{
			// ���� ������ ����� Ű ���� �� Ŭ ���.
			if (pNode->pair.first < pNewNode->pair.first)
			{
				// ������ �ڽ��� ��尡 ���ٸ�
				if (nullptr == pNode->pRightChild)
				{
					// �θ� �ڽİ��� ����.
					pNode->pRightChild = pNewNode;
					pNewNode->pParent = pNode;
					break;
				}
				else
				{
					// ���� ��带 ���� ����� ������ �ڽ����� ����.
					pNode = pNode->pRightChild;
				}
			}
			// ���� ������ ����� Ű ���� �� ���� ���.
			else if (pNode->pair.first > pNewNode->pair.first)
			{
				// ���� �ڽ��� ��尡 ���ٸ�
				if (nullptr == pNode->pLeftChild)
				{
					// �θ� �ڽİ��� ����.
					pNode->pLeftChild = pNewNode;
					pNewNode->pParent = pNode;
					break;
				}
				else
				{
					// ���� ����� ���� �ڽ����� ����.
					pNode = pNode->pLeftChild;
				}
			}
			else
			{
				// �Ϲ����� map �� �ߺ� Ű ���� ������� �����Ƿ� �����͸� ���� �ʴ´�.
				// �ٸ� multi map ���� ���� Ű ���� ����Ʈ ���·� ��带 ���� ���´�.
				// ����Ž��Ʈ���� Ž�� ȿ���� ���ؼ� �Ϲ����� map ������ �ߺ� Ű ���� ������� �ʴ´�.
				return false;
			}
		}
	}

	// ������ ���� ����
	++m_iCount;

	return true;
}
