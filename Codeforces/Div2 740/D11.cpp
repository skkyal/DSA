#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



ll func(ll n,ll &m,vector<ll>&dp){
	if(n==0) return 0;
	if(n==1) return 1;

	if(dp[n]!=-1) return dp[n];

	ll ans=0;
	for(ll i=n-1;i>=1;i--)
		ans=(ans%m+(func(i,m,dp))%m)%m;

	for(ll i=2;i<=n;i++)
		ans=(ans%m+(func(n/i,n,dp))%m)%m;

	return dp[n]=(ans%m);
}

void solve(){
	ll n,m;
	cin>>n>>m;
	vector<ll>dp(n+1,-1);
	cout<<(func(n,m,dp)%m)<<"\n";
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