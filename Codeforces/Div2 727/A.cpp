#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n,x,t;

	cin>>n>>x>>t;

	ll y=t/x;

	ll ans;
	if(y>=n-1)
		ans=(n)*(n-1)/2;
	else ans = y*(y+1)/2 + y*(n-1-y);

	cout<<ans<<"\n";
}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("op.txt","w",stdout);
	#endif

	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//ios_base::sync_with_stdio(false);cin.tie(NULL);
	
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
}