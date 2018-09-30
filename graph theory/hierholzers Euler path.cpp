#include<bits/stdc++.h>
using namespace std;

#define MX 100005

vector<int>g[MX];
deque<int>circuit, CurPath;

void HierHolzar(int start)
{
	circuit.clear();
	CurPath.clear();
	int EdgeCount[MX];

	for(int i=0 ; i<MX ; i++)
		EdgeCount[i]=g[i].size();

	CurPath.push_back(start);
	int CurV=start;

	while(CurPath.size())
	if(EdgeCount[CurV])
	{
		CurPath.push_back(CurV);
		int NextV=g[CurV].back();
		EdgeCount[CurV]--;
		g[CurV].pop_back();
//		vector<int>::iterator it=find(g[NextV].begin(), g[NextV].end(), CurV);
//		if( it!=g[NextV].end() )
//		g[NextV].erase(it);
		CurV=NextV;
	}
	else
	{
		circuit.push_front(CurV);
		CurV=CurPath.back();
		CurPath.pop_back();
	}
}

int main()
{
	int n=7, m=7;

	g[0].push_back(1);
	g[1].push_back(4);
	g[2].push_back(3);
	g[2].push_back(5);
	g[5].push_back(6);
	g[6].push_back(2);
	g[3].push_back(0);

	HierHolzar(2);

	for(auto v : circuit)
		cout<<v<<" ";
}
