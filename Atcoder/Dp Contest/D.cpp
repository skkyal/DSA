#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void ipop(){
	#ifndef ONLINE_JUDGE
		freopen("../input.txt","r",stdin);
		freopen("../op.txt","w",stdout);
	#endif
}

/*ll func(vector<vector<ll>>&a,ll n,ll w,vector<vector<ll>>&dp){
	if(n==-1) return 0;

	if(dp[n][w]!=-1) return dp[n][w];

	if(w>=a[n][0])
	return dp[n][w]=max(a[n][1]+func(a,n-1,w-a[n][0],dp),func(a,n-1,w,dp));

	return dp[n][w]=func(a,n-1,w,dp);
}*/

void solve(){
	ll n,w;
	cin>>n>>w;

	vector<vector<ll>>a(n+1,vector<ll>(2));
	vector<vector<ll>>dp(n+1,vector<ll>(w+1,0));

	for(ll i=1;i<n+1;i++){
		cin>>a[i][0]>>a[i][1];
	}

	for(ll i=1;i<=n;i++){
		for(ll j=0;j<=w;j++){
			if(j>=a[i][0])
				dp[i][j]=max(a[i][1]+dp[i-1][j-a[i][0]],dp[i-1][j]);
			else dp[i][j]=dp[i-1][j];
		}
	}

	cout<<dp[n][w];
	//cout<<func(a,n-1,w,dp);
	
}
 

int main() {
	ipop();

	int t=1,x=1;
	//cin>>t;
	while(t--){
		//cout<<"Case #"<<x<<":"<<" ";
		//x++;
		solve();
	}
}