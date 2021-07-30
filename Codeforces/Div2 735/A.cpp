#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n;
	cin>>n;

	vector<ll>a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	ll ans=0;
	for(ll i=1;i<n;i++)
		ans=max(ans,a[i]*a[i-1]);

	for(ll i=0;i<n-1;i++)
		ans=max(ans,a[i]*a[i+1]);

	cout<<ans<<"\n";
}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("op.txt","w",stdout);
	#endif
	
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
}