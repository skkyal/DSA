#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll check(ll n,ll p){
	ll ans=0;

	while(n>0 && n%p==0){
		ans++;
		n=n/p;
	}

	return ans;
}

ll func(ll s,ll l,ll r,vector<ll>&a,ll p,vector<vector<ll>>&bin){
	ll ans=0;
	for(ll i=l;i<=r;i++){
		ll x=bin[a[i]][s]-((a[i]%p==0)?0:bin[a[i]%p][s]);
		ans+=check(x,p);
	}
	return ans;
}

void solve(){
	ll n,q,p;
	cin>>n>>q>>p;

	ll N=1001;
	vector<vector<ll>>bin(N,vector<ll>(5,0));

	for(ll i=1;i<=N;i++)
		for(ll j=1;j<=4;j++)
			bin[i][j]=binpow(i,j);

	vector<ll>a(n);
	for(ll i=0;i<n;i++) cin>>a[i];

	for(ll i=0;i<q;i++){
		ll x;cin>>x;
		if(x==1){
			ll pos,val;
			cin>>pos>>val;
			a[pos-1]=val;
		}
		else{
			ll s,l,r;
			cin>>s>>l>>r;
			cout<<func(s,l-1,r-1,a,p,bin)<<" ";
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

