#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n;
	cin>>n;
	vector<ll>a(n);
	for(ll i=0;i<n;i++) cin>>a[i];

	sort(a.begin(),a.end());

	ll i=0;
	while(i<n && a[i]==a[0])
		i++;

	cout<<n-i<<"\n";
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