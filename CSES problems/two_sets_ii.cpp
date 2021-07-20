#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll func(ll n,ll m,ll sum){
	if(sum==0) return 1;
	if(n==0) return 0;
	return (func(n-1,m,sum)%m+func(n-1,m,sum-n)%m)%m;
}

void solve(){
	ll n,m=1e9+7;cin>>n;
	ll sum=n*(n+1)/2;
	if(sum%2==1) {
		cout<<0;
		return;
	}
	sum=sum/2;
	
	vector<vector<ll>>dp(n+1,vector<ll>(sum+1,0));
	dp[0][0]=1;
	for(ll i=1;i<n;i++){
		for(ll j=0;j<=sum;j++){
			if(j-i>=0)
				dp[i][j]=(dp[i-1][j]%m+dp[i-1][j-i]%m)%m;
			else dp[i][j]=dp[i-1][j]%m;
		}
	}
	cout<<dp[n-1][sum];
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