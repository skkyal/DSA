#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void ipop(){
	#ifndef ONLINE_JUDGE
		freopen("../input.txt","r",stdin);
		freopen("../op.txt","w",stdout);
	#endif
}

ll func(vector<ll>&a,ll l,ll r,vector<vector<ll>>&dp){
	if(l>r) return 0;

	if(dp[l][r]!=LLONG_MIN) return dp[l][r];

	return dp[l][r]=max(
			a[l]-func(a,l+1,r,dp),
			a[r]-func(a,l,r-1,dp)
		);
}
void solve(){
	ll n;
	cin>>n;

	vector<ll>a(n);
	vector<vector<ll>>dp(n,vector<ll>(n,LLONG_MIN));

	for(ll i=0;i<n;i++) cin>>a[i];

	cout<<func(a,0,n-1,dp);
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