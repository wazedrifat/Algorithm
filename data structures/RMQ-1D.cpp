#include <bits/stdc++.h>
using namespace std;

#define SIZE 8

int a[SIZE] = {3, 6, 2, -1, 0, 3, 1, 5};
int sparse[SIZE][22], height;

int buildTable(int a[], int n) //time : o(nlogn)
{
	for (int i = 0; i < n; i++)
		sparse[i][0] = a[i];

	for (int i = 1; (1 << i) <= n; i++)
	{
		height = i;
		for (int j = 0; j < n; j++)
		{
			int k = j + (1 << (i - 1));
			if (k >= n)
				k = n - 1;
			sparse[j][i] = min(sparse[j][i - 1], sparse[k][i - 1]);
		}
	}
}

int rmq(int i, int j) //0 indexed & time : O(1)
{
	int len = j - i + 1, l = -1;
	while (len)
	{
		len = len >> 1;
		l++;
	}

	int minn = min(sparse[i][l], sparse[j - (1 << l) + 1][l]);
	return minn;
}

int main()
{
	buildTable(SIZE);

	int x, y;
	cin >> x >> y;

	cout << rmq(x, y) << endl;
}
