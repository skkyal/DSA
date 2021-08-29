#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll x;
	cin>>x;

	ll y=64 - __builtin_clzll(x) - 1;
	cout<<y;
}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("../input.txt","r",stdin);
		freopen("../op.txt","w",stdout);
	#endif
	
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}