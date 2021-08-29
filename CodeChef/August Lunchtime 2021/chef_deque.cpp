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
	ll n,m;
	cin>>n>>m;

	vector<ll>a(n+1,0);
	for(ll i=1;i<=n;i++) cin>>a[i];

	for(ll i=1;i<n;i++) a[i]+=a[i-1];
	ll ans=INT_MAX;

	for(ll i=0;i<=n;i++){
		for(ll j=0;j<=i;j++){
	
			ll k= (j&i);
			if(k+i>=n) continue;

			ll x=a[n-i]-a[k];


			if(x!=0 && (x%m)==0){
				ll count=__builtin_popcountll(i);
				ans=min(ans,count);
			}
		}
	}
	cout<<(ans==INT_MAX?-1:ans)<<"\n";
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