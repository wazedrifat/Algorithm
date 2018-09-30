#include<bits/stdc++.h>
using namespace std;

int lps[1000005];//for prefix of suffix of pattern
vector<int>cnt;

void lps_array(string pattern)//time : o(n)
{
	int i=1, j=0;
	lps[0]=0;
	
	while( i<pattern.length() )
	{
		if(pattern[j]==pattern[i])
		{
			lps[i]=++j;
			i++;
		}
		else
			if(j)	j=lps[j-1];
			else	lps[i++]=0;
	}
}

int Search(string text, string pattern)//time : o(n)
{
	cnt.clear();
	lps_array(pattern);
	
	int i=0, j=0;//i for text & j for pattern
	while( i<text.length() )
	{
		if(pattern[j]==text[i])
		{
			i++;	j++;
		}
		
		if(j==pattern.length())
		{
			cnt.push_back(i-j);
			j=lps[j-1];
		}
		
		if(pattern[j]!=text[i])
			if(j)	j=lps[j-1];
			else	i++;
	}
	
	if(cnt.size())	return cnt[0];
	else 			return -1;
}

int main()
{
	string text="ABABDABACDABABCABAB";
    cout<<Search(text, "ABABCABAB")<<endl;
    
    text="bcabdabdababdababd";
    
    cout<<Search(text, "abdababd")<<endl;
    for(int i=0 ; i<cnt.size() ; i++)
    cout<<cnt[i]<<"  ";
}

