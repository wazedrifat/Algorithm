#include <bits/stdc++.h>
using namespace std;

#define IN freopen("in.txt", "r", stdin);
#define OUT freopen("out.txt", "w", stdout);
#define ll long long int
#define PII pair <int, int>
#define MX 100001
#define EPS 1e-9
#define MOD 1000000007
#define PI 2.0 * acos(0.0)

int main() 
{
	const double EPS = 1E-9;
	int n;
	vector < vector<double> > a (n, vector<double> (n));

	double det = 1;
	for (int i=0; i<n; ++i) {
		int k = i;
		for (int j=i+1; j<n; ++j)
			if (abs (a[j][i]) > abs (a[k][i]))
				k = j;
		if (abs (a[k][i]) < EPS) {
			det = 0;
			break;
		}
		swap (a[i], a[k]);
		if (i != k)
			det = -det;
		det *= a[i][i];
		for (int j=i+1; j<n; ++j)
			a[i][j] /= a[i][i];
		for (int j=0; j<n; ++j)
			if (j != i && abs (a[j][i]) > EPS)
				for (int k=i+1; k<n; ++k)
					a[j][k] -= a[i][k] * a[j][i];
	}

	cout << det;
}