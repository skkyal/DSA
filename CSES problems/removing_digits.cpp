#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(int a,int x){
	while(a>0){
		int y=a%10;
		if(y==x) return true;

		a=a/10;
	}
	return false;
}
void solve(){
	ll n;cin>>n;

	vector<ll>dp(n+1,INT_MAX);
	dp[0]=0;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=9;j++){
			if(check(i,j) && i-j>=0){
				dp[i]=min(dp[i],1+dp[i-j]);
			}
		}
		//cout<<dp[i]<<" ";
	}

	cout<<dp[n];
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