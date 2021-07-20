#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n,a,b;
	cin>>n>>a>>b;

	string s;
	cin>>s;

	ll ans=n*a;

	if(b>=0) {
		ans+=n*b;
		cout<<ans<<"\n";
		return;
	}

	ll x=0,y=0;
	for(ll i=0;i<n;i++){
		ll j=i;
		while(j<n && s[j]==s[i])
			j++;
		if(s[i]=='1') x++;
		else y++;
		i=j-1;
	}
	//cout<<x<<" "<<y<<" ";
	x=min(x,y);
	cout<<ans+(x+1)*b<<"\n";
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