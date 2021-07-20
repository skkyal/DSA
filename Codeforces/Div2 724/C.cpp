#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n;cin>>n;
	string s;
	cin>>s;

	map<pair<ll,ll>,ll>m;
	ll a=0,b=0;
	for(ll i=0;i<n;i++){
		if(s[i]=='D') a++;
		else b++;

		ll c=__gcd(a,b);
		cout<<++m[make_pair((ll)a/c,(ll)b/c)]<<" ";
	}

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