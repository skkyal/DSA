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

ll func(vector<ll>&a,ll k,ll n,vector<vector<ll>>&dp){
	if(k<0 || (n==-1 && k>0)) return 0;
	if(n==-1) return 1;
	ll ans=0;

	if(dp[n][k]!=-1) return dp[n][k];

	for(ll i=0;i<=a[n];i++){
		ans=(ans%mod + func(a,k-i,n-1,dp)%mod)%mod;
	}

	return dp[n][k]=ans;
}

void solve(){
	ll n,k;
	cin>>n>>k;

	vector<ll>a(n);
	vector<vector<ll>>dp(n,vector<ll>(k+1,-1));

	for(ll i=0;i<n;i++)	cin>>a[i];

	cout<<func(a,k,n-1,dp);	
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