#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll check(ll n,ll x){
	return n%x==0?n/x-1:n/x;
}

void solve(){
	ll n,k,x;
	cin>>n>>k>>x;

	vector<ll>a(n);
	for(ll i=0;i<n;i++) cin>>a[i];

	sort(a.begin(),a.end());

	vector<ll>diff;

	for(ll i=1;i<n;i++) {
		ll calc=(a[i]-a[i-1]);
		if(calc>x) {
			//cout<<calc<<" ";
			diff.push_back(calc);
		}
	}

	sort(diff.begin(),diff.end());

	ll ans=diff.size()+1;

	for(ll i=0;i<diff.size();i++){
		ll c= check(diff[i],x);
		//cout<<diff[i]<<" "<<c<<" | ";
		if(k>=c){
			ans--;
			k=k-c;
		}
		else break;
	}

	cout<<ans<<"\n";
}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("op.txt","w",stdout);
	#endif

	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//ios_base::sync_with_stdio(false);cin.tie(NULL);
	
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}