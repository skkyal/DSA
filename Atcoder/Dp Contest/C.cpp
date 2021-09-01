#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class triple{
public:
	ll x,y,z;
};


/*ll func(vector<vector<ll>>&a,ll n,ll p,vector<vector<ll>>&dp){
	if(n==-1) return 0;
	if(dp[n][p]!=-1) return dp[n][p];

	ll ans=0;

	for(ll i=0;i<3;i++){
		if(p!=i) ans=max(ans,a[n][i]+func(a,n-1,i,dp));
	}

	return dp[n][p]=ans;
}*/

ll max(ll a,ll b,ll c){
	return max(a,max(b,c));
}

void solve(){
	ll n;
	cin>>n;

	vector<vector<ll>>a(n,vector<ll>(3));
	vector<vector<ll>>dp(n,vector<ll>(3,0));

	for(ll i=0;i<n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
	}

	dp[0][0]=a[0][0],dp[0][1]=a[0][1],dp[0][2]=a[0][2];

	for(ll i=1;i<n;i++){
		dp[i][0]=a[i][0]+max(dp[i-1][1],dp[i-1][2]);
		dp[i][1]=a[i][1]+max(dp[i-1][0],dp[i-1][2]);
		dp[i][2]=a[i][2]+max(dp[i-1][1],dp[i-1][0]);
	}
	cout<<max(dp[n-1][0],dp[n-1][1],dp[n-1][2]);
}
 

void ipop(){
	#ifndef ONLINE_JUDGE
		freopen("../input.txt","r",stdin);
		freopen("../op.txt","w",stdout);
	#endif
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