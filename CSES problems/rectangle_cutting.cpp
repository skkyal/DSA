#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll a,b;
	cin>>a>>b;

	ll dp[a+1][b+1];
	memset(dp,0,sizeof(dp));

	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			if(i==j) dp[i][j]=0;
			else{
				ll ans=1e8;
				for(int p=1;p<i;p++){
					ans=min(ans,1+dp[i-p][j]+dp[p][j]);
				}
				for(int p=1;p<j;p++){
					ans=min(ans,1+dp[i][j-p]+dp[i][p]);
				}
				dp[i][j]=ans;
			}
		}
	}
	cout<<dp[a][b];
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