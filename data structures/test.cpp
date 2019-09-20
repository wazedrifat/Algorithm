#include <bits/stdc++.h>
using namespace std;

#define IN freopen("in.txt", "r", stdin);
#define OUT freopen("out.txt", "w", stdout);
#define ll long long int
#define PII pair <int, int>
#define MX 100001


class cls {
public:
	int a, b;
	cls(int p, int q) {
		a = p;	b = q;
	}
	
};


int main() 
{
	cls c[5] = {2, 3};

	for (int i = 0; i < 5; i++)
	{
		cout << c[i].a << " " << c[i].b << endl;
	}
	
}