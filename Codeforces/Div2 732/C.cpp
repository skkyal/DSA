#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n;
	cin>>n;

	vector<ll>a(n);
	for(ll i=0;i<n;i++) cin>>a[i];

	unordered_map<ll,pair<ll,ll>>m;
	for(ll i=0;i<n;i++){
		if(i%2==0)
			m[a[i]].first++;
		else
			m[a[i]].second++;
	}

	sort(a.begin(),a.end());

	for(ll i=0;i<n;i++){
		if(i%2==0)
			m[a[i]].first--;
		else
			m[a[i]].second--;
	}

	for(auto it=m.begin();it!=m.end();it++){
		if(it->second.first<0 || it->second.second<0){
			cout<<"NO"<<"\n";
			return;
		}
	}

	cout<<"YES"<<"\n";
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