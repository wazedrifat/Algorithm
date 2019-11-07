#include <bits/stdc++.h>
using namespace std;

#define MAX 30007

int N; // number of node in tree
vector<int> Edge[MAX + 7];
int SubT[MAX + 7];  // subtree size
int Par[MAX + 7];   // parent of a node
int Level[MAX + 7]; // level of a node

int nC;				   // number of chain
int ChainLdr[MAX + 7]; // chainleadr of a node
					   // for light edge chainldr is that node
int Chain[MAX + 7];	// node v in is which chain
int nP;				   // number of position , obviously == N
int Pos[MAX + 7];	  // Pos of a node in chain/dfs order

int Explore(int u, int p, int l) // find subtree size and level
{
	SubT[u] = 1;
	Par[u] = p;
	Level[u] = l;
	int i;
	for (i = 0; i < Edge[u].size(); i++)
	{
		int v = Edge[u][i];
		if (p == v)
			continue;
		SubT[u] += Explore(v, u, l + 1);
	}
	return SubT[u];
}

void HeavyLight(int u, int k, bool IsL) //if IsL make this node a chainledr of new chain
{
	if (IsL)
	{
		k = ++nC;
		ChainLdr[k] = u;
	}
	Chain[u] = k;
	Pos[u] = ++nP;
	//Update( nP,W[u] ); if query is need can b updated here
	int i, mx = -1; // max subtree size child is mx
	for (i = 0; i < Edge[u].size(); i++)
	{
		int v = Edge[u][i];
		if (Par[u] == v)
			continue;
		if (mx == -1)
			mx = v;
		else if (SubT[v] > SubT[mx])
			mx = v;
	}
	if (mx == -1)
		return;
	HeavyLight(mx, k, false);
	for (i = 0; i < Edge[u].size(); i++)
	{
		int v = Edge[u][i];
		if (Par[u] == v || mx == v)
			continue;
		HeavyLight(v, 0, true);
	}
}

int LCA(int u, int v)
{
	while (Chain[u] != Chain[v])
		if (Level[ChainLdr[Chain[u]]] < Level[ChainLdr[Chain[v]]])
			v = Par[ChainLdr[Chain[v]]];
		else
			u = Par[ChainLdr[Chain[u]]];
	if (Level[u] < Level[v])
		return u;
	else
		return v;
}

int main(void)
{
	//freopen("text1.txt","r",stdin );
	// node is index from 0
	scanf("%ld", &N);
	Explore(0, 0, 0);
	HeavyLight(0, 0, true);
	return 0;
}


//	cp-algorithm

vector<int> parent, depth, heavy, head, pos;
int cur_pos;

int dfs(int v, vector<vector<int>> const& adj) {
    int size = 1;
    int max_c_size = 0;
    for (int c : adj[v]) {
        if (c != parent[v]) {
            parent[c] = v, depth[c] = depth[v] + 1;
            int c_size = dfs(c, adj);
            size += c_size;
            if (c_size > max_c_size)
                max_c_size = c_size, heavy[v] = c;
        }
    }
    return size;
}

int decompose(int v, int h, vector<vector<int>> const& adj) {
    head[v] = h, pos[v] = cur_pos++;
    if (heavy[v] != -1)
        decompose(heavy[v], h, adj);
    for (int c : adj[v]) {
        if (c != parent[v] && c != heavy[v])
            decompose(c, c, adj);
    }
}

void init(vector<vector<int>> const& adj) {
    int n = adj.size();
    parent = vector<int>(n);
    depth = vector<int>(n);
    heavy = vector<int>(n, -1);
    head = vector<int>(n);
    pos = vector<int>(n);
    cur_pos = 0;

    dfs(0, adj);
    decompose(0, 0, adj);
}
int query(int a, int b) {
    int res = 0;
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        int cur_heavy_path_max = segment_tree_query(pos[head[b]], pos[b]);
        res = max(res, cur_heavy_path_max);
    }
    if (depth[a] > depth[b])
        swap(a, b);
    int last_heavy_path_max = segment_tree_query(pos[a], pos[b]);
    res = max(res, last_heavy_path_max);
    return res;
}