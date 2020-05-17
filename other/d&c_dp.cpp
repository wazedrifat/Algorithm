#include <bits/stdc++.h>
using namespace std;

#define IN freopen("in.txt", "r", stdin);
#define OUT freopen("out.txt", "w", stdout);
#define LL long long int
#define MX 500001
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define max4(a, b, c, d) max(a, max3(b, c, d))
#define min4(a, b, c, d) min(a, min3(b, c, d))
#define EPS 1e-9
#define MOD 1000000007
#define PI 2.0 * acos(0.0)
#define PII pair <int, int>
#define VI vector <int>
#define VVI vector <VI>

//	Given a sequence of N pairs of integers, find the length of the longest increasing subsequence of it.
//	A pair of integers (x1, y1) is less than (x2, y2) iff x1 < x2 and y1 < y2.

vector <PII> v;
int dp[MX];

int main() {
	IN OUT		//ThisIsForDebuggingPurposes
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({x, y});
	}

	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		if (i)	dp[i] = dp[i - 1];
		for (int j = 0; j < i; j++) {
			if (v[i].first > v[j].first && v[i].second > v[j].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	cout << dp[n - 1] << endl;
}