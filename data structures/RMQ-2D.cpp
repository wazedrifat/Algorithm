//    not done

#include <bits/stdc++.h>
using namespace std;

#define SIZE 8

int a[SIZE][SIZE];
int sparse[SIZE][SIZE][22], height;

int buildTable(int n) //time : o(nlogn)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			sparse[i][j][0] = a[i][j];

	for (int i = 1; (1 << i) <= n; i++)
	{
		height = i;
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
			{
				int l = j + (1 << (i - 1));
				if (l >= n)
					l = n - 1;
				sparse[j][i] = min(sparse[j][i - 1], sparse[l][i - 1]);
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
	buildTable(8);

	int x, y;
	cin >> x >> y;

	cout << rmq(x, y) << endl;
}
