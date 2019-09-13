#include <bits/stdc++.h>
using namespace std;

#define MX 13
#define PII pair<int, int>

vector<int> g[MX];
int dist[MX];
int path[MX], visited[MX]; //use disjoint set find() to print path

void BFS(int source, int destination = -1)
{
	queue<int> Q;

	for (int i = 0; i < MX; i++)
		visited[i] = 0;

	Q.push(source);

	dist[source] = 0;
	visited[source] = 1;

	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();

		for (int i = 0; i < g[u].size(); i++)
		{
			int v = g[u][i];

			if (!visited[v])
			{
				dist[v] = dist[u] + 1;
				visited[v] = 1;
				Q.push(v);
				path[v] = u;
			}
		}
	}
}

int Tm = 0;
int FinishingTime[MX], ArrivalTime[MX];

void DFS(int node = 0, int d = 0)
{
	ArrivalTime[node] = Tm++;
	visited[node] = 1;
	dist[node] = d;

	for (int i = 0; i < g[node].size(); i++)
		if (!visited[g[node][i]])
		{
			path[g[node][i]] = node;
			DFS(g[node][i], d + 1);
		}
	FinishingTime[node] = Tm++;
}

vector<int> cost[MX];
int cost1[MX][MX];

void Dijkstra(int source)
{
	map<int, int> m;

	for (int i = 1; i < MX; i++)
	{
		dist[i] = INT_MAX;
		path[i] = -1;
	}

	m[0] = source;
	dist[source] = 0;

	while (!m.empty())
	{
		map<int, int>::iterator it = m.begin();

		int u = it->second;
		m.erase(it);

		for (int i = 0; i < g[u].size(); i++)
		{
			int v = g[u][i];
			int NewCost = dist[u] + cost[u][i];

			if (NewCost < dist[v])
			{
				path[v] = u;
				dist[v] = NewCost;
				m[NewCost] = v;
			}
		}
	}
}

void PrintPath(int v)
{
	if (v == -1)
		return;
	PrintPath(path[v]);
	cout << v << " ";
}

int main()
{
	int n = 5, m = 6;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;

		g[x].push_back(y);
		g[y].push_back(x);

		cost[x].push_back(w);
		cost[y].push_back(w);

		cost1[x][y] = w;
		cost1[y][x] = w;
	}

	Dijkstra(1);
	//	BFS(1);
	for (int i = 2; i <= 10; i++)
	{
		cout << "i=" << i << " dist=" << dist[i] << " path : ";

		PrintPath(i);
		cout << endl;
	}
}
