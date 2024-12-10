#pragma once

#include <assert.h>

enum class NODE_TYPE
{
	PARENT, // 0
	LCHILD, // 1
	RCHILD, // 2
	END,    // 3
};

template <typename T1, typename T2>
struct tPair
{
	T1 first;
	T2 second;
};

// make_pair ���ø� �Լ� ����.
template<typename T1, typename T2>
tPair<T1, T2> make_bstPair(const T1& _first, const T2& _second)
{
	return tPair<T1, T2>{_first, _second};
}

template <typename T1, typename T2>
struct tBSTNode
{
	tPair<T1, T2> pair; // data(pair)

	//tBSTNode*     pParent; // �θ���
	//tBSTNode*	  pLeftChild; // �ڽĳ��
	//tBSTNode*	  pRightChild;
	// ���� �ڷ����� 3�� �̹Ƿ�, �迭�� ���´�.
	tBSTNode* arrNode[(int)NODE_TYPE::END]; // 3ĭ�� �ʿ��ϹǷ�, 3�� END �� �־��ش�.

	// ��Ʈ ������� Ȯ�ν��� �ִ� �Լ�.
	bool IsRoot()
	{
		if (nullptr == this->arrNode[(int)NODE_TYPE::PARENT])
			return true;
		return false;
	}

	// ��尡 �θ��� ���� �ڽ����� Ȯ�ν��� �ִ� �Լ�.
	bool IsLeftChild()
	{
		if (this->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] == this)
			return true;
		return false;
	}

	// ��尡 �θ��� ������ �ڽ����� Ȯ�ν��� �ִ� �Լ�.
	bool IsRightChild()
	{
		if (this->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] == this)
			return true;
		return false;
	}

	// ������ �߰�
	tBSTNode()
		: pair()
		, arrNode{}
	{
	}

	tBSTNode(const tPair<T1, T2>& _pair, tBSTNode* _pParent, tBSTNode* _pLChild, tBSTNode* _pRChild)
		: pair(_pair)
		, arrNode{_pParent, _pLChild, _pRChild}
	{
	}
};

template <typename T1, typename T2>
class CBST
{
private:
	tBSTNode<T1, T2>* m_pRoot; // ��Ʈ��� �ּ�
	int			      m_iCount; // ������ ����

public:
	bool insert(const tPair<T1, T2>& _pair); // ������ �߰� �Լ�
	
	// ���ڷ� ���� ����� ���� �ļ��� ��带 �ִ� �Լ�.
	tBSTNode<T1, T2>* GetInOrderSuccessor(tBSTNode<T1, T2> _pNode);

	// ���ڷ� ���� ����� ���� ������ ��带 �ִ� �Լ�.
	tBSTNode<T1, T2>* GetInOrderPredecessor(tBSTNode<T1, T2> _pNode);

public:
	class iterator;
	iterator begin();
	iterator end();
	iterator find(const T1& _find); // T1: Ű ��

public:
	CBST()
		: m_pRoot(nullptr)
		, m_iCount(0)
	{
	}

	// iterator
	class iterator
	{
	private:
		CBST<T1, T2>*     m_pBST;
		tBSTNode<T1, T2>* m_pNode; // null �� ��� end iterator

	public:
		// ������ ���۷����� �Լ�
		bool operator ==(const iterator& _other)
		{
			if (m_pBST == _other.m_pBST && m_pNode == _other.m_pNode)
				return true;

			return false;
		}

		bool operator !=(const iterator& _other)
		{
			return !(*this == _other);
		}

		const tPair<T1, T2>& operator *()
		{
			// end iterator ���� �˻�.
			assert(m_pNode); // assert �Լ��� �Ű������� nullptr �̸� ����ó��.
			return m_pNode->pair;
		}

		const tPair<T1, T2>* operator ->()
		{
			assert(m_pNode);
			return &m_pNode->pair; // �� �Լ��� ��ȯ Ÿ���� ������ �ڷ����̹Ƿ�,
			                       // �ּҰ��� �ش�.

			// ������ �⺻ ���� ����
			/*
			tPair<int, int> pair;
			tPair<int, int>* pPair = &pair;
			pPair->first;
			pPair->second;
			*/
		}

		iterator& operator ++()
		{
			// m_pNode = m_pBST->GetInOrderSuccessor(m_pNode);
			return *this;
		}

	public:
		// ������
		iterator()
			: m_pBST(nullptr)
			, m_pNode(nullptr)
		{
		}

		iterator(CBST<T1, T2>* _pBST, tBSTNode<T1, T2>* _pNode)
			: m_pBST(_pBST)
			, m_pNode(_pNode)
		{
		}
	};
};

