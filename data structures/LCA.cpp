#include<bits/stdc++.h>
using namespace std;

#define MX 100005
vector<int>g[MX];
int level[MX],height;
int sparse[MX][22],parent[MX];
int visited[MX];

void dfs(int v, int u=-1, int lvl=0)//for defining parent
{
	visited[v]=1;
	parent[v]=u;
	level[v]=lvl;
	height=max(height, lvl);

	for(int i=0 ; i<g[v].size() ; i++)
	if(!visited[ g[v][i] ])
		dfs(g[v][i], v, lvl+1);
}

void SparseTable(int n)
{
    for(int i=0 ; i<n ; i++)
    sparse[i][0]=parent[i];

    for(int i=1 ; (1<<i)<n ; i++)
	for(int j=0 ; j<n ; j++)
		if( sparse[j][i-1]!=-1 )	sparse[j][i]=sparse[ sparse[j][i-1] ][i-1];
		else						sparse[j][i]=-1;
}

int findLCA( int u, int v, int n)
{
    if( level[u]>level[v] )	swap(u, v);//so that level[u] is alawys smaller
    while( level[v]>level[u])
    {
    	int k=log2( level[v]-level[u] );
    	v=sparse[v][k];
    }
    if( u==v )	return u;

    for(int i=height ; i>=0 ; i--)
	{
        if( sparse[u][i]==sparse[v][i] )	continue;
        u=sparse[u][i];		v=sparse[v][i];
    }
    return sparse[u][0];
}

int main()
{
	int n;
	cin>>n;

	for(int i=1 ; i<n ; i++)
	{
		int u, v;
		cin>>u>>v;

		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=0 ; i<n ; i++)
	{
		parent[i]=-1;
		visited[i]=0;
	}
	dfs(0);

	SparseTable(n);

	int t=5;
	while(t--)
	{
		int u, v;
		cin>>u>>v;

		cout<<findLCA(u, v, n)<<endl;
	}

}
