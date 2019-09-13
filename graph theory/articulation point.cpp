#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_V 107

vector<long> Edge[MAX_V + 7];
long nVertex;

bool Visit[MAX_V + 7];
long Ind[MAX_V + 7], I; // I for Ind countin
long nChild[MAX_V + 7];
bool IsArt[MAX_V + 7];
long Low[MAX_V + 7];
long p[MAX_V + 7];

void Dfs(long u)
{
	// init
	Visit[u] = true;
	Ind[u] = ++I;
	nChild[u] = 0;
	IsArt[u] = false;
	Low[u] = I;
	long i;
	for (i = 0; i < Edge[u].size(); i++)
	{
		long v = Edge[u][i];
		if (!Visit[v])
		{
			p[v] = u;
			nChild[u]++;
			Dfs(v);
			// for findin bridge Low[v] > Ind[u]
			if (Low[v] >= Ind[u] && p[u] != -1)
				IsArt[u] = true;
			Low[u] = min(Low[u], Low[v]);
		}
		else if (p[u] != v)
		{
			Low[u] = min(Low[u], Ind[v]);
		}
	}
}

long Calc(void)
{
	long i;
	memset(&Visit[1], 0, sizeof(bool) * nVertex);
	for (i = 1; i <= nVertex; i++)
	{
		if (Visit[i])
			continue;
		p[i] = -1;
		I = 0;
		Dfs(i);
		if (nChild[i] > 1)
			IsArt[i] = true; // special check for root
	};

	long Ans = 0;
	for (i = 1; i <= nVertex; i++)
	{
		if (IsArt[i])
			Ans++;
	}

	return Ans;
}

int main(void)
{
	Input();
	long Ans = Calc();
	printf("%ld\n", Ans);

	return 0;
}
