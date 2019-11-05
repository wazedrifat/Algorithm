#include <bits/stdc++.h>
using namespace std;

#define IN freopen("in.txt", "r", stdin);
#define OUT freopen("out.txt", "w", stdout);
#define ll long long int
#define PII pair <int, int>
#define MX 100001
#define EPS 1e-9
#define PI 2.0 * acos(0.0)

vector <int> prime;

int numberOfDigit(int n, int base = 10) {
	int res = floor(log(n) / log(base));
	return (res + 1 + EPS);
}

int numberofDigitFactorial(int n, int base) {
	double x = 0.0;
	for (int i = 1; i <= n; i++)
		x += log(i) / log(base);
	
	return (x + 1 + EPS);
}


// how many time p occurs in n!(p is prime)
ll factorialPrimePower(ll n, ll p) {
	ll freq = 0, x = n;

	while (x) {
		freq += x / p;
		x /= p;
	}
	return freq;
}

//	first k leading digit of n!
int leadingDigitofFactorial(int n, int k) {
	double fact = 0;
	
	for (int i = 1; i <= n; i++)	//	log(n!)
		fact += log10(i);

	double q = fact - floor(fact + EPS);
	double b = pow(10, q);

	for (int i = 0; i < k - 1; i++)
		b *= 10;
	
	return floor(b + EPS);
}

void factorialFactorize(int n) {
	for (int i = 0; i < prime.size() && prime[i] <= n; i++) {
		int x = n, freq = 0;

		while (x / prime[i]) {
			freq += x / prime[i];
			x /= prime[i];
		}

		cout << prime[i] << " " << 	freq << endl;
	}
}

int main() 
{
	
}