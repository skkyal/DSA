#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n;
	cin>>n;

	vector<ll>a(n);
	for(ll i=0;i<n;i++) cin>>a[i];

	sort(a.begin(),a.end());

	ll l=0,r=n-1,ans=0,s=0;
	while(l<r && a[r]>=s+a[l]){
		s+=a[l];
		l++;
	}
	//cout<<s<<" "<<l<<" ";
	ans=a[r];
	for(ll i=r;i>=l;i--) ans+=a[i];
	//cout<<ans<<" ";
	if(l<r){
		s=s+a[l];
		ll sum=s;
		for(ll i=l+1;i<=r;i++) sum+=a[i];
		ans=min(sum,ans);
		//cout<<sum<<" ";
	}

	

	cout<<ans;
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