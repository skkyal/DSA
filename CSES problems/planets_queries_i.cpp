#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n,q;
	cin>>n>>q;

	vector<ll>a[n+1];
	for(ll i=1;i<=n;i++) {
		ll u;cin>>u;
		a[i].push_back(u);
	}

	ll x=0;
	vector<ll>vis(n+1,0);

	for(ll i=1;i<=n;i++){
		if(vis[i]!=0){
			x++;
			bfs()
		}
	}

	for(ll i=0;i<q;i++){

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