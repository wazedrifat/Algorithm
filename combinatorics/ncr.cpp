#include <bits/stdc++.h>
using namespace std;

#define IN freopen("in.txt", "r", stdin);
#define OUT freopen("out.txt", "w", stdout);
#define ll long long int
#define PII pair <int, int>
#define MX 100001
#define EPS 1e-9
#define PI 2.0 * acos(0.0)

int ncr[1000][1000];
ll fac[MX];

int calcNCR() {
	for (int i = 1; i <= 1000; i++) {
		ncr[i][i] = ncr[i][0] = 1;
		for (int j = 1; j < i; j++)
			ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
	}
}

void factorial() {
	fac[1] = 1;

	for (int i = 2; i < MX; i++)
		fac[i] = (fac[i-1] * i) % MOD; 
}

ll getNCR(int n, int r, int MOD) {
	ll res = fac[n];
	res = (res * modInv(fac[n-r], MOD)) % MOD;
	res = (res * modInv(fac[r], MOD)) % MOD;
	return res;
}



int main() 
{
	
}