#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define mod 1000000007

ll MAX=LLONG_MAX;
ll MIN=LLONG_MIN;

ld pdouble(ld a){cout<<fixed<<setprecision(10)<<a;}
ll max(ll a,ll b,ll c){return max(a,max(b,c));}

ld func1(vector<vector<ld>>&a,ll mask,ll j,ll &n){
	ll k=__builtin_popcountll(mask);

	ld ans =0;
	for(ll i=0;i<n;i++){
		if(mask & (1<<i))
			ans+=a[i][j];
	}

	return 2.0*ans/(1.0*k*(k-1.0));
}

ld func(vector<vector<ld>>&a,ll mask,ll &n,vector<ld>&dp){
	ll k=__builtin_popcountll(mask);
	if(n==k) return 1;

	if(dp[mask]>-0.9) return dp[mask];
 
	ld ans=0;

	for(ll j=0;j<n;j++){
		if(!(mask & (1<<j))){
			ll prev=mask^(1<<j);
			ans+=func(a,prev,n,dp)*func1(a,prev,j,n);
		}
	}

	return dp[mask]=ans;
}

void solve(){
	ll n;
	cin>>n;

	vector<vector<ld>>a(n,vector<ld>(n));
	vector<ld>dp(1<<n,-1);


	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			cin>>a[i][j];

	for(ll i=0;i<n;i++){	
		pdouble(func(a,(1<<i),n,dp));cout<<" ";
	}
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