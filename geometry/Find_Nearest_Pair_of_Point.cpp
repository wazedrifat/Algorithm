#include <bits/stdc++.h>
using namespace std;

#define IN freopen("in.txt", "r", stdin);
#define OUT freopen("out.txt", "w", stdout);
#define ll long long int
#define PII pair <int, int>
#define MX 100001

int n;
vector <point> a, temp;
double minDis;
PII best;

struct point {
	int x, y, id;
};

bool cmp(const point &a, const point &b) {
	return (a.x < b.x || (a.x == b.x && a.y < b.y));
}

bool cmpY(const point &a, const point &b) {
	return (a.y < b.y);
}

void update(const point &a, const point &b) {
	double dis = (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
	if (dis < minDis) {
		minDis = dis;
		best = PII(a.id, b.id);
	}
}

void rec(int l, int r) {
	if (r - l <= 3) {
		for (int i = l; i < r; i++)
			for (int j = i + 1; j < r; j++)
				update(a[i], a[j]);
		
		sort(a.begin(), a.end(), cmpY);
		return;
	}

	int m = (l + r) >> 1;
	int midX = a[m].x;
	
	rec(l, m);
	rec(m, r);

	merge(a.begin()+l, a.begin()+m, a.begin()+m, a.begin()+r, temp.begin(), cmpY);
	
}

int main() 
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		int y;
		scanf("%d", &y);

		a.push_back(point(x, y, i));
	}
	
}