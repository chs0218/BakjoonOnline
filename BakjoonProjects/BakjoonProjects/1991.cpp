#include <iostream>
#include <vector>
using namespace std;
struct Node {
	char chRoot = '.';
	char chLeft = '.';
	char chRight = '.';
};
vector<Node> vNode(26);
int N;
void Foward(int n)
{
	cout << vNode[n].chRoot;
	if(vNode[n].chLeft != '.') Foward(vNode[n].chLeft - 'A');
	if(vNode[n].chRight != '.') Foward(vNode[n].chRight - 'A');
}
void Midward(int n)
{
	if (vNode[n].chLeft != '.') Midward(vNode[n].chLeft - 'A');
	cout << vNode[n].chRoot;
	if (vNode[n].chRight != '.') Midward(vNode[n].chRight - 'A');
}
void Backward(int n)
{
	if (vNode[n].chLeft != '.') Backward(vNode[n].chLeft - 'A');
	if (vNode[n].chRight != '.') Backward(vNode[n].chRight - 'A');
	cout << vNode[n].chRoot;
}
int main()
{
	cin >> N;
	
	for (int i = 0; i < N; ++i)
	{
		char root;
		cin >> root;

		vNode[root - 'A'].chRoot = root;
		cin >> vNode[root - 'A'].chLeft >> vNode[root - 'A'].chRight;
	}

	Foward(0);
	cout << "\n";
	Midward(0);
	cout << "\n";
	Backward(0);
}