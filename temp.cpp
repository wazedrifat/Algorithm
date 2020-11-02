/***** Raf *****/
///#include <stdio.h>
///#include <iostream>
///#include <cstring>
///#include <cmath>
///#include <algorithm>
///#include <string>
///#include <vector>
///#include <map>
///#include <set>
///#include <queue>
///#include <cstdlib>
///#include <limits>
///#include <iostream>
///#include <sstream>
///#include <unordered_set>
///#include <unordered_map>
///#include <random>
#include <bits/stdc++.h>
///#include <bits/stdtr1c++.h>
///#include <ext/pb_ds/assoc_container.hpp>
///#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
///using namespace __gnu_pbds;
 
#define              MAX             500005
#define              mod             1000000007
#define              EPS             1e-9
#define              ull             unsigned long long
#define              ll              long long
#define              inf             INT_MAX
#define              pi              acos(-1.0)
#define              vi              vector<int>
#define              vl              vector<long long>
#define              pii             pair<int,int>
#define              pll             pair<long long,long long>
#define              mp              make_pair
#define              mem(a, v)       memset(a, v, sizeof (a))
#define              all(a)          a.begin(),a.end()
#define              rall(a)         a.rbegin(),a.rend()
#define              ff              first
#define              ss              second
#define              arsort(ar,n)    sort(ar,ar+n);
#define              vsort(v)        sort(v.begin(),v.end())
#define              vrev(v)         reverse(v.begin(),v.end())
#define              arrev(ar,n)     reverse(ar,ar+n)
#define              pb              push_back
#define              popb            pop_back
#define              booster()       ios_base::sync_with_stdio(0); cin.tie(0);
#define              read(f)         freopen(f, "r", stdin)
#define              scani(x)        scanf("%d",&x)
#define              scanl(x)        scanf("%I64d",&x)
#define              scand(x)        scanf("%lf",&x)
#define              scans(x)        scanf("%s",x)
#define              OUT(x)          printf("%d\n",x)
#define              OUTS(x)         printf("%d ",x)
#define              min3(a,b,c)     min(a,min(b,c))
#define              max3(a,b,c)     max(a,max(b,c))
#define              min4(a,b,c,d)   min(min(a,b),min(c,d))
#define              max4(a,b,c,d)   max(max(a,b),max(c,d))
#define              max5(a,b,c,d,e) max(max3(a,b,c),max(d,e))
#define              min5(a,b,c,d,e) min(min3(a,b,c),min(d,e))
 
#define              bitCheck(a,k)     ((bool)(a&(1<<(k))))
#define              bitOff(a,k)       (a&(~(1<<(k))))
#define              bitOn(a,k)        (a|(1<<(k)))
#define              bitFlip(a,k)      (a^(1<<(k)))
 
#define              POPCOUNT           __builtin_popcount
#define              POPCOUNTLL         __builtin_popcountll
#define              RIGHttmOST          __builtin_ctzll
#define              LEFttmOST(x)        (63-__builtin_clzll((x)))
 
#define scani2(a,b) scani(a) , scani(b)
#define scani3(a,b,c) scani(a), scani(b), scani(c)
#define scani4(a,b,c,d) scani(a), scani(b), scani(c), scani(d)
#define scani5(a,b,c,d,e) scani(a), scani(b), scani(c), scani(d) , scani(e)
#define rnd mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
/*********************Ordered Multiset*************************/
 
/*** Needs C++11 or C++14 ***/
/// Treap supporting duplicating values in set
/// Maximum value of treap * ADD must fit in long long
 
