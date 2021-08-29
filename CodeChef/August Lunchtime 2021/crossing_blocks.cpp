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
	ll n;
	cin>>n;

	vector<ll>a(n);
	stack<ll>q;

	for(ll i=0;i<n;i++) cin>>a[i];

	q.push(n-1);
	
	for(ll i=n-2;i>=0;i--){
		ll x=q.top();
		if(i==0 && a[i]>=a[x])
			q.push(i);
		else if(a[i]>a[x]) 
			q.push(i);
	}

	ll x=q.top();
	if(x==0){
		cout<<q.size()-1<<"\n";
	}
	else cout<<-1<<"\n"; 
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