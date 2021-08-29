#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void ipop(){
	#ifndef ONLINE_JUDGE
		freopen("../input.txt","r",stdin);
		freopen("../op.txt","w",stdout);
	#endif
}

void solve(){
	ll n;
	cin>>n;

	vector<ll>a(n);
	for(ll i=0;i<n;i++) cin>>a[i];
	for(ll i=0;i<n;i++) a[i]-=i;

	unordered_map<ll,ll>m;
	for(ll i=0;i<n;i++) m[a[i]]++;

	for(auto it=m.begin();it!=m.end();it++){
		if(it->second==n){
			cout<<n;
		}
		else{
			cout<<1;
		}
		break;
	}

	cout<<"\n";

}
 

int main() {
	ipop();

	int t=1,x=1;
	cin>>t;
	while(t--){
		//cout<<"Case #"<<x<<":"<<" ";x++;
		solve();
	}
}