#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n,s;
	cin>>n>>s;
	ll m=1e9+7;
	vector<ll>a(n),dp(s+1,0);

	for(ll i=0;i<n;i++) cin>>a[i];
	dp[0]=1;
	sort(a.begin(),a.end());

	for(ll i=1;i<=s;i++){
		for(ll j=0;j<n;j++){
			if(i-a[j]>=0) 
				dp[i]=(dp[i]%m + dp[i-a[j]]%m)%m;
			else break;
		}
		//cout<<dp[i]<<" ";
	}
	cout<<dp[s];

}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("op.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}