template<typename T1, typename T2>
inline bool CBST<T1, T2>::insert(const tPair<T1, T2>& _pair)
{
	tBSTNode<T1, T2>* pNewNode = new tBSTNode<T1, T2>(_pair, nullptr, nullptr, nullptr);
	/*pNewNode->pair = _pair;
	pNewNode->pParent = nullptr;
	pNewNode->pLeftChild = nullptr;
	pNewNode->pRightChild = nullptr;*/
	// tBSTNode �����ڸ� ������� ������ �� ������ �����.

	// ó�� ���� �������� ���
	if (nullptr == m_pRoot)
	{
		m_pRoot = pNewNode;
	}
	else
	{
		tBSTNode<T1, T2>* pNode = m_pRoot; // ���������� ��Ʈ��� ����.
		NODE_TYPE node_type = NODE_TYPE::END; // ������ enum Ÿ������ �����ϱ� ����.

		// ��Ʈ��� ���� Ű ���� ���ϸ� �������� ��带 ������ ������ ���� �ݺ�.
		while (true)
		{
			// ���� ������ ����� Ű ���� ũ�� ��.
			if (pNode->pair.first < pNewNode->pair.first)
				node_type = NODE_TYPE::RCHILD;
			else if (pNode->pair.first > pNewNode->pair.first)
				node_type = NODE_TYPE::LCHILD;
			else
				return false; // ���� ��� ������ �߰�X.

			// �θ����� ���� �Ǵ� ������ ���� ��尡 ����ִٸ�.
			if (nullptr == pNode->arrNode[(int)node_type])
			{
				// �θ� �ڽİ��� ����.
				pNode->arrNode[(int)node_type] = pNewNode;
				pNewNode->arrNode[(int)NODE_TYPE::PARENT] = pNode;
				break;
			}
			else
			{
				// �������� ��带 �����ϰ� ���� �������� �ڸ��� �̾ ã�´�.
				pNode = pNode->arrNode[(int)node_type];
			}
		}
	}

	// ������ ���� ����
	++m_iCount;

	return true;
}

template<typename T1, typename T2>
inline tBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderSuccessor(tBSTNode<T1, T2> _pNode)
{
	return nullptr;
}

template<typename T1, typename T2>
inline tBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderPredecessor(tBSTNode<T1, T2> _pNode)
{
	tBSTNode<T1, T2>* pSuccesor = nullptr; // �ʱ� ���� �ļ���.

	// 1. ������ �ڽ��� �ִ� ���, ������ �ڽ����� ����, ���� �ڽ��� ���� ������ ������.
	if (nullptr != _pNode->arrNode[(int)NODE_TYPE::RCHILD])
	{
		// ������ �ڽ����� �̵�.
		pSuccesor = _pNode->arrNode[(int)NODE_TYPE::RCHILD];

		while (pSuccesor->arrNode[(int)NODE_TYPE::LCHILD])
		{
			// ���� �ڽ��� ���� ������ ���� �ڽ����� �̵�.
			pSuccesor = pSuccesor->arrNode[(int)NODE_TYPE::LCHILD];
		}
	}

	// 2. �θ�� ���� ���� �ڽ��� ������ ���� �ö�, �׶� �θ� �ļ���.
	else
	{
		pSuccesor = _pNode;

		while (true)
		{
			// �θ� ���� ���.(�ڽ��� ��Ʈ ����� ���)
			if (pSuccesor->IsRoot())
				return nullptr;

			// �ڽ��� �θ��� ���� �ڽ��� ���.
			if (pSuccesor->IsLeftChild())
			{
				pSuccesor = pSuccesor->arrNode[(int)NODE_TYPE::PARENT]; // �θ� �ļ���.
				break;
			}
			else
			{
				pSuccesor = pSuccesor->arrNode[(int)NODE_TYPE::PARENT]; // �θ� ���� �̵�.
			}
		}
	}

	return pSuccesor;
}

// �Լ��� ����� �ۼ��� ��� �ڵ����� inline ó���Ǳ� ������
// inline Ű����� �����ص� �ȴ�.
template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::begin()
{
	tBSTNode<T1, T2>* pNode = m_pRoot;

	// ��Ʈ ������ ��� �������� �������鼭 ��� ����.
	while (pNode->arrNode[(int)NODE_TYPE::LCHILD])
	{
		pNode = pNode->arrNode[(int)NODE_TYPE::LCHILD];
	}

	return iterator(this, pNode); // ���� ���� �Ʒ��� ��带 ���� iterator ��ȯ
}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::end()
{
	// end iterator = null
	return iterator(this, nullptr);
}

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::find(const T1& _find)
{
	tBSTNode<T1, T2>* pNode = m_pRoot; // ���������� ��Ʈ��� ����.
	NODE_TYPE node_type = NODE_TYPE::END; // ������ enum Ÿ������ �����ϱ� ����.

	// ��Ʈ��� ���� Ű ���� ���ϸ� �������� ��带 ������ ������ ���� �ݺ�.
	while (true)
	{
		// ã�� Ű ���� ũ�� ��.
		if (pNode->pair.first < _find)
			node_type = NODE_TYPE::RCHILD;
		else if (pNode->pair.first > _find)
			node_type = NODE_TYPE::LCHILD;
		else
		{
			// ã�Ҵ�.
			// ���� ã������ ����̴�.
			break;
		}

		// �θ����� ���� �Ǵ� ������ ���� ��尡 ����ִٸ�.
		if (nullptr == pNode->arrNode[(int)node_type])
		{
			// �� ã�Ҵ�.
			pNode = nullptr; // end iterator �� ��ȯ ��Ű���� ��.
			break;
		}
		else
		{
			// �������� ��带 �����ϰ� ���� �������� �̾ ã�´�.
			pNode = pNode->arrNode[(int)node_type];
		}
	}

	return iterator(this, pNode);
}
