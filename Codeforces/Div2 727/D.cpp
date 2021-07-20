#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


bool static comp(pair<ll,ll>&a,pair<ll,ll>&b){
	return a.second<b.second;
}

void solve(){
	ll n;cin>>n;
	vector<pair<ll,ll>>a(n);

	for(ll i=0;i<n;i++) cin>>a[i].first>>a[i].second;

	sort(a.begin(),a.end(),comp);

//	for(ll i=0;i<n;i++) cout<<a[i].first<<" "<<a[i].second<<"\n";

	ll l=0,r=n-1,ans=0,m=0;

	while(l<=r){
		if(a[l].second<=m){
			ans+=a[l].first;
			m+=a[l].first;
			l++;
			//cout<<ans<<" ";

			continue;
		}

		if(a[l].second>=(a[r].first+m)){
			//a[l].second=a[l].second-a[r].first;
			ans+=a[r].first*2;
			m+=a[r].first;
			r--;
		}
		else{
			ans+=(a[l].second-m)*2;
			a[r].first=a[r].first-(a[l].second-m);

			m=a[l].second;
			//a[l].second=0;

		}
		//cout<<ans<<" ";

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