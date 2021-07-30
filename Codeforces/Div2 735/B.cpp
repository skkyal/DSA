#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n,k;
	cin>>n>>k;

	vector<ll>a(n+1);
	for(ll i=1;i<=n;i++)
		cin>>a[i];

	ll ans=LLONG_MIN,l=max(1LL*1,n-2*k);

	for(ll i=l;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			ans=max(ans,i*j-k*(a[i]|a[j]));
		}
	}

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