#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void ipop(){
	#ifndef ONLINE_JUDGE
		freopen("../input.txt","r",stdin);
		freopen("../op.txt","w",stdout);
	#endif
}

void solve(){
	ll n,k;cin>>n>>k;

	vector<ll>a(n);
	for(ll i=0;i<n;i++) cin>>a[i];

	vector<ll>dp(n,INT_MAX);
	dp[0]=0;

	for(ll i=1;i<n;i++){
		ll x=INT_MAX;

		for(ll j=1;j<=k && i-j>=0;j++){	
			x=abs(a[i]-a[i-j])+dp[i-j];
			dp[i]=min(x,dp[i]);
		}
	}
	cout<<dp[n-1];
}
 

int main() {
	ipop();

	int t=1;
	//cin>>t;
	while(t--){
		//cout<<"Case #"<<x<<":"<<" ";x++;
		solve();
	}
}