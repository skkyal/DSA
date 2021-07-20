#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll func(vector<ll>&a,ll l,ll r,vector<vector<ll>>&dp){
	if(l>r) return 0;
	if(dp[l][r]!=-1) return dp[l][r];
	return dp[l][r]=max(
		a[l]+min(func(a,l+1,r-1,dp),func(a,l+2,r,dp)),
		a[r]+min(func(a,l+1,r-1,dp),func(a,l,r-2,dp))
		);
}

void solve(){
	ll n;cin>>n;

	vector<ll>a(n);
	for(ll i=0;i<n;i++) cin>>a[i];

	vector<vector<ll>>dp(n,vector<ll>(n,-1));
	cout<<func(a,0,n-1,dp);
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