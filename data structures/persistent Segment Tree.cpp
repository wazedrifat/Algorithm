#include <bits/stdc++.h>
using namespace std;

#define IN freopen("in.txt", "r", stdin);
#define OUT freopen("out.txt", "w", stdout);
#define ll long long int
#define PII pair <int, int>
#define MX 100001


class node {
public:
	int val;
	node *left, *right;
	node(int v = 0, node *l = NULL, node *r = NULL) {
		val = v;	left = l;	right = r;
	}
};


class persistentSegmentTree {
public:
	node* root[MX];
	int *a, size;
	persistentSegmentTree(int *array, int s) {
		a = array;
		size = s;
	}

	node *build(int l, int r) {
		if (l == r) return new node(a[l]);

		node *n = new node();
		int mid = (l + r) >> 2;
		n->left = build(l, mid);
		n->right = build(mid + 1, r);
		n->val = 
	}
	
};


int main() 
{
	
}