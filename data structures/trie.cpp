#include <bits/stdc++.h>
using namespace std;

#define MX 26

struct node
{
	bool end;
	node *next[MX];

	node()
	{
		end = 0;
		for (int i = 0; i < MX; i++)
			next[i] = NULL;
	}
};

class trie
{
public:
	node *root;

	trie()
	{
		root = new node();
	}

	void Insert(string s)
	{
		node *cur = root;

		for (int i = 0; i < s.length(); i++)
		{
			int id = s[i] - 'a';

			if (cur->next[id] == NULL)
				cur->next[id] = new node();

			cur = cur->next[id];
		}
		cur->end = 1;
	}

	bool Find(string s)
	{
		node *cur = root;

		for (int i = 0; i < s.length(); i++)
		{
			int id = s[i] - 'a';

			if (cur->next[id] == NULL)
				return 0;

			cur = cur->next[id];
		}

		return cur->end;
	}

	void del(node *cur)
	{
		for (int i = 0; i < MX; i++)
			if (cur->next[i])
				del(cur->next[i]);

		delete (cur);
	}
};

int main()
{
	trie a;
	cout << 1 << endl;
	a.Insert("abc");
	cout << 2 << endl;
	a.Insert("bcd");
	cout << 3 << endl;
	cout << a.Find("ab") << endl;
	cout << a.Find("ac") << endl;
	cout << a.Find("abc") << endl;
	a.del(a.root);
}
