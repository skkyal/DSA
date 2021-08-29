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
	ll l,r;
	cin>>l>>r;

	if(l==r){
		cout<<0<<"\n";
		return;
	}

	ll ans=0;
	for(ll i=r;i<=r;i++){
		ll x=i/2+1;
		if(x>=l){
			ans=max(ans,i%x);
		}
		else{
			ans=max(ans,i%l);
		}
	}

	cout<<ans<<"\n";
}
 

int main() {
	ipop();

	int t=1,x=1;
	cin>>t;
	while(t--){
		//cout<<"Case #"<<x<<":"<<" ";x++;
		solve();
	}
}