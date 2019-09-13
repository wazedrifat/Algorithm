/*
 * Algoritm : Min Cost Max Flow using Bellmen Ford
 * Note : Vertex are 0 indexing Based
 */
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_V 3777
#define INF 777777777
struct NODE
{
	long v, Cap, Cost, RevInd; // This ind is necesery for multigraph to knw which edge is used to take flow
};
vector<NODE> Edge[MAX_V + 7];
long nV, nE, P;
long SRC, TNK;
// This PInd is neceserry for multigraph to knw which edge ind of parent is used to take flow
long Par[MAX_V + 7], PInd[MAX_V + 7];
long SD[MAX_V + 7]; // Shortest path

void SetEdge(long u, long v, long Cap, long Cost)
{
	NODE U = {v, Cap, Cost, Edge[v].size()};
	NODE V = {u, 0, -Cost, Edge[u].size()};
	Edge[u].push_back(U);
	Edge[v].push_back(V);
}

bool BFord(void)
{
	long i, u, k;
	for (i = 0; i < nV; i++)
	{
		Par[i] = -1;
		SD[i] = INF;
	}
	bool IsChange = true;
	SD[SRC] = 0;
	while (IsChange)
	{
		IsChange = false;
		for (u = SRC; u <= TNK; u++)
		{
			for (i = 0; i < Edge[u].size(); i++)
			{
				if (!Edge[u][i].Cap)
					continue;
				long v = Edge[u][i].v;
				TD = SD[u] + Edge[u][i].Cost;
				// relaxation
				if (SD[v] > TD)
				{
					SD[v] = TD;
					Par[v] = u;
					PInd[v] = i;
					IsChange = true;
				}
			}
		}
	}
	return Par[TNK] != -1;
}

long FindVol(long s, long t)
{
	long Cap = Edge[Par[t]][PInd[t]].Cap;
	if (s == Par[t])
		return Cap;
	else
		return min(Cap, FindVol(s, Par[t]));
}

long AugmentPath(long s, long t, long V)
{
	if (s == t)
		return 0;
	long Cost = Edge[Par[t]][PInd[t]].Cost * V;
	Edge[Par[t]][PInd[t]].Cap -= V;
	Edge[t][Edge[Par[t]][PInd[t]].RevInd].Cap += V;
	return Cost + AugmentPath(s, Par[t], V);
}

void MinCost(long &Flow, long &Cost)
{
	Flow = Cost = 0;
	while (BFord())
	{
		long V = FindVol(SRC, TNK);
		Flow += V;
		Cost += AugmentPath(SRC, TNK, V);
	}
}