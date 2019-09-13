#include <bits/stdc++.h>
using namespace std;
#define read freopen("C:\\Users\\Dell\\Desktop\\in.txt", "r", stdin)
#define write freopen("C:\\Users\\Dell\\Desktop\\out.txt", "w", stdout)
#define pii pair<int, int>
#define pll pair<LL, LL>
#define inf 1111111111
#define in(a) scanf("%d", &a)
#define ins(a) scanf("%s", a)
#define in2(a, b) scanf("%d%d", &a, &b)
#define in3(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pn printf("\n");
#define pr(a) printf("%d\n", a)
#define prs(a) printf("%d ", a)
#define pr2(a, b) printf("%d %d\n", a, b)
#define pr3(a, b, c) printf("%d %d %d\n", a, b, c)
#define MP make_pair
#define vi vector<int>
#define vll vector<LL>
#define _ceil(n, a) ((n) % (a) == 0 ? ((n) / (a)) : ((n) / (a) + 1))
#define cl clear()
#define sz size()
#define pb push_back
#define MEM(a, b) memset((a), (b), sizeof(a))
#define CASE printf("Case %d: ", ++cs)
#define all(X) (X).begin(), (X).end()
#define iter(it, X) for (__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)
#define oka(x, y) ((x) >= 0 && (x) < row && (y) >= 0 && (y) < col)
typedef long long LL;
//int  dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int  dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int  dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//bool check(int n, int pos) {return (n & (1<<pos))>>pos;} //typecast 1 in case of int
//int  on(int n, int pos) {return n | (1<<pos);} //typecast 1 in case of int
//int  off(int n, int pos) {return n & ~(1<<pos);} //typecast 1 in case of int
//bool operator < (const data &d) const{return cost<d.cost;} //reverse in priority queue
int getnum()
{
	char c = getchar();
	int num, sign = 1;
	for (; c < '0' || c > '9'; c = getchar())
		if (c == '-')
			sign = -1;
	for (num = 0; c >= '0' && c <= '9';)
	{
		c -= '0';
		num = num * 10 + c;
		c = getchar();
	}
	return num * sign;
}
/* ***************************************************************************************
       *************************************************************************************** */
const int M = 2002;
vi A[M], G[M], graph[M], trans[M];
int visited[M], matched_with[M], P[M], n;
bitset<M> reachable[M];
stack<int> S;
void pre_dfs(int u)
{
	visited[u] = true;
	for (int i = 0; i < graph[u].sz; i++)
		if (!visited[graph[u][i]])
			pre_dfs(graph[u][i]);
	S.push(u);
}
void pre_dfs2(int u, int p)
{
	visited[u] = true;
	P[u] = p;
	for (int i = 0; i < trans[u].sz; i++)
		if (!visited[trans[u][i]])
			pre_dfs2(trans[u][i], p);
}
int convert_to_DAG()
{
	int i, j, cnt = 0;
	MEM(visited, 0);
	for (i = 1; i <= n; i++)
		if (!visited[i])
			pre_dfs(i);

	MEM(visited, 0);
	while (!S.empty())
	{
		if (!visited[S.top()])
			pre_dfs2(S.top(), S.top());
		S.pop();
	}

	for (i = 1; i <= n; i++)
	{
		if (P[i] == i)
			cnt++;
		for (j = 0; j < graph[i].sz; j++)
		{
			int u = P[i], v = P[graph[i][j]];
			if (u != v)
				G[u].pb(v);
		}
	}
	return cnt;
}
void dfs(int u)
{
	int i, v;
	visited[u] = true;

	for (i = 0; i < G[u].sz; i++)
	{
		v = G[u][i];
		if (!visited[v])
			dfs(v);

		reachable[u][v] = true;
		reachable[u] |= reachable[v];
	}
}
void make_new_graph()
{
	int i, j;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (reachable[i][j])
				A[i].pb(j + n);
}
bool find_new_match(int u)
{
	int i, v;
	for (i = 0; i < A[u].sz; i++)
	{
		v = A[u][i];
		if (visited[v] == true)
			continue;

		if (matched_with[v] == -1)
		{
			matched_with[v] = u;
			matched_with[u] = v;
			return true;
		}
		else if (matched_with[v] != u)
		{
			visited[v] = true;
			if (find_new_match(matched_with[v]))
			{
				matched_with[v] = u;
				matched_with[u] = v;

				return true;
			}
		}
	}
	return false;
}
int _max_match()
{
	int i, _match = 0, N = 2 * n;
	for (i = 0; i <= N; i++)
		matched_with[i] = -1;

	_match = 0;
	for (i = 1; i <= n; i++)
	{
		if (P[i] != i)
			continue;
		if (matched_with[i] == -1)
		{
			MEM(visited, false);
			if (find_new_match(i))
			{
				_match++;
			}
		}
	}
	return _match;
}
int main()
{
#ifndef ONLINE_JUDGE
	read;
#endif
	int i, j, k, t, cs = 0, m, xnodes;
	//CASE //CLEAR

	t = getnum();
	while (t--)
	{
		n = getnum();
		m = getnum();
		while (m--)
		{
			i = getnum();
			j = getnum();
			graph[i].pb(j);
			trans[j].pb(i);
		}

		xnodes = convert_to_DAG();
		MEM(visited, 0);
		MEM(reachable, 0);
		for (i = 1; i <= n; i++)
			if (!visited[i])
				dfs(i);
		make_new_graph();
		k = _max_match();

		CASE;
		pr(xnodes - k);

		for (i = 0; i <= 2 * n; i++)
		{
			A[i].cl;
			G[i].cl;
			graph[i].cl;
			trans[i].cl;
		}
	}

	return 0;
}