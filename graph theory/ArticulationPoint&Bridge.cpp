#include<bits/stdc++.h>
using namespace std;

#define MX 100005
#define PII pair<int, int>

vector<int>g[MX];
int Tm=0, d[MX], low[MX], NoOfChildren=0, parent[MX];
bool ArticulationPoint[MX], visited[MX];

void FindArticulationPoint(int u, int root)
{
    if(u==root)
        memset(parent, -1, sizeof parent);

	low[u]=d[u]=Tm++;
	visited[u]=1;

	for(int i=0 ; i<g[u].size() ; i++)
	{
	    int v=g[u][i];

	    if(u==root && !visited[v])  NoOfChildren++;

        if(v==parent[u])    continue;
        else if(visited[v])
            low[u]=min(low[u], d[v]);
        else
        {
            parent[v]=u;
            FindArticulationPoint(v, root);
        }

        low[u]=min(low[u], low[v]);

        if(d[u]<=low[v])
            ArticulationPoint[u]=1;
	}

    if(NoOfChildren>1 && u==root)
        ArticulationPoint[root]=1;
    else
        ArticulationPoint[root]=0;
}

set<PII>edge;
void FindArticulationBridge(int u, int root)
{
    if(u==root)
        memset(parent, -1, sizeof parent);

	low[u]=d[u]=Tm++;
	visited[u]=1;

	for(auto v : g[u])
	{
	    if(u==root && !visited[v])  NoOfChildren++;

        if(v==parent[u])    continue;
        else if(visited[v])
            low[u]=min(low[u], d[v]);
        else
        {
            parent[v]=u;
            FindArticulationBridge(v, root);
        }

        low[u]=min(low[u], low[v]);

        //printf("d[%d]=%d  low[%d]=%d\n", u, d[u], v, low[v]);

        if(d[u]<low[v])
        {
            edge.insert( PII(u, v) );
            edge.insert( PII(v, u) );
        }
	}

    if(NoOfChildren>1 && u==root)
    for(auto v : g[u])
    {
        edge.insert( PII(u, v) );
        edge.insert( PII(v, u) );
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    int n, m;
    scanf("%d %d", &n, &m);

    for(int i=0 ; i<m ; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        g[u].push_back(v);
        g[v].push_back(u);
    }
    FindArticulationBridge(0, 0);

    cout<<endl<<"answer :\n";
    for(auto i : edge)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
}
