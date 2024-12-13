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

	// 단말 노드인지 확인시켜 주는 함수.
	bool IsLeaf()
	{
		// 왼쪽 자식, 오른쪽 자식이 모두 없는지 체크.
		if (nullptr == arrNode[(int)NODE_TYPE::LCHILD] && nullptr == arrNode[(int)NODE_TYPE::RCHILD])
			return true;
		return false;
	}

	bool IsFull()
	{
		// 왼쪽 자식, 오른쪽 자식 모두 보유하고 있는지 체크.
		if (arrNode[(int)NODE_TYPE::LCHILD] && arrNode[(int)NODE_TYPE::RCHILD])
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
		, arrNode{ _pParent, _pLChild, _pRChild }
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
	tBSTNode<T1, T2>* GetInOrderSuccessor(tBSTNode<T1, T2>* _pNode);

	// 인자로 받은 노드의 중위 선행자 노드를 주는 함수.
	tBSTNode<T1, T2>* GetInOrderPredecessor(tBSTNode<T1, T2>* _pNode);

public:
	class iterator;
	iterator begin();
	iterator end();
	iterator find(const T1& _find); // T1: 키 값
	iterator erase(const iterator& _iter);

private:
	tBSTNode<T1, T2>* DeleteNode(tBSTNode<T1, T2>* _pTargetNode);

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
		CBST<T1, T2>* m_pBST;
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
			m_pNode = m_pBST->GetInOrderSuccessor(m_pNode);
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

		friend class CBST<T1, T2>;
	};
};

template<typename T1, typename T2>
inline bool CBST<T1, T2>::insert(const tPair<T1, T2>& _pair)
{
	tBSTNode<T1, T2>* pNewNode = new tBSTNode<T1, T2>(_pair, nullptr, nullptr, nullptr);

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
inline tBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderSuccessor(tBSTNode<T1, T2>* _pNode)
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

template<typename T1, typename T2>
inline tBSTNode<T1, T2>* CBST<T1, T2>::GetInOrderPredecessor(tBSTNode<T1, T2>* _pNode)
{
	return nullptr;
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

template<typename T1, typename T2>
inline typename CBST<T1, T2>::iterator CBST<T1, T2>::erase(const iterator& _iter)
{
	// 같은 이진탐색트리 객체인지 검사.
	assert(this == _iter.m_pBST);

	tBSTNode<T1, T2>* pSuccessor = DeleteNode(_iter.m_pNode);
	// DeleteNode: 노드를 삭제하는 것에 집중하는 함수.
	// erase: iterator 가 가리키는 노드를 제거해서,
	//        그 다음을 가리키는 iterator 를 만들어서 반환하는 함수.

	return iterator(this, pSuccessor);
}

template<typename T1, typename T2>
inline tBSTNode<T1, T2>* CBST<T1, T2>::DeleteNode(tBSTNode<T1, T2>* _pTargetNode)
{
	// 삭제시킬 노드의 중위 후속자 노드를 찾아둔다.
	tBSTNode<T1, T2>* pSuccessor = GetInOrderSuccessor(_pTargetNode);

	// 1. 자식이 하나도 없는 경우.
	if (_pTargetNode->IsLeaf())
	{
		// 삭제할 노드가 루트 노드 였다면(자식이 없고, BST 안에 데이터가 1개)
		if (_pTargetNode == m_pRoot)
		{
			m_pRoot = nullptr;
		}
		else
		{
			// 부모 노드로 접근, 삭제될 노드인 자식을 가리키는 포인터를 nullptr 로 만든다.
			if (_pTargetNode->IsLeftChild())
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] = nullptr;
			else
			{
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] = nullptr;
			}
		}

		// 노드 삭제.
		delete _pTargetNode;

		// 데이터 개수 차감.
		--m_iCount;
	}

	// 2. 자식이 2개인 경우.
	else if (_pTargetNode->IsFull())
	{
		// 삭제될 자리에 중위 후속자의 값을 복사시킨다.
		_pTargetNode->pair = pSuccessor->pair;

		// 중위 후속자 노드를 삭제한다.
		DeleteNode(pSuccessor);

		// 최종적인 중위 후속자 = 값을 복사 받은 _pTargetNode.
		pSuccessor = _pTargetNode;
	}

	// 3. 자식이 1개인 경우.
	else
	{
		NODE_TYPE eChildType = NODE_TYPE::LCHILD; // arrNode 의 초기 인덱스.

		// 보유한 자식이 오른쪽 자식이면.
		if (_pTargetNode->arrNode[(int)NODE_TYPE::RCHILD])
			eChildType = NODE_TYPE::RCHILD;

		// 삭제할 노드가 루트 노드였다면.
		if (_pTargetNode == m_pRoot)
		{
			// 자식 노드 1개를 루트로 만든다.
			m_pRoot = _pTargetNode->arrNode[(int)eChildType];

			// 루트 노드가 된 자식의 부모는 null.
			_pTargetNode->arrNode[(int)eChildType]->arrNode[(int)NODE_TYPE::PARENT] = nullptr;
		}
		else
		{
			// 삭제될 노드의 부모와, 삭제될 노드의 자식을 연결해준다.
			// 자신이 부모의 어느쪽 자식인지 확인.
			// 자신의 부모의 자식을 자신의 자식으로 갱신.
			if (_pTargetNode->IsLeftChild())
			{
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] = _pTargetNode->arrNode[(int)eChildType];
			}
			else
			{
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] = _pTargetNode->arrNode[(int)eChildType];
			}

			// 자신의 부모를 자기 자식의 부모로 갱신.
			_pTargetNode->arrNode[(int)eChildType]->arrNode[(int)NODE_TYPE::PARENT] = _pTargetNode->arrNode[(int)NODE_TYPE::PARENT];
		}

		delete _pTargetNode;

		// 데이터 개수 차감.
		--m_iCount;
	}

	return pSuccessor;
}
