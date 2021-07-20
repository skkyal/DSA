#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n;
	cin>>n;

	ll x=sqrt(n);
	if(x*x==n) cout<<x<<"\n";
	else cout<<x+1<<"\n";
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