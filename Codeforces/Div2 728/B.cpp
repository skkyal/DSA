#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n,ans=0;
	cin>>n;

	vector<ll>a(n);
	for(ll i=0;i<n;i++) cin>>a[i];

	vector<ll>v(2*n+1,-1);
	for(ll i=0;i<n;i++) v[a[i]]=i+1;

	//for(ll i=1;i<=2*n;i++) cout<<v[i]<<" ";cout<<"\n";

	for(ll i=1;i<=2*n;i++){

		if(v[i]==-1) continue;
		for(ll j=i*i;j<=2*n;j+=i){
			if(v[j/i]==-1) continue;

			if(i!=j/i && j==v[i]+v[j/i]) ans++;
		}
	}
	cout<<ans<<"\n";

}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("op.txt","w",stdout);
	#endif
	
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
}