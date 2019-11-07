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

//	g one high low
#include <bits/stdc++.h>
using namespace std;

int A[] = {2, 0};
int B[] = {2, 9};
int n = 2;
int dp[20][2][2][220];
int visited[20][2][2][220];

bool isprime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int func(int pos, int high_flag, int low_flag, int sum) {

    if (pos == n) return isprime(sum);

    if (visited[pos][high_flag][low_flag][sum]) return dp[pos][high_flag][low_flag][sum];
    visited[pos][high_flag][low_flag][sum] = 1;

    int lo = low_flag ? A[pos] : 0;
    int hi = high_flag ? B[pos] : 9;
    int cnt = 0;
    for (int i = lo; i <= hi; i++) {
        cnt += func(pos+1, high_flag&(i==hi), low_flag&(i==lo), sum+i);
    }

    return dp[pos][high_flag][low_flag][sum] = cnt;
}


int main() {

    cout<<func(0,1,1,0);

}

//	one high
#include <bits/stdc++.h>
using namespace std;

int A[] = {2, 5, 9};
int n = 3;
int dp[20][2][220];
int visited[20][2][220];

bool isprime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int func(int pos, int high_flag, int sum) {

    if (pos == n) return isprime(sum);

    if (visited[pos][high_flag][sum]) return dp[pos][high_flag][sum];
    visited[pos][high_flag][sum] = 1;

    int lo = 0;
    int hi = high_flag ? A[pos] : 9;
    int cnt = 0;
    for (int i = lo; i <= hi; i++) {
        cnt += func(pos+1, high_flag&(i==hi), sum+i);
    }

    return dp[pos][high_flag][sum] = cnt;
}


int main() {

    cout<<func(0,1,0);

}

//	cheapest palindrome
const int MAX=2010;
char A[MAX];
int insrt[300], dlt[300];
int dp[MAX][MAX];
bool visited[MAX][MAX];

int call(int l, int r)
{
    if (l>=r) return 0;
    if (visited[l][r]) return dp[l][r];
    visited[l][r] = 1;

    int a=inf, b=inf, c=inf, d=inf;

    if (A[l]==A[r]) a=call(l+1, r-1);
    else
    {
        a=dlt[A[l]]+call(l+1, r);
        b=dlt[A[r]]+call(l, r-1);
        c=insrt[A[r]]+call(l, r-1);
        d=insrt[A[l]]+call(l+1, r);
    }

    return dp[l][r]=min(min(a, b), min(c, d));
}
int main() 
{
	
}