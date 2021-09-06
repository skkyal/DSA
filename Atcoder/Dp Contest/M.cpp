#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;

void ipop(){
	#ifndef ONLINE_JUDGE
		freopen("../input.txt","r",stdin);
		freopen("../op.txt","w",stdout);
	#endif
}

/*ll func(vector<ll>&a,ll k,ll n,vector<vector<ll>>&dp){
	if(k<0 || (n==-1 && k>0)) return 0;
	if(n==-1) return 1;
	ll ans=0;

	if(dp[n][k]!=-1) return dp[n][k];

	for(ll i=0;i<=a[n];i++){
		ans=(ans%mod + func(a,k-i,n-1,dp)%mod)%mod;
	}

	return dp[n][k]=ans;
}*/

void solve(){
	ll n,k;
	cin>>n>>k;

	vector<ll>a(n);
	vector<vector<ll>>dp(n,vector<ll>(k+1,0));

	for(ll i=0;i<n;i++) cin>>a[i];

	for(ll i=0;i<=a[0] && i<=k;i++) dp[0][i]=1;

	for(ll i=1;i<n;i++){
		dp[i][0]=1;

		vector<ll>prefix_sum(k+1);
		prefix_sum[0]=dp[i-1][0];

		for(ll j=1;j<=k;j++)
			prefix_sum[j]=(dp[i-1][j]+prefix_sum[j-1])%mod;


		for(ll j=0;j<=k;j++){
			dp[i][j]=(prefix_sum[j]-(a[i]<j?prefix_sum[j-a[i]-1]:0) +mod)%mod;
		}
	}

	cout<<dp[n-1][k];	
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