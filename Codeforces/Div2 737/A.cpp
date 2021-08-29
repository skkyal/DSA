#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n,sum=0,x=0;
	cin>>n;
	vector<ll>a(n);
	vector<ll>b(n);
	for(ll i=0;i<n;i++) {
		cin>>a[i];
	}
	sort(a.begin(),a.end(),greater<ll>());

	for(ll i=0;i<n;i++) sum+=a[i];

	sum-=a[0];
	x+=a[0];
	
	double ans=(double)sum*1.0/(n-1) + (double)x*1.0/(1);
	for(ll i=1;i<n-1;i++){
		sum-=a[i];
		x+=a[i];
		double res = (double)sum*1.0/(n-i-1) + (double)x*1.0/(i+1);
		ans=max(ans,res);
	}
	cout << std::setprecision(9) << std::fixed<<ans<<"\n";

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