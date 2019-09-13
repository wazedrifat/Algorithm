#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>
#define MX 100005

class DisjointSet
{
public:
	PII a[MX]; //index for value, first value for parent, second value for rank
	DisjointSet(int sz = MX)
	{
		for (int i = 0; i < sz; i++)
		{
			a[i].first = i;
			a[i].second = 0;
		}
	}

	int FindSet(int n)
	{
		int m = n;
		while (a[m].first != m)
			m = a[m].first;

		a[n].first = m;
		return m;
	}

	void Union(int n1, int n2)
	{
		int x = FindSet(n1);
		int y = FindSet(n2);

		//cout<<"x="<<x<<" y="<<y<<endl;

		if (a[x] == a[y])
			return;
		else if (a[x].second < a[y].second)
			swap(x, y);

		a[y].first = x;
		a[x].second++;
	}

	void print(int v)
	{
		for (int i = 0; i < v; i++)
			cout << "i=" << i << " parent=" << a[i].first << endl;
	}
};

int main()
{
	DisjointSet d;
	d.print(10);

	while (1)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		d.Union(u, v);
		d.print(10);
	}
}
