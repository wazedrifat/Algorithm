			//topological sort
#include<bits/stdc++.h>
using namespace std;

#define MX 100005

vector<int>g[MX];
bool visited[MX];
deque<int>d;
int indegree[MX];

void topological_sort(int n)
{
	if(visited[n])	return;

	visited[n]=1;
	for(int i=0 ; i<g[n].size() ; i++)
	topological_sort(g[n][i]);

	d.push_front(n);
}

void TopologicalSort(int sz)
{
    for(int i=1 ; i<=sz ; i++)
    if(indegree[i]==0)
        topological_sort(i);
}

int main()
{
    vector<int>g[MX];
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=0 ; i<n ; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        g[u].push_back(v);
        indegree[v]++;
    }
    TopologicalSort(n);
}
