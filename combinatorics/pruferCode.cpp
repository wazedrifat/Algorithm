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

//	node n occurs (d - 1) times in arra if
//	node n has degree of d
//	Tree to Prufer Code
//	Complexity: O(VlogV)

vector<int> treeToPrufercode(int nodes, vector<pair<int, int>> &edges) {
	unordered_set<int> neighbors[nodes + 1];

	for (int i = 0; i < edges.size(); i++) {
		pair<int, int> edge = edges[i];
		int u = edges[i].first;
		int v = edges[i].second;

		neighbors[u].insert(v);
		neighbors[v].insert(u);
	}

	priority_queue<int> leaves;
	for (int i = 0; i <= nodes; i++) {
		if (neighbors[i].size() == 1)
			leaves.push(-i);
	}

	vector<int> pruferCode;
	int need = nodes - 2;
	while (need--) {
		int leaf = -leaves.top();
		leaves.pop();
		
		int neighborOfLeaf = *(neighbors[leaf].begin());
		pruferCode.push_back(neighborOfLeaf);
		neighbors[neighborOfLeaf].erase(leaf);
		
		if (neighbors[neighborOfLeaf].size() == 1)
			leaves.push(-neighborOfLeaf);
	}
	return pruferCode;
}


//	Prufer Code to Tree
//	Complexity: O(VlogV)
vector<pair<int, int>> pruferCodeToTree(vector<int> &pruferCode) {
	unordered_map<int, int> nodeCount;
	set<int> leaves;

	int len = pruferCode.size();
	int node = len + 2;

	for (int i = 0; i < len; i++) {
		int t = pruferCode[i];
		nodeCount[t]++;
	}

	for (int i = 1; i <= node; i++) {
		if (nodeCount.find(i) == nodeCount.end())
			leaves.insert(i);
	}

	vector<pair<int, int>> edges;
	for (int i = 0; i < len; i++) {
		int a = pruferCode[i];
		int b = *leaves.begin();

		edges.push_back({a, b});
		leaves.erase(b);
		nodeCount[a]--;

		if (nodeCount[a] == 0)
			leaves.insert(a);
	}

	edges.push_back({*leaves.begin(), *leaves.rbegin()});
	return edges;
}

int main()
{

}