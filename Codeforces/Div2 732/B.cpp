#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n,m;
	cin>>n>>m;
	vector<string>a(n),b(n-1);

	for(ll i=0;i<n;i++)	cin>>a[i];
	for(ll i=0;i<n-1;i++) cin>>b[i];
	string ans;
	for(ll i=0;i<m;i++){
		unordered_map<char,ll>m;
		for(ll j=0;j<n;j++) m[a[j][i]]++;
		for(ll j=0;j<n-1;j++) m[b[j][i]]--;

		for(auto it=m.begin();it!=m.end();it++){
			if(it->second==1) ans+=it->first;
		}
	}

	cout<<ans<<endl;
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