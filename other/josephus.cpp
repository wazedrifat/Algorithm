#include <bits/stdc++.h>
using namespace std;

#define IN freopen("in.txt", "r", stdin);
#define OUT freopen("out.txt", "w", stdout);
#define ll long long int
#define PII pair <int, int>
#define MX 100001
#define EPS 1e-9
#define MOD 1000000007
#define PI 2.0 * acos(0.0)

int josephus(int n, int k) {
    return n > 1 ? (joseph(n-1, k) + k - 1) % n + 1 : 1;
}

int josephus(int n, int k) {
    int res = 0;
    for (int i = 1; i <= n; ++i)
      res = (res + k) % i;
    return res + 1;
}

int josephus(int n, int k) {
    if (n == 1)
        return 0;
    if (k == 1)
        return n-1;
    if (k > n)
        return (joseph(n-1, k) + k) % n;
    int cnt = n / k;
    int res = joseph(n - cnt, k);
    res -= n % k;
    if (res < 0)
        res += n;
    else
        res += res / (k - 1);
    return res;
}

int main() 
{
	
}