#include <bits/stdc++.h>
using namespace std;

#define IN freopen("in.txt", "r", stdin);
#define OUT freopen("out.txt", "w", stdout);
#define LL long long int
#define ULL unsinged LL
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
#define PLL pair <LL, LL>

struct ConvexHullTrick {
	vector <LL> m, c;

	bool badDecreasing(int sz) {
		int f3 = sz - 1, f2 = sz - 2, f1 = sz - 3;
		return (1.0 * (c[f3] - c[f1]) * (m[f1] - m[f2]) <= 1.0 * (c[f2] - c[f1]) * (m[f1] - m[f3]));
	}

	bool badIncreasing(int sz) {
		int f3 = sz - 1, f2 = sz - 2, f1 = sz - 3;
		return (1.0 * (c[f3] - c[f1]) * (m[f1] - m[f2]) >= 1.0 * (c[f2] - c[f1]) * (m[f1] - m[f3]));
	}

	LL fn(int i, LL x) {
		if (i >= m.size())	return 0;
		return (m[i] * x + c[i]);
	}

	void addDecreasing(LL _m, LL _c) {
		m.push_back(_m);	c.push_back(_c);

		while (m.size() >= 3 && badDecreasing(m.size())) {
			m.erase(m.end() - 2);	c.erase(c.end() - 2);
		}
	}

	void addIncreasing(LL _m, LL _c) {
		m.push_back(_m);	c.push_back(_c);

		while (m.size() >= 3 && badIncreasing(m.size())) {
			m.erase(m.end() - 2);	c.erase(c.end() - 2);
		}
	}

	LL queryMin(LL x) {
		int l = 0, h = m.size() - 1;
		LL ret = LONG_LONG_MAX;

		while (l <= h) {
			int m1 = l + (h - l)/3;
			int m2 = h - (h - l)/3;

			LL y1 = fn(m1, x), y2 = fn(m2, x);	

			if (y1 <= y2) {
				ret = min(ret, y1);
				h = m2 - 1;
			}
			else {
				ret = min(ret, y2);
				l = m1 + 1;
			}
		}
		return ret;
	}
};

/*
values of a : 
1. mi > mi+1, and all queries are for minimum.
2. mi > mi+1, and all queries are for maximum.
3. mi < mi+1, and all queries are for minimum.
4. mi < mi+1, and all queries are for maximum.

Furthermore, all quereis of second kind will obey this - xi < xi+1.
*/

int main() {
	// IN OUT		//ThisIsForDebuggingPurposes
	
	int q, a;
	cin >> q >> a;

	ConvexHullTrick ds;

	while (q--) {
		int t;
		cin >> t;

		if (t == 1) {
			LL m, c;
			cin >> m >> c;

			if (!(a&1)) {
				m = -m;	c = -c;
			}

			if (a == 1 || a == 4) {
				ds.addDecreasing(m, c);
			}
			else {
				ds.addIncreasing(m, c);
			}
		}
		else {
			LL x;
			cin >> x;
			
			if (a&1) {
				cout << ds.queryMin(x) << endl;
			}
			else {
				cout << -ds.queryMin(x) << endl;
			}
		}
	}
}