#include <bits/stdc++.h>
using namespace std;

#define IN freopen("in.txt", "r", stdin);
#define OUT freopen("out.txt", "w", stdout);
#define ll long long int
#define PII pair<int, int>
#define MX 100001
#define EPS 1e-9
#define MOD 1000000007
#define PI 2.0 * acos(0.0)
#define sz 100

// call DFS(G) to compute finishing times f [u] for all u
// compute GT
// call DFS(GT), but in the main loop, consider vertices in order of decreasing f [u] (as computed in first DFS)
// output the vertices in each tree of the depth-first forest formed in second DFS as a separate SCC

vector<int> graph[sz], Gt[sz]; //graph[] store the graph and Gt[] store transpose graph
vector<int> topo;
int disc[sz], fin[sz], color[sz];
int time = 0;

void dfs_visit(int node, int flag)
{
	int i, j, k, temp;

	color[node] = 1;
	if (flag == 0) //for the general graph, first dfs call
	{
		disc[node] = ++time;

		for (i = 0; i < graph[node].size(); i++)
		{
			temp = graph[node][i];
			if (color[temp] == 0)
				dfs_visit(temp, flag);
		}
		fin[node] = ++time;
		topo.push_back(node);
	}
	else //for the transpose graph, second dfs call
	{
		printf("%d ", node);
		for (i = 0; i < Gt[node].size(); i++)
		{
			temp = Gt[node][i];
			if (color[temp] == 0)
				dfs_visit(temp, flag);
		}
	}

	color[node] = 2;
}

void dfs(int node, int flag)
{
	int i, j;

	if (flag == 0) //for the general graph, first dfs call
	{
		for (i = 0; i < node; i++)
		{
			if (color[i] == 0)
				dfs_visit(i, flag);
		}
	}
	else //for the transpose graph, second dfs call
	{
		for (i = 0; i < topo.size(); i++)
		{
			if (color[topo[i]] == 0)
			{
				dfs_visit(topo[i], flag);
				puts("");
			}
		}
	}
}

int main()
{
	int i, j, k, num, t, node, edge, a, b;

	scanf("%d%d", &node, &edge);

	for (i = 0; i < edge; i++)
	{
		scanf("%d%d", &a, &b);
		graph[a].push_back(b); //directed graph
		Gt[b].push_back(a);	//transpose graph
	}

	//dfs in graph
	for (i = 0; i < node; i++)
		color[i] = 0;

	dfs(node, 0);

	//finding topological sort
	reverse(topo.begin(), topo.end());

	//dfs in transpose graph
	for (i = 0; i < node; i++)
		color[i] = 0;

	dfs(node, 1); //connected components will be printed in this call

	return 0;
}