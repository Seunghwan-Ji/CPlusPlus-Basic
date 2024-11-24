#pragma once

// 구조체 템플릿
template<typename T>
struct tListNode
{
	// C++ 구조체 기능은 클래스와 동일한 수준이 되었다.
	// 개인적인 구조체와 클래스 사용 목적 규칙을 정해놓자.
	// 기능이 많지 않고, 데이터를 묶어 저장 목적으로 사용할 때는 구조체 사용.
	// 좀거 복잡한 기능들은 클래스 사용.
	// 접근 제한 지정자를 적지 않으면 기본적으로 public 으로 간주한다.(클래스에서는 private)
	T		      data;
	// 다음 또는 이전 노드의 포인터 타입을 현재 포인터 타입으로 맞추기 위해 <T> 를 붙여준다.
	// 그런데 구조체 내에서 자기 자신의 구조체 이름을 지칭하면, 컴파일러는 <T> 를 붙이지 않아도
	// 자동으로 치환 자료형 형태의 포인터를 가리킨다.
	// 여기서는 의도를 명시적으로 표현하기 위해 <T> 를 붙인다.
	tListNode<T>* pPrev; // 이전 노드의 주소.
	tListNode<T>* pNext;

	tListNode() // 구조체는 클래스와 같으므로 생성자 함수 생성 가능.
		// 노드 초기화
		: data()
		, pPrev(nullptr)
		, pNext(nullptr)
	{

	}

	// 생성자도 함수 오버로딩 가능.
	tListNode(const T& _data, tListNode<T>* _pPrev, tListNode<T>* _pNext)
		// 받아온 인자로 초기화
		: data(_data)
		, pPrev(_pPrev)
		, pNext(_pNext)
	{

	}
};

// 클래스 템플릿
template<typename T> // 사용자가 집어넣은 자료형으로 노드 생성 시작.
class CList
{
private:
	tListNode<T>* m_pHead; // 받은 자료형 포인터로 헤드 노드를 가리킨다.
	tListNode<T>* m_pTail; // 꼬리 노드(마지막 노드의 주소)
	int m_icount;

public:
	void push_back(const T& _data);
	void push_front(const T& _data);
	// 인자로 받을 데이터의 타입은 얼마나 큰 크기의 자료형인지 모르므로,
	// 복사 비용을 줄이기 위해 참조 형태로 받고, 원본을 수정하지 않기 위해
	// 접근 값도 상수화해서 받는다.

public:
	CList();
	~CList();
};

template<typename T>
inline void CList<T>::push_back(const T& _data)
{
	// 입력된 데이터를 저장할 노드를 동적할당 한다.
	// 지역변수에 임시적으로 새 노드 생성.
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, nullptr); // 오버로딩 생성자 함수로 노드 초기화.

	// 처음 입력된 데이터라면
	if (nullptr == m_pHead)
	{
		m_pHead = pNewNode; // this->m_pHead
		m_pTail = pNewNode;
	}
	else
	{
		// 데이터가 1개 이상인 상태에서 들어온 경우
		// 현재 가장 마지막 데이터(Tail)를 저장하고 있는 노드와
		// 새로 생성된 노드가 서로 가리키게 한다.
		m_pTail->pNext = pNewNode;
		pNewNode->pPrev = m_pTail;

		// 꼬리 노드 갱신
		m_pTail = pNewNode;
	}

	// 데이터 개수 증가
	++m_icount;
}

template<typename T>
inline void CList<T>::push_front(const T& _data)
{
	// 새로 생성된 노드의 다음을 현재 헤드 노드의 주소값으로 채운다.
	tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, m_pHead);

	// 현재 헤드 노드의 이전 노드 주소값을 새로 생성된 노드의 주소로 채운다.
	m_pHead->pPrev = pNewNode;

	// 헤드 노드를 새로 생성한 노드로 갱신
	m_pHead = pNewNode;

	// 데이터 개수 증가
	++m_icount;
}

template<typename T>
CList<T>::CList() // 생성자 함수, 리스트 초기화.
	: m_pHead(nullptr) // 초기엔 가리키는 주소 없음.
	, m_pTail(nullptr)
	, m_icount(0)
{

}

template<typename T>
inline CList<T>::~CList() // 소멸자 함수.
{
	// 반복문을 통해 노드들을 정방향으로 지우기
	tListNode<T>* pDeleteNode = m_pHead; // 지역변수에 헤드 노드의 주소 저장.

	while (true)
	{
		if (nullptr == pDeleteNode)
		{
			break; // 다음 노드의 주소가 더 이상 없으면 중지.
		}

		tListNode<T>* pNext = pDeleteNode->pNext; // 지역변수에 다음 노드의 주소 임시 저장.
		delete(pDeleteNode); // 노드가 할당된 힙 메모리 해제.
		pDeleteNode = pNext; // 다음 반복에서 참조할 노드의 주소를
		// 임시 저장해둔 다음 노드의 주소로 변경.
	}
}
