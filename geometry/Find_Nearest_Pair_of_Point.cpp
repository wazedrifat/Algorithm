#include <bits/stdc++.h>
using namespace std;

#define IN freopen("in.txt", "r", stdin);
#define OUT freopen("out.txt", "w", stdout);
#define ll long long int
#define PII pair <int, int>
#define MX 100001

// time complexity : O(nlogn)

struct Point {
	double x, y;
};

bool cmp(Point a, Point b) {
	return a.x < b.x;
};

double dis(Point a, Point b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

int main() {
	int n;
	scanf("%d", &n);

	Point p[10000];

	for (int i = 0; i < n; i++)
	scanf("%lf%lf", &p[i].x, &p[i].y);

	sort(p, p + n, cmp);
	double mini = dis(p[0], p[1]);

	for (int i = 0; i < n; i++)
	for (int j = i + 1; j < n && (p[j].x - p[i].x)*(p[j].x - p[i].x) < mini; j++)
		if (dis(p[j], p[i]) < mini) 
			mini = dis(p[j], p[i]);

	mini = sqrt(mini);

	printf("%.4lf\n", mini);
}