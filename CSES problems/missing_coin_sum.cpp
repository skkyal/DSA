#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n;cin>>n;

	vector<int>a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	
	ll sum=0;

	for(int i=0;i<n;i++){
		if(a[i]>sum+1){
			cout<<sum+1;
			return;
		}
		sum+=a[i];
	}
	cout<<sum+1;
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