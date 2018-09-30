#include<bits/stdc++.h>
using namespace std;

#define file freopen("input.txt", "r", stdin);
#define CLOCK printf("time: %lld ms\n",(long long)clock()*1000/CLOCKS_PER_SEC);

struct Suffix
{
	int index;
	int rank[22];
};

bool cmp(Suffix a, Suffix b)
{
	for(int i=0 ; i<22 ; i++)
		if(a.rank[i]==b.rank[i])	continue;
		else						return a.rank[i]<b.rank[i];
	
	return 0;
}

int a[100001], n;
Suffix suffix[100001];
void SuffixArray(string s)
{
	n=s.length();
	
	for(int i=0 ; i<n ; i++)
	{
		suffix[i].index=i;
		suffix[i].rank[0]=s[i]-'a';
	}
	
	for(int i=1 ; (1<<i)<n ; i++)
	{
		for(int j=0 ; j<n ; j++)
		{
			if(j+(1<<(i-1))<n)
			suffix[j].rank[i]=suffix[j+(1<<(i-1))].rank[i-1];
			else
			suffix[j].rank[i]=-1;
		}
	}
	
	sort(suffix, suffix+n, cmp);
	
	for(int i=0 ; i<n ; i++)//just copying to a 1D array for simplification
	a[i]=suffix[i].index;
}

int main()
{
	SuffixArray("banana");
	
	for(int i=0 ; i<n ; i++)
	{
		cout<<suffix[i].index<<"\t";
		
		for(int j=0 ; (1<<j)<n ; j++)
		cout<<suffix[i].rank[j]<<"\t";
		cout<<endl;
	}
	
	cout<<"array : ";
	for(int i=0 ; i<n ; i++)
	cout<<a[i]<<" ";
}

