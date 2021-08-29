#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void ipop(){
	#ifndef ONLINE_JUDGE
		freopen("../input.txt","r",stdin);
		freopen("../op.txt","w",stdout);
	#endif
}

void solve(){
	ll c,d;
	cin>>c>>d;

	ll x,y;
	x=min(c,d);
	y=max(c,d);

	ll diff=y-x;

	if(diff%2==1){
		cout<<-1<<"\n";
		return;
	}

	if(x==y){
		if(x==0) cout<<0<<"\n";
		else cout<<1<<"\n";
		return;
	}

	cout<<2<<"\n";
}
 

int main() {
	ipop();

	int t=1,x=1;
	cin>>t;
	while(t--){
		//cout<<"Case #"<<x<<":"<<" ";x++;
		solve();
	}
}