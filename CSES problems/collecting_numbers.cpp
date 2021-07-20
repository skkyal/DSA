#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n,x;cin>>n;
	vector<int>a(n+1);

	for(int i=0;i<n;i++) {
		cin>>x;
		a[x]=i+1;
	}

	int l=1,ans=1;
	for(int i=1;i<=n;i++){
		if(l>a[i]) ans++;
		l=a[i];
	}

	cout<<ans;
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