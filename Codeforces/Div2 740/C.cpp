#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n,k;cin>>n;
	vector<vector<ll>>a(n);

	for(ll i=0;i<n;i++){
		cin>>k;
		vector<ll>b(k);
		for(ll j=0;j<k;j++)
			cin>>b[j];

		ll ans=b[0]+1,x=ans;

		for(ll j=0;j<k;j++){
			if(x>b[j])
				x++;
			else{
				ans+=(b[j]-x)+1;
				x=b[j]+2;
			}
		}

		a[i]={ans,k};
		//cout<<ans<<" ";
	}

	sort(a.begin(),a.end());

	ll ans=0,x=0;

	for(ll i=0;i<n;i++){
		if(x>=a[i][0]){
			x+=a[i][1];
		}
		else{
			ans+=(a[i][0]-x);
			x=a[i][0]+a[i][1];
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