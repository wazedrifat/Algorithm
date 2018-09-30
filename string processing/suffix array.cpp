#include<bits/stdc++.h>
using namespace std;

#define file freopen("input.txt", "r", stdin);
#define CLOCK printf("time: %lld ms\n",(long long)clock()*1000/CLOCKS_PER_SEC);
#define MX 600004

int m, SA[MX], LCP[MX];
int suffix[MX], index[MX], cnt[MX], rank[MX];

inline bool cmp(const int a, const int b, const int l)
{
    return ( index[a]==index[b] && index[a+l]==index[b+l] );
}

void Sort(int len)
{
    for(int i=0 ; i<256 ; i++)	 	cnt[i]=0;
    for(int i=0 ; i<len ; i++) 		cnt[suffix[ index[i] ] ]++;
    for(int i=0 ; i<255 ; i++) 		cnt[i+1]+=cnt[i];
    for(int i=len-1 ; i>=0 ; i--)	SA[ --cnt[ suffix[ index[i] ] ] ]=index[i];
}

void kasaiLCP(string text)
{
	int len=text.length();
	
    for(int i=0 ; i<len ; i++)	rank[ SA[i] ]=i;
    
    LCP[len-1] = 0;
    
	for(int i=0, h=0 ; i<len ;i++)
	if(rank[i]>0)
    {
        int j=SA[ rank[i]-1 ];
        while( i+h<len && j+h<len && text[i+h]==text[j+h] )
		h++;
        
		LCP[ rank[i]-1 ]=h;
        
		if(h>0)		h--;
    }
}

void SuffixArray(string text)
{
    int len=text.length()+1;
    
    for(int i=0 ; i<len ; i++)	
	{
		suffix[i]=text[i];
		index[i]=i;
	}
	
    Sort(len);
    
    for(int i, j=1, p=1 ; p<len ; j<<=1, m=p)
    {
        for(p=0, i=len-j ; i<len ; i++) 
		index[p++] = i;
        
		for(int k=0 ; k<len ; k++) 
		if(SA[k]>=j) 
		index[p++]=SA[k]-j;
        
		Sort(len);
        
		swap(suffix, index);
        suffix[ SA[0] ]=0;
        
        for(p=1, i=1 ; i<len ; i++) 
		suffix[ SA[i] ]=cmp( SA[i-1], SA[i], j)	?	p-1 : p++;
    }
    
    for(int i=1 ; i<len ; i++) 
	SA[i-1]=SA[i];
    
    kasaiLCP(text);
}


int main()
{
	file
    string  s1, s2, text;
	cin>>text;
//	string text="banana";
    SuffixArray(text);
    CLOCK
    int n = text.size();
//    for(int i=0; i<n; i++)
//    {
//        cout << SA[i]  << " " << text.substr(SA[i]) << endl;
//    }
    
//    for(int i=0; i<n; i++)
//    {
//        cout<<i<<"  "<< LCP[i] << endl;
//    }
}
