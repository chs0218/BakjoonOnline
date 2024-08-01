#include <iostream>
using namespace std;

int N, S, M, L, XL, XXL, XXXL, T, P;
int AnsShirtBundle = 0, AnsPencilBundle = 0, AnsPencilIndividual = 0;

void CountAnsShirtBundle()
{
	AnsShirtBundle += S / T;
	(S % T == 0) ? AnsShirtBundle : AnsShirtBundle += 1;

	AnsShirtBundle += M / T;
	(M % T == 0) ? AnsShirtBundle : AnsShirtBundle += 1;

	AnsShirtBundle += L / T;
	(L % T == 0) ? AnsShirtBundle : AnsShirtBundle += 1;

	AnsShirtBundle += XL / T;
	(XL % T == 0) ? AnsShirtBundle : AnsShirtBundle += 1;

	AnsShirtBundle += XXL / T;
	(XXL % T == 0) ? AnsShirtBundle : AnsShirtBundle += 1;

	AnsShirtBundle += XXXL / T;
	(XXXL % T == 0) ? AnsShirtBundle : AnsShirtBundle += 1;
}

void CountAnsPencil()
{
	AnsPencilBundle += N / P;
	AnsPencilIndividual = N % P;
}

int main()
{
	cin >> N >> S >> M >> L >> XL >> XXL >> XXXL >> T >> P;
	
	CountAnsShirtBundle();
	CountAnsPencil();

	cout << AnsShirtBundle << "\n";
	cout << AnsPencilBundle << " " << AnsPencilIndividual;
}