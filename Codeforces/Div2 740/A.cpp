#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n; cin>>n;
	vector<ll>a(n);

	for(ll i=0;i<n;i++) cin>>a[i];

	ll ans=0,it=0;
	
	while(++it){

		int f=0;
		for(ll i=1;i<n;i++){
			if(a[i-1]>a[i])
				f=1;
		}

		if(f==0) break;

		ll st;
		if(it%2==0) st=1;
		else st=0;
		for(ll i=st;i<n;i+=2){
			if(i+1<n && a[i]>a[i+1]){
				swap(a[i],a[i+1]);
			}
		}

		//for(ll i=0;i<n;i++){cout<<a[i]<<" ";}cout<<"\n";
	}

	cout<<it-1<<"\n";
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