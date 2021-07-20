#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int func(string a,string b,int n,int m,vector<vector<int>>&dp){
	if(n==0 && m==0) return 0;
	if(n==0) return m;
	if(m==0) return n;

	if(dp[n][m]!=-1) return dp[n][m];
	if(a[n-1]==b[m-1]){
		return dp[n][m]=func(a,b,n-1,m-1,dp);
	}

	return dp[n][m]=1+min(func(a,b,n-1,m-1,dp),min(func(a,b,n-1,m,dp),func(a,b,n,m-1,dp)));
}

void solve(){
	string a,b;
	cin>>a>>b;

	int n=a.size(),m=b.size();
	vector<vector<int>>dp(n+1,vector<int>(m+1,0));

	for(ll i=0;i<=n;i++){
		for(ll j=0;j<=m;j++){
			if(i==0) dp[i][j]=j;
			else if(j==0) dp[i][j]=i;

			else if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
			else dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
		}
	}
	cout<<dp[n][m];
}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("op.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}