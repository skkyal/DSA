#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n;cin>>n;

	vector<pair<ll,ll>>a(n);
	for(ll i=0;i<n;i++) cin>>a[i].first>>a[i].second;

	sort(a.begin(),a.end());

	ll ans=0,t=0;
	for(ll i=0;i<n;i++){
		t+=a[i].first;
		ans+=(a[i].second-t);
	}

	cout<<ans;
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