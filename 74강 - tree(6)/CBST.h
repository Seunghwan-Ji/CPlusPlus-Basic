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
	tBSTNode* pParent; // 부모노드
	tBSTNode* pLeftChild; // 자식노드
	tBSTNode* pRightChild;
};

template <typename T1, typename T2>
class CBST
{
private:
	tBSTNode<T1, T2>* m_pRoot; // 루트노드 주소
	int			      m_iCount; // 데이터 개수

public:
	bool insert(const tPair<T1, T2>& _pair); // 데이터 추가 함수

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

	// 처음 들어온 데이터일 경우
	if (nullptr == m_pRoot)
	{
		m_pRoot = pNewNode;
	}
	else
	{
		tBSTNode<T1, T2>* pNode = m_pRoot;

		// 루트노드 부터 키 값을 비교하며 지역변수 노드를 갱신해 나가는 것을 반복.
		while (true)
		{
			// 새로 생성한 노드의 키 값이 더 클 경우.
			if (pNode->pair.first < pNewNode->pair.first)
			{
				// 오른쪽 자식의 노드가 없다면
				if (nullptr == pNode->pRightChild)
				{
					// 부모 자식관계 형성.
					pNode->pRightChild = pNewNode;
					pNewNode->pParent = pNode;
					break;
				}
				else
				{
					// 현재 노드를 현재 노드의 오른쪽 자식으로 갱신.
					pNode = pNode->pRightChild;
				}
			}
			// 새로 생성한 노드의 키 값이 더 작을 경우.
			else if (pNode->pair.first > pNewNode->pair.first)
			{
				// 왼쪽 자식의 노드가 없다면
				if (nullptr == pNode->pLeftChild)
				{
					// 부모 자식관계 형성.
					pNode->pLeftChild = pNewNode;
					pNewNode->pParent = pNode;
					break;
				}
				else
				{
					// 현재 노드의 왼쪽 자식으로 갱신.
					pNode = pNode->pLeftChild;
				}
			}
			else
			{
				// 일반적인 map 은 중복 키 값을 허용하지 않으므로 데이터를 넣지 않는다.
				// 다만 multi map 에선 같은 키 값을 리스트 형태로 노드를 연결 짓는다.
				// 이진탐색트리의 탐색 효율을 위해서 일반적인 map 에서는 중복 키 값을 허용하지 않는다.
				return false;
			}
		}
	}

	// 데이터 개수 증가
	++m_iCount;

	return true;
}
