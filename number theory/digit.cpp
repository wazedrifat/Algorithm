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

//	returns (n^p) % mod
int bigMod(int n, int p, int mod ) {
	int res = 1%mod, x = n%mod;

	while (p) {
		if (p&1)
			res = (res * x) % mod;
		
		x = (x * x) % mod;
		p >>= 1;
	}
	return res;
}

//	Euler Phi Function : count of numbers <= N 
//	that are coPrime with N
//	Number of elements e, such that gcd(e,n)=d is equal to ϕ(nd).
//	∑of (d/n)  [ ] = n.
int eulerPhi(int n) {
	int res = n, sqrtn = sqrt(n);

	for (int i = 0; i < prime.size() && prime[i] <= sqrtn; i++) {
		if (n % prime[i] == 0) {
			while (n % prime[i] == 0)
				n /= prime[i];

			sqrtn = sqrt(n);
			res /= prime[i];
			res *= prime[i] - 1;
		}
	}

	if (n != 1) {
		res /= n;
		res *= n - 1;
	}
	return res;
}

//	x = (1/a) % mod
int modInv(int a, int mod) {	//	mod is prime
	return bigMod(a, mod - 2, mod);
}

int modInv2(int a, int mod) {	//	mod is not prime
	int x, y;
	ext_GCD(a, mod, x, y);

	x %= mod;
	if (x < 0)	
		x += mod;
	return x;
}

//	modular inverse of n
//	complexity = O(n)
int modInvArray[MX];
void allModInv(int n, int mod) {
	modInvArray[1] = 1;
	for (int i = 1; i <= n; i++) {
		modInvArray[i] = (-(mod / i) * modInvArray[mod % i]) % mod;
		modInvArray[i] += mod;
	}	
}

int main() 
{
	
}