#include <bits/stdc++.h>
using namespace std;

#define MX 100005

int a[MX], SegTree[4 * MX], Lazy[4 * MX];

void init(int low, int high, int pos = 0) //	O(n)
{
	if (low == high)
	{
		SegTree[pos] = a[low];
		return;
	}

	int mid = (low + high) / 2;
	init(low, mid, 2 * pos + 1);
	init(mid + 1, high, 2 * pos + 2);

	SegTree[pos] = min(SegTree[2 * pos + 1], SegTree[2 * pos + 2]);
}

int Query(int low, int high, int Qlow, int Qhigh, int pos = 0) //O(logn)
{
	if (Lazy[pos])
	{
		SegTree[pos] += Lazy[pos];

		if (low != high) //not a leaf node
		{
			Lazy[2 * pos + 1] += Lazy[pos];
			Lazy[2 * pos + 2] += Lazy[pos];
		}
		Lazy[pos] = 0;
	}

	if (Qlow > high || Qhigh < low || low > high)
		return INT_MAX;
	if (Qlow <= low && Qhigh >= high)
		return SegTree[pos];

	int mid = (low + high) / 2;
	int x = Query(low, mid, Qlow, Qhigh, 2 * pos + 1);
	int y = Query(mid + 1, high, Qlow, Qhigh, 2 * pos + 2);

	return min(x, y);
}

void Update(int low, int high, int Qlow, int Qhigh, int val, int pos = 0) //O(logn)
{
	if (Lazy[pos])
	{
		SegTree[pos] += Lazy[pos];

		if (low != high) //not a leaf node
		{
			Lazy[2 * pos + 1] += Lazy[pos];
			Lazy[2 * pos + 2] += Lazy[pos];
		}
		Lazy[pos] = 0;
	}

	if (Qlow > high || Qhigh < low || low > high)
		return;
	if (Qlow <= low && Qhigh >= high)
	{
		SegTree[pos] += val;

		if (low != high) //not a leaf node
		{
			Lazy[2 * pos + 1] += val;
			Lazy[2 * pos + 2] += val;
		}
		return;
	}

	int mid = (low + high) / 2;

	Update(low, mid, Qlow, Qhigh, val, 2 * pos + 1);
	Update(mid + 1, high, Qlow, Qhigh, val, 2 * pos + 2);

	SegTree[pos] = min(SegTree[2 * pos + 1], SegTree[2 * pos + 2]);
}

int main()
{
	init(5);

	Update(0, 5, 1, 2, 4);
	Update(0, 5, 2, 4, 5);

	cout << Query(0, 5, 0, 2) << " " << Query(0, 5, 1, 4) << " " << Query(0, 5, 2, 2) << endl;
}
