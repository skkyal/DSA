#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll a,b;
	cin>>a>>b;

	vector<ll>ans;

	if(a==0 || b==0){
		if(a==0) a=b;
		if(a%2==0) ans.push_back(a/2);
		else {
			ans.push_back(a/2);
			ans.push_back(a/2+1);
		}
	}	
	else if(a==b){
		for(ll i=0;i<=a+b;i+=2)
			ans.push_back(i);
	}
	else{
		ll x=min(a,b),y=max(a,b);
		ll l=(x+1)<y ? 2*x+1+(y-(x+1))/2 : x+y;
		ll s = a+b-l;

		if((x%2==0 && y%2==0) || (x%2==1 && y%2==1)){
			for(ll i=s;i<=l;i+=2)
			ans.push_back(i);
		}
		else{
			for(ll i=s;i<=l;i++)
			ans.push_back(i);
		}
	}

	cout<<ans.size()<<"\n";

	for(ll i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}

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