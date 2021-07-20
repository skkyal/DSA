#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll N;cin>>N;
	ll ans=0;

	for(ll i=1;i<=N;i++){
		ll x=2*N-(i*(i-1));
		if(x<=0) break;
		if(x>0 && x%(2*i)==0) {
			//cout<<i<<" "<<x/(2*i)<<"|";
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
	
	int t=1,x=1;
	cin>>t;
	
	while(t--){
		cout<<"Case #"<<x<<":"<<" ";
		x++;
		solve();
	}
}