#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n;
	cin>>n;

	ll o=0,e=0;

	for(ll i=0;i<2*n;i++){
		ll x;cin>>x;

		if(x%2==0) e++;
		else o++;
	}

	if(e==o) cout<<"Yes";
	else cout<<"No";
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