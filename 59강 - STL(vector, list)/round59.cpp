#include <iostream>

#include <vector> // ǥ�� ���̺귯���� �����ϴ� ���� �迭
#include <list> // ǥ�� ���̺귯���� �����ϴ� ������ ����Ʈ
// �Ѵ� Ŭ���� ���ø����� �����Ǿ���.

using std::vector;
using std::list;
using std::cout;
using std::endl;

int main()
{
	// ǥ�� ���� �迭 ���
	vector<int> vecInt;
	vecInt.push_back(10);
	vecInt.push_back(20);

	// ������ �����ε� �Լ��� �����Ǿ��ִ�.
	vecInt[0] = 100;

	vecInt.at(1); // �迭�� Ư�� �ε����� �����ؼ� �� ���� ���۷����� ��ȯ���ִ� �Լ��̴�.
	vecInt[1]; // ���� ǥ���̴�.
	// ��ó�� �Լ��ε� ������ �� �ְ�, ������ �����ε� �Լ��ε� ������ �� �ִ�.

	vecInt.data(); // ���� �迭�� ������ ���� �ּҸ� ��ȯ���ִ� �Լ��̴�.
	// Ŭ���� ���ø� �� �Լ��� ���� ����: T* data() {return m_pData;}

	vecInt.size(); // ���� ������ ������ ��ȯ���ִ� �Լ��̴�.
	// Ŭ���� ���ø� �� �Լ��� ���� ����: int size() {return m_iCount;}

	vecInt.capacity(); // �����͸� �� ĭ ���� ������� �� �ִ��� �˷��ִ� �Լ��̴�.
	// Ŭ���� ���ø� �� �Լ��� ���� ����: int capacity() {return m_iMaxCount;}

	// �迭 �� ��� ������ ��ȸ�ϱ�
	for (size_t i = 0; i < vecInt.size(); ++i)
		// size_t �� size �Լ��� ��ȯ Ÿ���̰�, Ÿ���� ������ ���̴�.
		// ���� size_t �� �ڷ����̸�, long long �ڷ����� Ÿ�� �������� �̸��̴�.
		// ���θ� Ȯ���غ��� typedef unsigned __int64 size_t; ��� ��õǾ� �ִ�.
		// __int64 �� long long �� ����.
	{
		// ������ ���
		cout << vecInt[i] << endl;
	}

	// ǥ�� ������ ����Ʈ ���
	list<int> listInt;
	listInt.push_back(10);
	listInt.push_front(20);

	listInt.size();
	// int size() {return m_iCount;

	// iterator(inner class)
	list<int>::iterator iter = listInt.begin();
	// list Ŭ���� �ȿ� iterator ��� Ŭ������ ���ԵǾ��ִ�.
	// iterator �� ��ü�� iter ��� ���������� ������ ���̴�.
	// begin �Լ��� ������ ����Ʈ listInt �� ���� �����͸� ����Ų��.

	// ���� ������ Ȯ���ϴ¹�
	int iData = *iter;
	// iter �� �����Ͱ� �ƴ϶� Ŭ������ ��ü�ε�,
	// ������ ������ ������ �ϵ��� ���� Ȯ���ϰ� �ִ�.
	// ��� ���⼭ * �� �����Ͱ� �ƴ϶� ������ �����ε� �Լ�(operator)�� ����Ǿ��ִ�.
	// ���� ��带 ����Ű�� �ִ� ���̾���, * �����ڸ� ������
	// ��� �� ����� ������ ��Ʈ, ������ ���� ��Ʈ �� �߿���
	// ������ ��Ʈ�� ��ȯ���ִ� �����̴�.
	// ���� ����ڷ� �Ͽ��� iterator Ŭ������ ����Ʈ�� �ش� �ڷᱸ���� �����͸�
	// ����Ű�� ��Ī�ϴ� ������ ���� �ݺ��� �����̴�.

	return 0;
}