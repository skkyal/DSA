#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void ipop(){
	#ifndef ONLINE_JUDGE
		freopen("../input.txt","r",stdin);
		freopen("../op.txt","w",stdout);
	#endif
}

long double func(vector<long double>&a,ll n,ll d,vector<vector<long double>>&dp){
	if(n==-1) return 1.0;

	if(dp[n][d]!=-1.0)	return dp[n][d];
	if(d==0) return dp[n][d]=a[n]*func(a,n-1,d,dp);
	return dp[n][d]=a[n]*func(a,n-1,d,dp)+(1.0-a[n])*func(a,n-1,d-1,dp);
}
void solve(){
	ll n;
	cin>>n;

	vector<long double>a(n);
	vector<vector<long double>>dp(n+1,vector<long double>(n,1.0));

	for(ll i=0;i<n;i++) cin>>a[i];

	for(ll i=1;i<=n;i++){
		for(ll j=0;j<=n/2;j++){
			if(j==0)
				dp[i][j]=a[i-1]*dp[i-1][j];
			else 
				dp[i][j]=a[i-1]*dp[i-1][j]+(1.0-a[i-1])*dp[i-1][j-1];
		}
	}

	/*for(ll i=1;i<=n;i++){
		for(ll j=0;j<=n/2;j++) cout<<dp[i][j]<<" ";
			cout<<"\n";
	}*/
	cout<<fixed<<setprecision(10)<<dp[n][n/2];//func(a,n-1,n/2,dp);
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