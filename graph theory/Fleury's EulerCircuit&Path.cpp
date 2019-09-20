#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>
#define MX 100005

vector<int> g[30];
int Tm = 0, d[MX], low[MX], NoOfChildren = 0, parent[MX];
bool ArticulationPoint[MX], visited[MX];
set<PII> edge;
int indegree[30], outdegree[30];

void FindArticulationBridge(int u = 0, int root = 0)
{
	if (u == root)
		memset(parent, -1, sizeof parent);

	low[u] = d[u] = Tm++;
	visited[u] = 1;

	for (int i = 0; i < g[u].size(); i++)
	{
		int v = g[u][i];

		if (u == root && !visited[v])
			NoOfChildren++;

		if (v == parent[u])
			continue;
		else if (visited[v])
			low[u] = min(low[u], d[v]);
		else
		{
			parent[v] = u;
			FindArticulationBridge(v, root);
		}

		low[u] = min(low[u], low[v]);

		//        printf("d[%d]=%d  low[%d]=%d\n", u, d[u], v, low[v]);

		if (d[u] < low[v])
			edge.insert(PII(u, v));
	}

	if (NoOfChildren > 1 && u == root)
		for (int i = 0; i < g[u].size(); i++)
			edge.insert(PII(u, g[u][i]));
}

PII HasDirectedEulerPath() //first is starting node & 2nd is ending node
{
	vector<int> v;
	PII p(-1, -1);

	for (int i = 0; i < 30; i++)
		if (outdegree[i] != indegree[i])
			v.push_back(i);

	if (v.size() == 2)
		if (outdegree[v[0]] - indegree[v[0]] == 1 && indegree[v[1]] - outdegree[v[1]] == 1)
			p = PII(v[0], v[1]);
		else if (outdegree[v[1]] - indegree[v[1]] == 1 && indegree[v[0]] - outdegree[v[0]] == 1)
			p = PII(v[1], v[0]);

	v.clear();
	return p;
}

deque<int> path;
void EulerCircuit(int n)
{
	visited[n] = 1;

	for (auto i : g[n])
		if (!visited[i] && edge.find(PII(n, i)) == edge.end())
			EulerCircuit(i);

	for (auto i : g[n])
		if (!visited[i])
			EulerCircuit(i);

	path.push_front(n);
}

int main()
{
	freopen("input.txt", "r", stdin);

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);

		g[u].push_back(v);
	}
	FindArticulationBridge(1, 1);

	cout << "Bridge=";
	for (auto i : edge)
		cout << i.first << " " << i.second << endl;

	memset(visited, 0, sizeof visited);
	EulerCircuit(1);

	printf("path for Euler Circuit : ");
	for (auto i : path)
		printf("%d ", i);
	cout << endl;

	//	memset(visited, 0, sizeof visited);
	//	EulerPath(0);
}
