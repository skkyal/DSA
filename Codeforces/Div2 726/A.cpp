#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	ll n;cin>>n;

	vector<ll>a(n);
	for(ll i=0;i<n;i++) cin>>a[i];

	ll s=0;
	for(ll i=0;i<n;i++) s+=a[i];

	if(s==n) cout<<0<<"\n";
	else if(s>n) cout<<s-n<<"\n";
	else cout<<1<<"\n";	
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