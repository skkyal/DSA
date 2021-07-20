#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n,x;
	cin>>n;

	vector<ll>a(n);
	for(ll i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	ll ans=1;

	for(ll i=1;i<n;i++) if(a[i-1]!=a[i]) ans++;

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