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

bool islow(char ch){if(ch>='a' && ch<='z') return true; return false;}
bool isupp(char ch){if(ch>='A' && ch<='Z') return true; return false;}
bool isdig(char ch){if(ch>='0' && ch<='9') return true; return false;}
 
//any base to decimal conversion
int todec(string s, int base) {
	int i, j, temp, len, sum = 0;

	len = s.length() - 1;
	for (i = 0, j = len; i <= len; i++, j--) {
		char ch = s.at(i);
		if (isdig(ch))
			temp = ch - '0';
		else if (islow(ch))
			temp = 10 + ch - 'a';
		else if (isupp(ch))
			temp = 10 + ch - 'A';

		sum += (temp * (power(base, j)));
	}
	return sum;
}

//decimal to any base conversion
string tobase(int num, int base) {
	int temp;
	string s;
	char ch;

	if (!num)
		return "0"; //special '0' case handling

	while (num > 0)	{
		temp = num % base;
		num /= base;
		if (temp <= 9)
			s += (temp + '0');
		else
			s += ((temp - 10) + 'A');
	}
	reverse(all(s));
	return s;
}

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

//	(n!)^k
int fact_pow (int n, int k) {
    int res = 0;
    while (n) {
        n /= k;
        res += n;
    }
    return res;
}

//	pascale triangle
const int maxn = ...;
int C[maxn + 1][maxn + 1];
C[0][0] = 1;
for (int n = 1; n <= maxn; ++n) {
    C[n][0] = C[n][n] = 1;
    for (int k = 1; k < n; ++k)
        C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
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