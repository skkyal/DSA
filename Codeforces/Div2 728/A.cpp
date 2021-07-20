#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n;
	cin>>n;

	vector<ll>a(n);

	for(ll i=0;i<n;i++) a[i]=i+1;

	for(ll i=0;i<n;i+=2)
		if(i+1<n)
		swap(a[i],a[i+1]);

	if(n%2==1) swap(a[n-1],a[n-2]);

	for(ll i=0;i<n;i++) cout<<a[i]<<" ";

	cout<<"\n";
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