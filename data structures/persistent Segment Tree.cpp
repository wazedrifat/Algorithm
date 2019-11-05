#include <bits/stdc++.h>
using namespace std;

#define IN freopen("in.txt", "r", stdin);
#define OUT freopen("out.txt", "w", stdout);
#define ll long long int
#define PII pair <int, int>
#define MX 100001

int a[MX];

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
	
	node *update(int l, int r, int pos, node *cur, int val) {
		if (r < pos || l > pos)	return cur;
		if (l == r)
			return new node(cur->val+1);
		
		int mid = (l + r) >> 2;

		node *left = update(l, mid, pos, cur->left, val);
		node *right = update(mid + 1, r, pos, cur->right, val);
		
		return new node(left->val + right->val, left, right);
	}

	int query(int l, int r, int i, int j, node *cur) {//[l, r] range & [i, j] query
		if (r < i || l > j)	return 0;
		if (i <= l && j >= r)
			return cur->val;
		
		int mid = (l + r) >> 2;

		return query(l, mid, i, j, cur->left) + query(mid + 1, r, i, j, cur->right);
	}

	void print(node *cur) {
		if (cur == NULL)	return;

		cout << "cur = " << cur->val << " ";
		if (left != NULL)	cout << "left = " << cur->left->val << " ";
		if (right != NULL)	cout << "right = " << cur->right->val << " ";
		cout << endl;

		print(cur->left);
		print(cur->right);
	}
}


int main() 
{
	int a[5] = {2, 5 , 1, 7, 3};
	persistentSegmentTree pst[5];

	pst[0].build(0, 4);
	for (int i = 0; i < 5; i++) {
		pst[i+1] = pst[i].update(0, 4, a[i], pst[i].root, 1);

		cout << "i = " << i << " print: " << endl;

	}
}