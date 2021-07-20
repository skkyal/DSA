#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n,m;
	cin>>n>>m;

	vector<pair<ll,ll>>a(n);
	for(ll i=0;i<n;i++) cin>>a[i].first>>a[i].second;

	vector<ll>s(m);
	for(ll i=0;i<m;i++) cin>>s[i];

	ll N=1001;
	vector<bool>v(N,0);

	for(ll i=0;i<n;i++){
		for(ll j=a[i].first;j<=a[i].second;j++){
			v[j]=true;
		}
	}

	for(ll i=0;i<m;i++){
		ll x=s[i];

		if(v[x]==true) {
			cout<<x<<" ";
			v[x]=false;
			continue;
		}
		else{
			ll p=x,q=x;
			while(p>=0 && v[p]!=true)
				p--;
			while(q<N && v[q]!=true)
				q++;

			ll ans=0;
			if(p==-1) ans=q;
			else if(q==N) ans=p;
			else{
				if((x-p)<=(q-x)) ans=p;
				else ans=q;
			}

			cout<<ans<<" ";
			v[ans]=false;
		}
	}

	cout<<"\n";

}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("op.txt","w",stdout);
	#endif
	
	int t,x=1;cin>>t;
	while(t--){
		cout<<"Case #"<<x<<":"<<" ";
		x++;
		solve();
	}
}