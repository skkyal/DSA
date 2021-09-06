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

ll func(vector<vector<ll>>&a,ll i,ll mask,vector<vector<ll>>&dp){
	ll ans=0,n=a.size();
	if(i==n) return 1;
	if(dp[i][mask]!=-1) return dp[i][mask];

	for(ll j=0;j<n;j++){
		if(mask & (1<<j) && a[i][j]==1)
			ans=(ans+func(a,i+1,mask^(1<<j),dp))%mod;
	}

	return dp[i][mask]=ans;
}

void solve(){
	ll n;cin>>n;
	vector<vector<ll>>a(n,vector<ll>(n));

	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			cin>>a[i][j];

	vector<vector<ll>>dp(n,vector<ll>(1<<n,-1));
	cout<<func(a,0,(1<<n)-1,dp);
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