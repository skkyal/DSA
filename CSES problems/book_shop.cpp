#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n,s;cin>>n>>s;

	vector<int>a(n),b(n);

	for(ll i=0;i<n;i++) cin>>a[i];
	for(ll i=0;i<n;i++) cin>>b[i];

	vector<vector<int>>dp(n+1,vector<int>(s+1,0));
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=s;j++){
			if(j<a[i-1]) dp[i][j]=dp[i-1][j];
			else dp[i][j]=max(b[i-1]+dp[i-1][j-a[i-1]],dp[i-1][j]);
		}
	}
	//cout<<func(a,b,s,n-1,dp);
	cout<<dp[n][s];
}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("op.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}