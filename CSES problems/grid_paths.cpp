#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n,m=1e9+7;cin>>n;

	vector<string>a(n);
	for(int i=0;i<n;i++) cin>>a[i];

	vector<vector<ll>>dp(n,vector<ll>(n,0));
	//dp[0][0]=1;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]=='.'){
				if(i==0 && j==0) dp[i][j]=1;
				else 
				dp[i][j]=((i-1>=0?dp[i-1][j]:0)%m+(j-1>=0?dp[i][j-1]:0)%m)%m;
			}
		}
	}

	cout<<dp[n-1][n-1]%m;
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