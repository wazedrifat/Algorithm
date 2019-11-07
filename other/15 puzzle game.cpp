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

//	This game is played on a 4×4 board. 
//	On this board there are 15 playing tiles numbered 
//	from 1 to 15. One cell is left empty (denoted by 0). 
//	You need to get the board to the position presented below 
//	by repeatedly moving one of the tiles to the free space:


int main() 
{
	int a[16];
	for (int i=0; i<16; ++i)
		cin >> a[i];

	int inv = 0;
	for (int i=0; i<16; ++i)
		if (a[i])
			for (int j=0; j<i; ++j)
				if (a[j] > a[i])
					++inv;
	for (int i=0; i<16; ++i)
		if (a[i] == 0)
			inv += 1 + i / 4;

	puts ((inv & 1) ? "No Solution" : "Solution Exists");
}