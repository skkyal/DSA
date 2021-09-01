#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void ipop(){
	#ifndef ONLINE_JUDGE
		freopen("../input.txt","r",stdin);
		freopen("../op.txt","w",stdout);
	#endif
}

/*ll func(vector<vector<ll>>&a,ll n,ll w,vector<vector<ll>>&dp){
	if(n==-1) return 0;

	if(dp[n][w]!=-1) return dp[n][w];

	if(w>=a[n][0])
	return dp[n][w]=max(a[n][1]+func(a,n-1,w-a[n][0],dp),func(a,n-1,w,dp));

	return dp[n][w]=func(a,n-1,w,dp);
}*/

void solve(){
	ll n,w,v=0;
	cin>>n>>w;

	vector<vector<ll>>a(n+1,vector<ll>(2));

	for(ll i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1];
		v+=a[i][1];
	}
	
	vector<vector<ll>>dp(n+1,vector<ll>(v+1,w+1));

	
	//for(ll i=1;i<=n;i++){
	//for(ll i=0;i<=v;i++) dp[0][i]=0;
	dp[1][0]=0;
	dp[1][a[1][1]]=a[1][0];
	//}

	for(ll i=2;i<=n;i++){
		dp[i][0]=0;
		for(ll j=1;j<=v;j++){
			if(j>=a[i][1])
				dp[i][j]=min(a[i][0]+dp[i-1][j-a[i][1]],dp[i-1][j]);

			else dp[i][j]=dp[i-1][j];
		}
	}

	ll ans=0;

	for(ll i=v;i>=0;i--){
		if(dp[n][i]<=w){
			ans=i;
			break;
		}
	}

	cout<<ans;
	
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