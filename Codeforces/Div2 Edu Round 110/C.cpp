#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	string s;
	cin>>s;

	ll n=s.size();

	ll ans=0,len=0,f=1;
	queue<ll>q;


	for(ll i=0;i<n;i++){
		if(a[i]=='?' && f==0){
			q.push(i);
			f=1;
		} 
		else{
			
		}


	}
}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("op.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
}