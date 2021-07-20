#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll func(vector<ll>&a,ll n,ll s){

	if(s==0) return 1;
	if(n==0) return INT_MAX;

	if(s-a[n-1]<0)
		return func(a,n-1,s);
	return min(1+func(a,n,s-a[n-1]),func(a,n-1,s));
}

void solve(){
	ll n,s;
	cin>>n>>s;

	vector<ll>a(n);
	for(ll i=0;i<n;i++) cin>>a[i];

	vector<ll>dp(s+1,INT_MAX);
	dp[0]=0;

	for(ll i=1;i<=s;i++){
		for(ll j=0;j<n;j++){
			if(i-a[j]>=0)
				dp[i]=min(dp[i],1+dp[i-a[j]]);
		}
		//cout<<dp[i]<<" ";
	}
	
	if(dp[s]==INT_MAX) dp[s]=-1;
	cout<<dp[s];

	//cout<<func(a,n,s);
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