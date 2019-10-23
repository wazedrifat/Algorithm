#include <bits/stdc++.h>
using namespace std;

#define IN freopen("in.txt", "r", stdin);
#define OUT freopen("out.txt", "w", stdout);
#define ll long long int
#define PII pair <int, int>
#define MX 100001

int main() 
{
	vector <int> a{1, 2, 3}, b{4, 5, 6}, c(2, 0);

	merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());

	
	cout << "a : ";		//ThisIsForDebuggingPurposes
	for (int temporary = 0; temporary < a.size(); temporary++)		//ThisIsForDebuggingPurposes
		cout << a[temporary] << ' ' ;		//ThisIsForDebuggingPurposes
	cout << endl;		//ThisIsForDebuggingPurposes

	
	cout << "b : ";		//ThisIsForDebuggingPurposes
	for (int temporary = 0; temporary < b.size(); temporary++)		//ThisIsForDebuggingPurposes
		cout << b[temporary] << ' ' ;		//ThisIsForDebuggingPurposes
	cout << endl;		//ThisIsForDebuggingPurposes
	
	
	cout << "c : ";		//ThisIsForDebuggingPurposes
	for (int temporary = 0; temporary < c.size(); temporary++)		//ThisIsForDebuggingPurposes
		cout << c[temporary] << ' ' ;		//ThisIsForDebuggingPurposes
	cout << endl;		//ThisIsForDebuggingPurposes
	
	

}