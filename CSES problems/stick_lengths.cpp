#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	int n;cin>>n;

	vector<int>a(n);
	for(int i=0;i<n;i++) cin>>a[i];

	sort(a.begin(),a.end());

	int x=a[n/2];
	ll ans=0;
	for(int i=0;i<n;i++) ans+=1LL*abs(a[i]-x);

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