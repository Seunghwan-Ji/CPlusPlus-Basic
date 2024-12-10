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

// make_pair 템플릿 함수 구현.
template<typename T1, typename T2>
tPair<T1, T2> make_bstPair(const T1& _first, const T2& _second)
{
	return tPair<T1, T2>{_first, _second};
}

template <typename T1, typename T2>
struct tBSTNode
{
	tPair<T1, T2> pair; // data(pair)

	//tBSTNode*     pParent; // 부모노드
	//tBSTNode*	  pLeftChild; // 자식노드
	//tBSTNode*	  pRightChild;
	// 같은 자료형이 3개 이므로, 배열로 묶는다.
	tBSTNode* arrNode[(int)NODE_TYPE::END]; // 3칸이 필요하므로, 3인 END 를 넣어준다.

	// 루트 노드인지 확인시켜 주는 함수.
	bool IsRoot()
	{
		if (nullptr == this->arrNode[(int)NODE_TYPE::PARENT])
			return true;
		return false;
	}

	// 노드가 부모의 왼쪽 자식인지 확인시켜 주는 함수.
	bool IsLeftChild()
	{
		if (this->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] == this)
			return true;
		return false;
	}

	// 노드가 부모의 오른쪽 자식인지 확인시켜 주는 함수.
	bool IsRightChild()
	{
		if (this->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] == this)
			return true;
		return false;
	}

	// 생성자 추가
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
	tBSTNode<T1, T2>* m_pRoot; // 루트노드 주소
	int			      m_iCount; // 데이터 개수

public:
	bool insert(const tPair<T1, T2>& _pair); // 데이터 추가 함수
	
	// 인자로 받은 노드의 중위 후속자 노드를 주는 함수.
	tBSTNode<T1, T2>* GetInOrderSuccessor(tBSTNode<T1, T2> _pNode);

	// 인자로 받은 노드의 중위 선행자 노드를 주는 함수.
	tBSTNode<T1, T2>* GetInOrderPredecessor(tBSTNode<T1, T2> _pNode);

public:
	class iterator;
	iterator begin();
	iterator end();
	iterator find(const T1& _find); // T1: 키 값

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
		tBSTNode<T1, T2>* m_pNode; // null 인 경우 end iterator

	public:
		// 연산자 오퍼레이터 함수
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
			// end iterator 인지 검사.
			assert(m_pNode); // assert 함수의 매개변수가 nullptr 이면 예외처리.
			return m_pNode->pair;
		}

		const tPair<T1, T2>* operator ->()
		{
			assert(m_pNode);
			return &m_pNode->pair; // 이 함수의 반환 타입이 포인터 자료형이므로,
			                       // 주소값을 준다.

			// 포인터 기본 문법 복습
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
		// 생성자
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
	// tBSTNode 생성자를 만들었기 때문에 이 구문은 지운다.

	// 처음 들어온 데이터일 경우
	if (nullptr == m_pRoot)
	{
		m_pRoot = pNewNode;
	}
	else
	{
		tBSTNode<T1, T2>* pNode = m_pRoot; // 지역변수에 루트노드 복사.
		NODE_TYPE node_type = NODE_TYPE::END; // 방향을 enum 타입으로 설정하기 위함.

		// 루트노드 부터 키 값을 비교하며 지역변수 노드를 갱신해 나가는 것을 반복.
		while (true)
		{
			// 새로 생성한 노드의 키 값과 크기 비교.
			if (pNode->pair.first < pNewNode->pair.first)
				node_type = NODE_TYPE::RCHILD;
			else if (pNode->pair.first > pNewNode->pair.first)
				node_type = NODE_TYPE::LCHILD;
			else
				return false; // 같을 경우 데이터 추가X.

			// 부모노드의 왼쪽 또는 오른쪽 방향 노드가 비어있다면.
			if (nullptr == pNode->arrNode[(int)node_type])
			{
				// 부모 자식관계 형성.
				pNode->arrNode[(int)node_type] = pNewNode;
				pNewNode->arrNode[(int)NODE_TYPE::PARENT] = pNode;
				break;
			}
			else
			{
				// 지역변수 노드를 갱신하고 다음 루프에서 자리를 이어서 찾는다.
				pNode = pNode->arrNode[(int)node_type];
			}
		}
	}

	// 데이터 개수 증가
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
	tBSTNode<T1, T2>* pSuccesor = nullptr; // 초기 중위 후속자.

	// 1. 오른쪽 자식이 있는 경우, 오른쪽 자식으로 가서, 왼쪽 자식이 없을 때까지 내려감.
	if (nullptr != _pNode->arrNode[(int)NODE_TYPE::RCHILD])
	{
		// 오른쪽 자식으로 이동.
		pSuccesor = _pNode->arrNode[(int)NODE_TYPE::RCHILD];

		while (pSuccesor->arrNode[(int)NODE_TYPE::LCHILD])
		{
			// 왼쪽 자식이 없을 때까지 왼쪽 자식으로 이동.
			pSuccesor = pSuccesor->arrNode[(int)NODE_TYPE::LCHILD];
		}
	}

	// 2. 부모로 부터 왼쪽 자식일 때까지 위로 올라감, 그때 부모가 후속자.
	else
	{
		pSuccesor = _pNode;

		while (true)
		{
			// 부모가 없을 경우.(자신이 루트 노드일 경우)
			if (pSuccesor->IsRoot())
				return nullptr;

			// 자신이 부모의 왼쪽 자식일 경우.
			if (pSuccesor->IsLeftChild())
			{
				pSuccesor = pSuccesor->arrNode[(int)NODE_TYPE::PARENT]; // 부모가 후속자.
				break;
			}
			else
			{
				pSuccesor = pSuccesor->arrNode[(int)NODE_TYPE::PARENT]; // 부모 노드로 이동.
			}
		}
	}

	return pSuccesor;
}

// 함수를 헤더에 작성할 경우 자동으로 inline 처리되기 때문에
// inline 키워드는 생략해도 된다.
template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::begin()
{
	tBSTNode<T1, T2>* pNode = m_pRoot;

	// 루트 노드부터 계속 왼쪽으로 내려가면서 노드 갱신.
	while (pNode->arrNode[(int)NODE_TYPE::LCHILD])
	{
		pNode = pNode->arrNode[(int)NODE_TYPE::LCHILD];
	}

	return iterator(this, pNode); // 가장 왼쪽 아래의 노드를 가진 iterator 반환
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
	tBSTNode<T1, T2>* pNode = m_pRoot; // 지역변수에 루트노드 복사.
	NODE_TYPE node_type = NODE_TYPE::END; // 방향을 enum 타입으로 설정하기 위함.

	// 루트노드 부터 키 값을 비교하며 지역변수 노드를 갱신해 나가는 것을 반복.
	while (true)
	{
		// 찾을 키 값과 크기 비교.
		if (pNode->pair.first < _find)
			node_type = NODE_TYPE::RCHILD;
		else if (pNode->pair.first > _find)
			node_type = NODE_TYPE::LCHILD;
		else
		{
			// 찾았다.
			// 현재 찾으려는 노드이다.
			break;
		}

		// 부모노드의 왼쪽 또는 오른쪽 방향 노드가 비어있다면.
		if (nullptr == pNode->arrNode[(int)node_type])
		{
			// 못 찾았다.
			pNode = nullptr; // end iterator 를 반환 시키도록 함.
			break;
		}
		else
		{
			// 지역변수 노드를 갱신하고 다음 루프에서 이어서 찾는다.
			pNode = pNode->arrNode[(int)node_type];
		}
	}

	return iterator(this, pNode);
}
