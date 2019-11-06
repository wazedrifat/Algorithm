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
#define VI vector <int> 

const int base = 1000 * 1000 * 1000;


void output(VI &a) {
	printf ("%d", a.empty() ? 0 : a.back());
	for (int i=(int)a.size()-2; i>=0; --i)
		printf ("%09d", a[i]);
}

void input(string s, VI &a) {
	for (int i=(int)s.length(); i>0; i-=9)
    if (i < 9)
        a.push_back (atoi (s.substr (0, i).c_str()));
    else
        a.push_back (atoi (s.substr (i-9, 9).c_str()));
	
	while (a.size() > 1 && a.back() == 0)
    a.pop_back();
}

VI& add(VI &a, VI &b) {
	int carry = 0;
	for (size_t i=0; i<max(a.size(),b.size()) || carry; ++i) {
		if (i == a.size())
			a.push_back (0);
		
		a[i] += carry + (i < b.size() ? b[i] : 0);
		carry = a[i] >= base;
		
		if (carry)  
			a[i] -= base;
	}
	return a;
}

VI& substract(VI &a, VI &b) {
	int carry = 0;
	for (size_t i=0; i<b.size() || carry; ++i) {
		a[i] -= carry + (i < b.size() ? b[i] : 0);
		carry = a[i] < 0;
		if (carry)  a[i] += base;
	}
	
	while (a.size() > 1 && a.back() == 0)
		a.pop_back();
	return a;
}

VI& multiplicationLS(VI &a, VI &b) {
	int carry = 0;
	for (size_t i=0; i<a.size() || carry; ++i) {
		if (i == a.size())
			a.push_back (0);
		long long cur = carry + a[i] * 1ll * b;
		a[i] = int (cur % base);
		carry = int (cur / base);
	}
	while (a.size() > 1 && a.back() == 0)
		a.pop_back();
	return a;
}

VI multiplicationLL(VI &a, VI &b) {
	VI c (a.size()+b.size());
	for (size_t i=0; i<a.size(); ++i)
		for (int j=0, carry=0; j<(int)b.size() || carry; ++j) {
			long long cur = c[i+j] + a[i] * 1ll * (j < (int)b.size() ? b[j] : 0) + carry;
			c[i+j] = int (cur % base);
			carry = int (cur / base);
		}
	while (c.size() > 1 && c.back() == 0)
		c.pop_back();
	return c;
}

VI& divionLS(VI &a, VI &b) {
	int carry = 0;
	for (int i=(int)a.size()-1; i>=0; --i) {
		long long cur = a[i] + carry * 1ll * base;
		a[i] = int (cur / b);
		carry = int (cur % b);
	}
	while (a.size() > 1 && a.back() == 0)
		a.pop_back();
	return a;
}

int main() 
{
	
}