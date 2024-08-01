#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int GetMaxCommonElement(vector<int>& A, vector<int>& B)
{
	int Ret = -1;

	while (A.size() > 0 && B.size() > 0)
	{
		auto AMaxElementIt = max_element(A.begin(), A.end());
		auto BMaxElementIt = max_element(B.begin(), B.end());

		// �� �迭�� �ִ밡 ���ٸ� �׸�ŭ �迭�� ���̰� �ִ밪�� ����
		if (*AMaxElementIt == *BMaxElementIt)
		{
			Ret = *AMaxElementIt;
			A.erase(A.begin(), AMaxElementIt + 1);
			B.erase(B.begin(), BMaxElementIt + 1);

			break;
		}
		// B �迭�� �ִ밡 �� ũ�ٸ� B �迭���� �ִ� ���� ����
		else if (*AMaxElementIt < *BMaxElementIt)
		{
			B.erase(BMaxElementIt);
		}
		// A �迭�� �ִ밡 �� ũ�ٸ� A �迭���� �ִ� ���� ����
		else
		{
			A.erase(AMaxElementIt);
		}
	}
	return Ret;
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N;

	vector<int> ArrayA(N);
	for (int i = 0; i < N; ++i)
		cin >> ArrayA[i];

	cin >> M;
	vector<int> ArrayB(M);
	for (int i = 0; i < M; ++i)
		cin >> ArrayB[i];

	vector<int> AnsArray;
	while (ArrayA.size() > 0 && ArrayB.size() > 0)
	{
		int MaxCommonElement = GetMaxCommonElement(ArrayA, ArrayB);
		if(MaxCommonElement != -1) AnsArray.push_back(MaxCommonElement);
	}

	cout << AnsArray.size() << "\n";
	for (const int& Ans : AnsArray)
		cout << Ans << " ";
}