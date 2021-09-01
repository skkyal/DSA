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
	ll n,m,mod=1e9+7;
	cin>>n>>m;

	vector<string>a(n);

	for(ll i=0;i<n;i++) cin>>a[i];

	vector<vector<ll>>dp(n,vector<ll>(m,0));

	ll f1=0,f2=0;

	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++){
			if(i==0){
				if(a[i][j]=='#') f1=1;
				dp[i][j]=(f1==1?0:1);
			}
			else if(j==0){
				if(a[i][j]=='#') f2=1;
				dp[i][j]=(f2==1?0:1);
			}
			else if(a[i][j]=='#') dp[i][j]=0;
			else dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
		}
	}

	/*for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}*/

	cout<<(dp[n-1][m-1]%mod);
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