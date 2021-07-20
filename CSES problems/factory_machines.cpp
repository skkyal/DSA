#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n,t;
	cin>>n>>t;
	vector<ll>a(n);

	for(ll i=0;i<n;i++) cin>>a[i];

	ll l=0,h=1e18,m,ans=0;

	while(l<=h){
		m=l+(h-l)/2;
		ll sum=0;

		for(ll i=0;i<n;i++){
			sum+=m/a[i];

			if(sum>=t) break;
		}
		if(sum>=t){
			ans=m;
			h=m-1;
		}
		else l=m+1;

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