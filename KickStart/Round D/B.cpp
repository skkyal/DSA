#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n,c;
	cin>>n>>c;

	vector<ll>a(n),b(n);
	for(ll i=0;i<n;i++) cin>>a[i]>>b[i];

	vector<ll>f(1e4+2,0);
	ll ans=n;

	for(ll i=0;i<n;i++){
		if(a[i]==b[i])
			continue;
		f[a[i]+1]++;
		f[b[i]]--;
	}

	for(ll i=1;i<=1e4+1;i++) f[i]+=f[i-1];
	sort(f.begin(),f.end(),greater<ll>());

	for(ll i=0;i<=1e4+1 && i<c;i++){
		if(f[i]==0) break;
		ans+=f[i];
		f[i]=0;
	}
	cout<<ans<<"\n";
}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("op.txt","w",stdout);
	#endif
	
	int t,x=1;cin>>t;
	while(t--){
		cout<<"Case #"<<x<<":"<<" ";
		x++;
		solve();
	}
}