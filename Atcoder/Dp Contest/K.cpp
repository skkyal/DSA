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
	ll n,k;
	cin>>n>>k;

	vector<ll>a(n),dp(k+1,0);
	for(ll i=0;i<n;i++)	cin>>a[i];

	for(ll i=1;i<=k;i++){
		for(ll j=0;j<n;j++){
			if(i-a[j]>=0 && dp[i-a[j]]==0)
				dp[i]=1;
		}
	}

	cout<<(dp[k]==1?"First":"Second");
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