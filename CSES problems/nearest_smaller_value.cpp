#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n;cin>>n;

	vector<ll>a(n);
	for(ll i=0;i<n;i++) cin>>a[i];

	stack<ll>q;

	for(ll i=0;i<n;i++){
		while(!q.empty() && a[i]<=a[q.top()-1]) q.pop();
		if(q.empty()) cout<<0<<" ";
		else cout<<q.top()<<" ";

		q.push(i+1);
	}
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