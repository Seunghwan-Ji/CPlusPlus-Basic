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
	vector<int> vecInt; // ���� �迭
	vecInt.push_back(10);
	vecInt.push_back(20);

	// vector �� iterator ��� inner(����) Ŭ������ �����Ѵ�.
	vector<int>::iterator veciter = vecInt.begin();
	*veciter = 100; // ���� ������

	// ���� ǥ��
	vecInt[0] = 100;

	++veciter; // ++ �����ڸ� ������ ���� �����͸� ����Ų��.

	list<int> listInt; // ������ ����Ʈ
	listInt.push_back(100);
	listInt.push_back(200);

	list<int>::iterator iter = listInt.begin();
	++iter; // ���� �����͸� ����Ų��.

	// ����Ʈ �� ��� ������ ��ȸ�ϱ�
	for (iter = listInt.begin(); iter != listInt.end(); ++iter)
		// listInt.end() �� ������ �������� ������ ����Ų��.
		// ���� ��ȸ���� iter �� ������ �����Ͱ� �Ǿ��� ��
		// listInt.end() �� �ƴϹǷ� ���ǿ� �����Ѵ�.
	{
		cout << *iter << endl;
	}

	return 0;
}