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
	ll n;cin>>n;

	vector<ll>a(n);
	for(ll i=0;i<n;i++) cin>>a[i];

	vector<ll>dp(n,0);

	for(ll i=1;i<n;i++){
		ll x=INT_MAX,y=INT_MAX;
		if(i-1>=0)	x=abs(a[i]-a[i-1])+dp[i-1];
		if(i-2>=0)  y=abs(a[i]-a[i-2])+dp[i-2];

		dp[i]=min(x,y);
	}
	cout<<dp[n-1];

}
 

int main() {
	ipop();

	int t=1,x=1;
	//cin>>t;
	while(t--){
		//cout<<"Case #"<<x<<":"<<" ";x++;
		solve();
	}
}