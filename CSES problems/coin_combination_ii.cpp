#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n,s,m=1e9+7;
	cin>>n>>s;
	
	vector<ll>a(n);

	for(ll i=0;i<n;i++) cin>>a[i];

	vector<vector<int>>dp(n+1,vector<int>(s+1,0));
	dp[0][0]=1;

	for(ll i=1;i<=n;i++){
		for(ll j=0;j<=s;j++){
			dp[i][j]=dp[i-1][j]%m;
			if(j-a[i-1]>=0)
			dp[i][j]=(dp[i][j]%m+dp[i][j-a[i-1]]%m)%m;
		}
	}
	cout<<dp[n][s];

}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("op.txt","w",stdout);
	#endif
	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}