#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


/*ll func(ll n,ll &m,vector<ll>&dp){
	if(n==0) return 0;
	if(n==1) return 1;

	if(dp[n]!=-1) return dp[n];

	ll ans=0;
	for(ll i=n-1;i>=1;i--)
		ans+=func(i,m,dp);

	ans+=func(n/2,m,dp);

	return dp[n]=ans;
}*/

void solve(){
	ll n,m;
	cin>>n>>m;

	vector<ll>dp(n+1,0);
	dp[0]=0,dp[1]=1;

	for(ll i=2;i<=n;i++){
		dp[i]=dp[i-1]+dp[i/2];
	}
	cout<<dp[n]<<"\n";
}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("op.txt","w",stdout);
	#endif
	
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}