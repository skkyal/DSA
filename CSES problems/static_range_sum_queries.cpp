#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n,m;
	cin>>n>>m;
	vector<ll>a(n+1,0);
	for(ll i=1;i<=n;i++){
		ll x;cin>>x;
		a[i]=a[i-1]+x;
	}

	for(ll i=0;i<m;i++){
		ll u,v;
		cin>>u>>v;
		cout<<a[v]-a[u-1]<<"\n";
	}
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