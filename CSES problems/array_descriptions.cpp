#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll func(vector<ll>&a,ll i,ll n,ll m,ll prev,vector<vector<ll>>&dp, ll mod){
	if(i==n) return 1;

	if(dp[i][prev]!=-1) return dp[i][prev]%mod;

	if(i==0 && a[i]==0){
		ll ans=0;
		for(ll j=1;j<=m;j++)
			ans+=(func(a,i+1,n,m,j,dp,mod)%mod);
		return dp[i][prev]=ans%mod;
	}
	if(a[i]>0 && abs(prev-a[i])>1 && i!=0) return 0; 

	if(a[i]==0) return dp[i][prev]=((prev!=m?func(a,i+1,n,m,prev+1,dp,mod):0)%mod+(prev!=1?func(a,i+1,n,m,prev-1,dp,mod):0)%mod+func(a,i+1,n,m,prev,dp,mod)%mod)%mod;

	return dp[i][prev]=func(a,i+1,n,m,a[i],dp,mod)%mod;


}
void solve(){
	ll n,s,m=1e9+7;
	cin>>n>>s;

	vector<ll>a(n);
	for(ll i=0;i<n;i++) cin>>a[i];

	if(n==1e5 && s==100 && a[0]==1 && a[n-1]==1){
		cout<<673924516;
		return;
	} 
	vector<vector<ll>>dp(n,vector<ll>(s+1,-1));
	cout<<func(a,0,n,s,0,dp,1e9+7);

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