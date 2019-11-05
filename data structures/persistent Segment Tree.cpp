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

struct node {
	node *left, *right;
	int val;
	node(int a = 0, node *b = NULL, node *c = NULL) {
		val = a;	left = b;	right = c;
	}

	void build(int l, int r) {
		if (l == r)
			return;
		
		left = new node();
		right = new node();

		int mid = (l + r) >> 1;
		left->build(l, mid);
		right->build(mid + 1, r);
	}

	node* update(int l, int r, int idx, int v) {
		if (r < idx || l > idx)
			return this;
		else if (l == r)
			return new node(val + v, left, right);
		
		int mid = (l + r) >> 1;
		node *ret = new node(val);
		ret->left = left->update(l, mid, idx, v);
		ret->right = right->update(mid+1, r, idx, v);
		ret->val = ret->left->val + ret->right->val;
		return ret;
	}
	
	//	[l, r] node range
	//	[i, j] query range
	int query(int l, int r, int i, int j) {
		if (r < i || l > j)
			return 0;
		else if (i <= l && r <= j)
			return val;
		
		int mid = (l + r) >> 1;
		int ret = left->query(l, mid, i, j) + right->query(mid+1, r, i, j);
		return ret;
	}
} *root[MX];

int main() 
{
	int n = MX:
	root[0] = new node();
	root[0]->build(0, n - 1);
	//update value of 4th index with 6
	root[1] = root[0]->update(0, n-1, 4, 6);
}