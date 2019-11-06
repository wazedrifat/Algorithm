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

bool next_combination(vector<int>& a, int n) {
    int k = (int)a.size();
    for (int i = k - 1; i >= 0; i--) {
        if (a[i] < n - k + i + 1) {
            a[i]++;
            for (int j = i + 1; j < k; j++)
                a[j] = a[j - 1] + 1;
            return true;
        }
    }
    return false;
}

//	next permutation such that 1 digit differ

int gray_code (int n) {
    return n ^ (n >> 1);
}

int count_bits (int n) {
    int res = 0;
    for (; n; n >>= 1)
        res += n & 1;
    return res;
}

void all_combinations (int n, int k) {
    for (int i = 0; i < (1 << n); i++) {
        int cur = gray_code (i);
        if (count_bits(cur) == k) {
            for (int j = 0; j < n; j++) {
                if (cur & (1 << j))
                    cout << j + 1;
            }
            cout << "\n";
        }
    }
}




vector<int> ans;

void gen(int n, int k, int idx, bool rev) {
    if (k > n || k < 0)
        return;

    if (!n) {
        for (int i = 0; i < idx; ++i) {
            if (ans[i])
                cout << i + 1;
        }
        cout << "\n";
        return;
    }

    ans[idx] = rev;
    gen(n - 1, k - rev, idx + 1, false);
    ans[idx] = !rev;
    gen(n - 1, k - !rev, idx + 1, true);
}

void all_combinations(int n, int k) {
    ans.resize(n);
    gen(n, k, 0, false);
}

int main() 
{
	
}