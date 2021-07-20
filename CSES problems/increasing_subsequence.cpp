#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n;cin>>n;

	vector<ll>a(n);
	for(ll i=0;i<n;i++) cin>>a[i];

	vector<ll>l;
	
	l.push_back(a[0]);
	for(ll i=1;i<n;i++){
		if(l[l.size()-1]<a[i]) l.push_back(a[i]);
		else{
			auto it=lower_bound(l.begin(),l.end(),a[i]);
			l[it-l.begin()]=a[i];
		}
	}

	cout<<l.size();
}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("op.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}