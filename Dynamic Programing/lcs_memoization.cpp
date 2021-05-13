#include <bits/stdc++.h>
using namespace std;

int lcsMemo(string& X,string& Y,int n,int m,int dp[][]){
	if(n==0 || m==0) 
		return 0;
	if(dp[n][m]!=-1) return dp[n][m];

	if(X[n-1]==Y[m-1]) return dp[n][m]=1+lcsMemo(X,Y,n-1,m-1,dp);
	else return dp[n][m]=max(lcsMemo(X,Y,n-1,m,dp),lcsMemo(X,Y,n,m-1,dp));
}

int int main(){
	string X = "ABCBDAB", Y = "BDCABA";
	int dp[X.length()+1][Y.length()+1];
	memset(dp, -1 , sizeof dp);
	
    cout <<lcs(X, Y, X.length(), Y.length(),dp);
    return 0;
}