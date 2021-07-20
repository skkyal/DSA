#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll a,b;
	cin>>a>>b;

	if(a==b) {
		cout<<0<<" "<<0<<"\n";
		return;
	}

	ll p=max(a,b),q=min(a,b);
	ll x=p-q;

	ll a1 =p/x*x,a2=q/x*x;
	ll b1=a1+x,b2=a2+x;

	/*ll ans1=LLONG_MAX,ans2=LLONG_MAX;
	if(p-a1==q-a2) ans1=p-a1;
	if(b1-p==b2-q) ans2=b2-p;*/

	ll ans1;
	if(p%x==0) ans1=0;
	else { ans1 = min(p-p/x*x,(p/x+1)*x-p);}

	cout<<x<<" "<<ans1<<"\n";
	
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