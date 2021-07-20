#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n;cin>>n;
	vector<ll>a(n);
	for(ll i=0;i<n;i++) cin>>a[i];

	ll ans=0,ma=0,f=0;
	for(ll i=0;i<n;i++){
		if(a[i]<0){
			cout<<"NO"<<"\n";
			return;
		}
		if(a[i]==0) f=1;
		ans=__gcd(ans,a[i]);
		ma=max(ma,a[i]);
	}

	cout<<"YES"<<"\n"<<ma/ans+1<<"\n";
	//if(f==1) cout<<0<<" "
	for(ll i=0;i<=ma;i+=ans) cout<<i<<" ";
		cout<<"\n";
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