/*
 
struct Treap{ /// hash = 96814
    int len;
    const int ADD = 1000010;
    const int MAXVAL = 1000000010;
    tr1::unordered_map <long long, int> mp; /// Change to int if only int in treap
    tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> T;
    Treap(){
        len = 0;
        T.clear(), mp.clear();
    }
    inline void clear(){
        len = 0;
        T.clear(), mp.clear();
    }
    inline void insert(long long x){
        len++, x += MAXVAL;
        int c = mp[x]++;
        T.insert((x * ADD) + c);
    }
    inline void erase(long long x){
        x += MAXVAL;
        int c = mp[x];
        if (c){
            c--, mp[x]--, len--;
            T.erase((x * ADD) + c);
        }
    }
    /// 1-based index, returns the K'th element in the treap, -1 if none exists
    inline long long kth(int k){
        if (k < 1 || k > len) return -1;
        auto it = T.find_by_order(--k);
        return ((*it) / ADD) - MAXVAL;
    }
    /// Count of value < x in treap
    inline int count(long long x){
        x += MAXVAL;
        int c = mp[--x];
        return (T.order_of_key((x * ADD) + c));
    }
    /// Number of elements in treap
    inline int size(){
        return len;
    }
};
 
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;///*X.find_by_order();X.order_of_key();
template <class T> inline bool isLeap(T y) {return (y % 400 == 0) || (y % 100 ? y % 4 == 0 : false); }*/
template< class T > inline T gcd(T a, T b) { return (b) == 0 ? (a) : gcd((b), ((a) % (b))); }
template< class T > inline T lcm(T a, T b) { return ((a) / gcd((a), (b)) * (b)); }
template <class T> inline T BigMod(T Base,T power,T M=mod){if(power==0)return 1;if(power&1)return ((Base%M)*(BigMod(Base,power-1,M)%M))%M;
else{T y=BigMod(Base,power/2,M)%M;return (y*y)%M;}}
template <class T> inline T ModInv (T A,T M = mod){return BigMod(A,M-2,M);}
 
int fx[] = {-1,+0,+1,+0,+1,+1,-1,-1,+0};
int fy[] = {+0,-1,+0,+1,+1,-1,+1,-1,+0};
int day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 
/*********************** let the play begin() ***********************************/
  typedef complex < double > base ;
  const double PI = 2*acos( 0.0 );
 
void fft ( vector < base > & a, bool invert ) {
	int n = ( int ) a. size ( ) ;
 
	for ( int i = 1 , j = 0 ; i < n ; ++ i ) {
		int bit = n >> 1 ;
		for ( ; j >= bit ; bit >>= 1 )
			j -= bit ;
		j += bit ;
		if ( i < j )
			swap ( a [ i ] , a [ j ] ) ;
	}
 
	for ( int len = 2 ; len <= n ; len <<= 1 ) {
		double ang = 2 * PI / len * ( invert ? - 1 : 1 ) ;
		base wlen ( cos ( ang ) , sin ( ang ) ) ;
		for ( int i = 0 ; i < n ; i += len ) {
			base w ( 1 ) ;
			for ( int j = 0 ; j < len / 2 ; ++ j ) {
				base u = a [ i + j ] ,  v = a [ i + j + len / 2 ] * w ;
				a [ i + j ] = u + v ;
				a [ i + j + len / 2 ] = u - v ;
				w *= wlen ;
			}
		}
	}
	if ( invert )
		for ( int i = 0 ; i < n ; ++ i )
			a [ i ] /= n ;
}

void multiply ( const vector < int > & a, const vector < int > & b, vector < int > & res ) {
	vector < base > fa ( a. begin ( ) , a. end ( ) ) ,  fb ( b. begin ( ) , b. end ( ) ) ;
	size_t n = 1 ;
	while ( n < max ( a. size ( ) , b. size ( ) ) )  n <<= 1 ;
	n <<= 1 ;
	fa. resize ( n ) ,  fb. resize ( n ) ;
 
	fft ( fa, false ) ,  fft ( fb, false ) ;
	for ( size_t i = 0 ; i < n ; ++ i )
		fa [ i ] *= fb [ i ] ;
	fft ( fa, true ) ;
 
	res. resize ( n ) ;
	for ( size_t i = 0 ; i < n ; ++ i )
		res [ i ] = int ( fa [ i ] . real ( ) + 0.5 ) ;
    /*	int carry = 0 ;
	for ( size_t i = 0 ; i < n ; ++ i ) {
		res [ i ] + = carry ;
		carry = res [ i ] / 10 ;
		res [ i ] % = 10 ;
	}*/
}

int xx[MAX];

int main() {
	vector < int > a{2, 3, 5}, b{7, 10, 101}, c;
	multiply(a, b, c);

	cout << "c : ";
	for (auto i:c) {
		cout << i << " ";
	}
	cout << endl;
}	