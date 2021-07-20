#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n,x;
	cin>>n>>x;

	vector<ll>a(n);
	for(ll i=0;i<n;i++) cin>>a[i];

	map<ll,pair<ll,ll>>m;
	
	for(ll i=0;i<n;i++) for(ll j=i+1;j<n;j++) m[a[i]+a[j]]={i+1,j+1};

	for(ll i=0;i<n;i++){
		for(ll j=i+1;j<n;j++){
			ll s=a[i]+a[j];

			if(m.find(x-s)!=m.end()){
				ll p=m[x-s].first,q=m[x-s].second;

				if(i+1!=p && i+1!=q && j+1!=q && j+1!=p){
					cout<<i+1<<" "<<j+1<<" "<<p<<" "<<q;
					return;
				}
				//else m[s]=make_pair(i+1,j+1);
			}
			//else
			//m[s]=make_pair(i+1,j+1);
		}
	}	
	cout<<"IMPOSSIBLE";

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