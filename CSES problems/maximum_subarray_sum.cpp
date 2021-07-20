#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	int n;cin>>n;

	vector<ll>a(n);
	for(int i=0;i<n;i++) cin>>a[i];

	ll sum=a[0],ans=a[0];

	for(int i=1;i<n;i++){
		if(sum<0) sum=0;
		sum+=a[i];
		if(sum>ans) ans=sum;
		
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