#include <bits/stdc++.h>
using namespace std;

#define IN freopen("in.txt", "r", stdin);
#define OUT freopen("out.txt", "w", stdout);
#define ll long long int
#define PII pair <int, int>
#define MX 1000010
#define EPS 1e-9
#define PI 2.0 * acos(0.0)

//	lcm(1, n) + lcm(2, n) + .....lcm(n, n)

ll res[MX], phi[MX];

void preCalc(int n) {
	for (int i = 1; i <= n; i++)
		phi[i] = i;
	
	for (int i = 2; i <= n; i++) {
		if (phi[i] == i) {
			for (int j = i; j <= n; j += i) {
				phi[j] /= i;
				phi[h] *= i - 1;
			}
		}
	}

	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j += i)
			res[j] += (i * phi[i]);
}

int main() 
{
	preCalc(1000000);

	int n;
	scanf("%d", &n);

	ll ans = res[n] + 1;
	ans *= n;
	ans /= 2;

	cout << ans << endl;
}