#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n,x;
	cin>>n>>x;

	vector<pair<ll,ll>>a(n);
	for(ll i=0;i<n;i++) {
		cin>>a[i].first;
		a[i].second=i+1;
	}

	sort(a.begin(),a.end());

	for(ll i=0;i<n;i++){
		ll t=x-a[i].first;
		if(t<=0) continue;

		ll l=i+1,r=n-1;
		while(l<r){
			ll sum=a[l].first+a[r].first;
			if(sum==t) {
				cout<<a[i].second<<" "<<a[l].second<<" "<<a[r].second;
				return;
			}
			if(sum<t) l++;
			else r--;
		}
	}

	cout<<"IMPOSSIBLE"<<"\n";

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