#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	ll n,q;
	cin>>n>>q;
	string s;cin>>s;

	vector<pair<ll,ll>>a(q);

	for(ll i=0;i<q;i++) cin>>a[i].first>>a[i].second;

	vector<vector<ll>>f(n,vector<ll>(26,0));

	//cout<<s;

	for(ll i=0;i<n;i++){
		f[i][s[i]-'a']++;
	}

	for(ll i=1;i<n;i++){
		for(ll j=0;j<26;j++){
			f[i][j]+=f[i-1][j];
		}
	}


	for(ll i=0;i<q;i++){
		ll x=a[i].first-1,y=a[i].second-1;

		ll ans=0;
		if(x==0){
			for(ll j=0;j<26;j++){
				ans+=f[y][j]*(j+1);
			}
		}
		else{
			for(ll j=0;j<26;j++){
				ans+=(f[y][j]-f[x-1][j])*(j+1);
			}
		}

		cout<<ans<<"\n";
	}
}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("op.txt","w",stdout);
	#endif

	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//ios_base::sync_with_stdio(false);cin.tie(NULL);
	
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
}