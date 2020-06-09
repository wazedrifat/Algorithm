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

int res[2000][2000];

int main() {
	// IN OUT		//ThisIsForDebuggingPurposes
	
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int k = 1;
		for (int i = 0; i < n; i++) {
			for (int j = (i&1); j < n; j += 2) {
				// cout << i << " " << j << endl;
				res[i][j] = k;
				k += 2;
			}
		}

		k = 2;
		for (int i = 0; i < n; i++) {
			for (int j = !(i&1); j < n; j += 2) {
				res[i][j] = k;
				k += 2;
			}
		}
		// cout << "array : " << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << res[i][j] << " ";
			}
			cout << endl;
		}
		// cout << endl << endl << endl;		//ThisIsForDebuggingPurposes
	}
}