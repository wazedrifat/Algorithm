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

int gcd(int a, int b) {
	while (b) {
		a = a % b;
		swap(a, b);
	}
	return a;
}

int lcm(int a, int b) {
	return ((a / gcd(a, b)) * b);
}

//	aX + bY = gcd(a, b)
//	(x, y) = (x + (kb) / gcd(a, b)   ,   y - (ka) / gcd(a, b))
int ext_GCD(int a, int b, int &X, int &Y) {
	int x, y, x1, y1, x2, y2, r, r1, r2, q;
	x1 = 0;		y1 = 1;
	x2 = 1;		y2 = 0;
	r1 = b;		r2 = a;

	for ( ; r1 != 0; ) {
		q = r2 / r1;
		r = r2 % r1;
		x = x2 - (q * x1);
		y = y2 - (q * x1);

		r2 = r1;
		r1 = r;
		x2 = x1;
		y2 = y1;
		x1 = x;
		y1 = y;
	}
	X = x2;		Y = y2;
	return r2;
}

//	solve (x, y) for Ax + By = C
bool linearDiophantineEquation(int A, int B, int C, int &x, int&y) {
	int g = gcd(A, B);

	if (C % g != 0)
		return false;

	int a = A / g, b = B / g, c = C / g;
	ext_GCD(a, b, x, y);	//	solve ax + by = 1

	if (g < 0) {
		a *= -1;	b *= -1;	c *= -1;
	}

	x *= c;		y *= c;	//	ax + by = c
	return true;
}

//	simple Hyperbolic Diophantine Equation
//	solve (x, y)	for Axy + Bx + Cy = D
//	=> (Ax + C) (Ay + B) = AD + BC
//	(x, y) = ((d - C) / A	,	(P - Bd) / Ad)
//	where P = AD + BC
//	d is counted in res;
bool isValidSolution(int a, int b, int c, int p, int div) {
	if ( (div - c) % a != 0)	//	x = (div - c) / a
		return false;
	if ( (p - b*div) % (a*div) != 0)	//	y = (p - b*div) / (a*div)
		return false;
	return true;
}

int simpleHyperbolicDiophantineEquation(int a, int b, int c, int d) {
	int p = a*d + b*c;

	if (!p) {	//	ad + bc = 0
		if ((-c % a == 0) || (-b % a == 0))
			return - 1;
		return 0;
	}
	
	int res = 0;
	int sqrtp = sqrt(p), div;

	for (int i = 1; i <= sqrtp; i++) {
		if (p%i == 0) {
			res += isValidSolution(a, b, c, p, i) + isValidSolution(a, b, c, p, -i);
			res += ((p/i != i) * isValidSolution(a, b, c, p, p/i)); 
			res += ((p/i != i) * isValidSolution(a, b, c, p, -p/i)); 
		}
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

//	returns (n^p) % mod
LL bigMod(LL n, LL p, LL mod ) {
	LL res = 1%mod, x = n%mod;

	while (p) {
		if (p&1)
			res = (res * x) % mod;
		
		x = (x * x) % mod;
		p >>= 1;
	}
	return res;
}

//	x = (1/a) % mod
LL modInv(LL a, LL mod) {	//	mod is prime
	return bigMod(a, mod - 2, mod);
}

LL modInv2(LL a, LL mod) {	//	mod is not prime
	LL x, y;
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

//	return {-1. -1} if invalid input
//	return {x, l}	where x is unique
//	when mod by l [answer => x(MOD L)]
//	answer = x + L * k;	k = 0,1,2,3...
//	complexity: O( nlog(L) )
PII ChineseRemainderTheorem(vector <int> A, vector <int> M) {
	if (A.size() != M.size())
		return {-1, -1};
	
	int n = A.size();
	int a1 = A[0], m1 = M[0];

	for (int i = 1; i < n; i++) {
		int a2 = A[i], m2 = M[i];
		int g = gcd(m1, m2);

		if (a1%g != a2%g)
			return {-1, -1};
		
		int p, q;
		ext_GCD(m1/g, m2/g, p, q);

		int mod = m1 / g * m2;

		//modify inCase Overflow
		int x = (a1 * (m2 / g) * q + a2 * (m1 / g) * p) % mod;

		a1 = x;
		if (a1 < 0)
			a1 += mod;
		m1 = mod;
	}

	return PII(a1, m1);
}

int main() 
{
	cout << gcd(6, 8);

	//Linear Diophantine Equation

	int a = 2, b = 3, c = 5, x, y;
	int g = gcd(a, b);

	if (linearDiophantineEquation(a, b, c, x, y)) {
		for (int k = 1; k <= 100; k++)
			cout << x + k * (b / g) << "  " << y - k * (a / g) << endl;
	}


}