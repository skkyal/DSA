
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n;cin>>n;
	vector<ll>a(n);

	for(ll i=0;i<n;i++) cin>>a[i];

	ll sum=0;
	for(ll i=0;i<n;i++) sum+=a[i];

	ll x=sum/n,y=sum%n;

	sort(a.begin(),a.end());

	ll z=n-y;
	cout<<z*y<<"\n";


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