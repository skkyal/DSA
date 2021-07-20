#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(vector<ll>&a){
	ll n=a.size();
	for(ll i=0;i<n;i++){
		for(ll j=i+1;j<n;j++){
			for(ll k=j+1;k<n;k++){
				if((a[i]<=a[j] && a[j]<=a[k]) || (a[i]>=a[j] && a[j]>=a[k]))
					return true;
			}
		}
	}

	return false;
}

void solve(){
	ll n,ans=0;cin>>n;
	vector<ll>a(n);

	for(ll i=0;i<n;i++) cin>>a[i];

	for(ll i=0;i<n;i++){
		vector<ll>b;
		for(ll j=i;j<n;j++){
			b.push_back(a[j]);
			if(check(b)) break;
			ans++;
		}
	}

	cout<<ans<<"\n";
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