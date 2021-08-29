#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

static bool mycomp(pair<ll,ll>&a,pair<ll,ll>&b){
	return abs(a.first-a.second)<abs(b.first-b.second);
}

void solve(){
	ll n;
	cin>>n;

	vector<pair<ll,ll>>a(n);

	for(ll i=0;i<n;i++) cin>>a[i].first>>a[i].second;

	sort(a.begin(),a.end(),mycomp);
	ll ans=0;

	for(ll i=1;i<n;i++){
		ans=max(ans,min(abs(a[i].first-a[i-1].first),abs(a[i].second-a[i-1].second)));
	}
	cout<<ans;
}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("../input.txt","r",stdin);
		freopen("../op.txt","w",stdout);
	#endif
	
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}