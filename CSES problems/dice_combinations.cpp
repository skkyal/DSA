#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m=1e9+7;



void solve(){
	ll n;cin>>n;

	ll a[n+1]={0};
	a[0]=1;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=6 && i-j>=0;j++)
			a[i]+=a[i-j]%m;
	}
	cout<<a[n]%m;
}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("op.txt","w",stdout);
	#endif
	
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}