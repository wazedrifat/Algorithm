#include<bits/stdc++.h>
using namespace std;

#define MX 10000

struct edge
{
	int u, v, w;
	edge(int _u, int _v, int _w)
	{
	    u=_u;   v=_v;   w=_w;
	}
}
vector<edge>e;
int	pr[MX];

bool comp(edge a, edge b){	return a.w<=b.w;	}

int Find(int r)
{
    int m=n;
    while(pr[m]!=m)
    m=pr[m];

    while(pr[n]!=n)
    {
        int k=pr[n];
        pr[n]=m;
        n=k;
    }
    return m;
}

int mst(int node)
{
	sort(e.begin(),e.end(),comp);

	for(int i=0 ; i<=node ; i++)	pr[i]=i;

	int cnt=0,sum=0;
	for(int i=0 ; i<e.size() ; i++)
	{
		int u=Find(e[i].u);
		int v=Find(e[i].v);

		if(u!=v)
		{
			pr[u]=v;
			cnt++;
			sum+=e[i].w;

			if(cnt==n-1)	break;
		}
	}
	return sum;
}

int main()
{

}
