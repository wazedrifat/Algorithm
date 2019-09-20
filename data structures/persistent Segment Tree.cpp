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
	node* root;
	int *a, size;
	persistentSegmentTree( ) {
	
	}

	node *build(int l, int r) {
		if (l == r) return new node(a[l]);

		node *n = new node();
		int mid = (l + r) >> 2;
		n->left = build(l, mid);
		n->right = build(mid + 1, r);
		n->val = n->left->val + n->right->val;

		return n;
	}
	
	node *update(int l, int r, int pos, int val) {
		if (r < pos || l > pos)	return NULL;
	}
};


int main() 
{
	int a[5] = {2, 5 , 1, 7, 3};
	persistentSegmentTree pst[5];

	pst[0].build(0, 5);

	pst[1].root = pst[0].update();

	pst[1].root = pst[1].update();
}