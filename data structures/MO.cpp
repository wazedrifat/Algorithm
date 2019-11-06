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

// *not fully ready
struct query {
	int l, r, t, id;
}q[MX];

struct update {
	int x, pre, now;
}u[MX];

const int k = 320;//	ceil(sqrt(MX));

bool cmp(query &a, query &b) {
	int l1 = a.l / k, l2 = b.l / k,
	r1 = a.r / k, r2 = b.r / k;
	
	if(l1 != l2) 
		return l1 < l2;  
	if(r1 != r2) 
		return r1 < r2;
	return a.t < b.t;
}

int l = 0, r = -1, sum = 0, ans[MX], a[MX];

void apply(int x, int t) {
  if(l <= x && x <= r) {  // l, r is the l, r from MO's algo
    remove(x);
    a[x] = y;
    add(x);
  } else a[x] = y;
}

void add(int x) {
	sum += a[x];
}

void remove(int x) {
	sum += a[x];
}

int main() 
{
	int Q;
	cin >> Q;

	for (int i = 0; i < Q; i++) {
		cin >> q[i].l >> q[i].r;
		q[i].id = i;
	}
	sort(q, q+Q, cmp);

	int l = 0, r = -1, t = 0; 

	int last[N];
	for(int i = 0; i < N; i++)
		last[i] = a[i];

	for(int i = 0; i < Q; i++) {
		if( this is a query ) {
			store query {l, r, idx, id++} // idx is number of updates before, id is this query's id
		}
		if( this is an update ) {
			u[++idx] = {x, last[x], y};
			last[x] = y;
		}
	}

	for(int i = 0; i < Q; i++) {
		while(t < q[i].t) 
			t++, apply(u[t].x, u[t].now); 
		while(t > q[i].t) 
			apply(u[t].x, u[y].pre), t--; 

		while(l > q[i].l) 
			add(--l);
		while(r < q[i].r) 
			add(++r);
		while(l < q[i].l) 
			remove(l++);
		while(r > q[i].r) 
			remove(r--);

		ans[q[i].id] = some_variable;
	}
}