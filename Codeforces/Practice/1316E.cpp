#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define mod 1000000007

ll MAX=LLONG_MAX;
ll MIN=LLONG_MIN;

ll pdouble(ll a){cout<<fixed<<setprecision(10)<<a;}
ll max(ll a,ll b,ll c){return max(a,max(b,c));}

ll n,p;
ll func(vector<ll>&a,vector<vector<ll>>&s,ll i,ll mask,ll k){
	if(mask==0 && k==0) return 0;

	if(i==n) {
		if(mask!=0 || k!=0)
			return -1;
		return 0;
	}

	ll ans=0,x;

	if(k>0){
		x=func(a,s,i+1,mask,k-1);

		if(x!=-1)
		ans=a[i]+x;
	}

	for(ll j=0;j<p;j++){
		if(mask & (1<<j)){
			x=func(a,s,i+1,mask ^ (1<<j),k);
			if(x!=-1)
				ans=max(ans,x);
		}
	}

	x=func(a,s,i+1,mask,k);
	
	if(x!=-1)
	ans=max(ans,x);

	return ans;
}

void solve(){
	ll k;
	cin>>n>>p>>k;

	vector<ll>a(n);
	vector<vector<ll>>s(n,vector<ll>(p));

	for(ll i=0;i<n;i++) cin>>a[i];
	for(ll i=0;i<n;i++)
		for(ll j=0;j<p;j++)
			cin>>s[i][j];

	cout<<func(a,s,0,(1<<p),k);

}
 

void ipop(){
	#ifndef ONLINE_JUDGE
		freopen("../input.txt","r",stdin);
		freopen("../op.txt","w",stdout);
	#endif
}
int main() {
	ipop();

	int t=1,x=1;
	//cin>>t;
	while(t--){
		//cout<<"Case #"<<x<<":"<<" ";x++;
		solve();
		cout<<"\n";
	}
}