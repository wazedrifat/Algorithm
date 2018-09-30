//	0/1 Knapsack problem
if(TotalWeight < weight[i])
	dp[i][TotalWeight]=dp[i-1][TotalWeight];
else
	dp[i][TotalWeight]=max(value[i]+dp[i-1][ TotalWeight-weight[i] ], dp[i-1][TotalWeight]);
	

//	Longest Common Subsequence
if(str[i]==str[j])
	dp[i][j]=1 + dp[i-1][j];
else
	dp[i][j]=max( dp[i-1][j], dp[i][j-1] );


//	Matrix Chain Multiplication
for(int i=0 ; i<limit ; i++)
dp[i][i]=0;

dp[i][j]=min( dp[i][k] + dp[k+1][j] );


//	Subset Sum Problem
if(Total < value[i])
	dp[i][Total] = dp[i-1][Total];
else
	dp[i][Total] = dp[i-1][ Total-value[i] ] || dp[i-1][Total];
	

//	Optimal Binary Search Tree






