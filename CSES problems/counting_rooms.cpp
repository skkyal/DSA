#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(vector<string>&a,ll i,ll j,ll n,ll m){
	if(i<0 || j<0 ||i>=n ||j>=m || a[i][j]=='#')
		return;

	a[i][j]='#';
	dfs(a,i+1,j,n,m);
	dfs(a,i-1,j,n,m);
	dfs(a,i,j+1,n,m);
	dfs(a,i,j-1,n,m);
}

void solve(){
	ll n,m;
	cin>>n>>m;

	vector<string>a(n);
	for(ll i=0;i<n;i++) cin>>a[i];

	ll ans=0;

	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++){
			if(a[i][j]=='.'){
				dfs(a,i,j,n,m);
				ans++;
			}
		}
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