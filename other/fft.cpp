#include <bits/stdc++.h>
using namespace std;

#define IN freopen("in.txt", "r", stdin);
#define OUT freopen("out.txt", "w", stdout);
#define CLOCK printf("time: %lld ms\n", (long long)clock() * 1000 / CLOCKS_PER_SEC);
#define LL long long int
#define MX 500001
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define max4(a, b, c, d) max(a, max3(b, c, d))
#define min4(a, b, c, d) min(a, min3(b, c, d))
#define EPS 1e-9
#define MOD 1000000007
#define PI 2.0 * acos(0.0)
#define PII pair <int, int>
#define Booster() ios_base::sync_with_stdio(false);	cin.tie(NULL);

typedef complex < double > base ;
 
//inv=0 means Converting from coefficient form to point value form
//inv=1 means Converting from point value  form to coefficient form i.e. inverse fft
void fft(vector<base> &a,bool inv)
{
    int n=(int)a.size();
    //rearranging the elements to the leaf nodes of the tree
    for(int i=1,j=0;i<n;i++){
        int bit=n>>1;
        for(;j>=bit;bit>>=1) j-=bit;
        j+=bit;
        if(i<j) swap(a[i],a[j]);
    }
    for(int len=2;len<=n;len*=2){
        long double ang=2*PI/len*(inv?-1:1);
        base wlen(cos(ang),sin(ang));
        //wlen=e^(2*PI*i/n)=cos(2*PI/n)+i*sin(2*PI/n)
        //bcz e^(i*theta)=cos(theta)+i*sin(theta)
        for(int i=0;i<n;i+=len){
            base w=1;
            for(int j=0;j<len/2;j++){
                base even=a[i+j],odd=a[i+j+len/2];
                a[i+j]=even+w*odd;
                a[i+j+len/2]=even-w*odd;
                w*=wlen;
            }
        }
    }
    if(inv) for(int i=0;i<n;i++) a[i]/=n;
}
vector <int> multiply(vector <int>& a,vector <int>& b)
{
    vector<base>fa(a.begin(), a.end()),fb(b.begin(), b.end());
    int n=1;
    int mx=max((LL)a.size(),(LL)b.size());
    while(n<mx) n*=2;//making it power of 2
    n*=2;//making 2*n size
    fa.resize(n);
    fb.resize(n);
    //convolution
    fft(fa,0);
    fft(fb,0);
    for(int i=0;i<n;i++) fa[i]*=fb[i];
    fft(fa,1);//inverse fft
    
	vector <int> res(n);
    for(int i=0;i<n;i++) res[i]=int(fa[i].real()+0.5);
    for(int i=0;i<n;i++) if(res[i]>1) res[i]=1;
    while(res.size()>1&&res.back()==0) res.pop_back();
    return res;
}

int main() {
	#ifndef ONLINE_JUDGE 
		IN OUT
	#endif
	
	vector <int> a{1, 2, 3, 4, 5, 6}, b{3, 4, 9, 10};

	vector <int> c = multiply(a, b);

	cout << "c.size() = " << c.size() << endl;
	cout << "c : ";
	for (auto i:c) {
		cout << i << " ";
	}
	cout << endl;
}