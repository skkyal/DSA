#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool static comp(vector<ll>&a,vector<ll>&b){
	return a[1]>b[1];
}
ll func(vector<vector<ll>>&a ,ll n,ll e,vector<ll>&dp){
	if(n==0) return 0;
	if(dp[n]!=-1) return dp[n];
	if(a[n-1][0]>e)
		return dp[n]=max(a[n-1][2]+func(a,n-1,a[n-1][1],dp),func(a,n-1,e,dp));
	return dp[n]=func(a,n-1,e,dp);
}
void solve(){
	ll n;cin>>n;
	vector<vector<ll>>a(n,vector<ll>(3));
	for(ll i=0;i<n;i++) cin>>a[i][0]>>a[i][1]>>a[i][2];

	vector<ll>dp(n+1,-1);
	sort(a.begin(),a.end(),comp);
	//for(int i=0;i<n;i++) cout<<a[i][0]<<a[i][1]<<a[i][2]<<"\n";
	cout<<func(a,n,0,dp);
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