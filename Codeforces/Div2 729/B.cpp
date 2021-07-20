#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n,a,b,f=0;
	cin>>n>>a>>b;

	if(a==1){
		if(n==1 || (n-1)%b==0){
			cout<<"Yes"<<"\n";
		}
		else cout<<"No"<<"\n";
		return;
	}
	for(ll i=1;i<=n;i=i*a){
		if(i==n){
			f=1;
			break;
		}
		ll x=n-i;
		if(x%b==0){
			f=1;
			break;
		}
	}

	if(f==1) cout<<"Yes";
	else cout<<"No";
	cout<<"\n";
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