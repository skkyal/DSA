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

ll m=998244353;
void solve(){
	ll n,maxi=0,sm=0;
	cin>>n;
	vector<ll>a(n);
	for(ll i=0;i<n;i++) {
		cin>>a[i];
		maxi=max(maxi,a[i]);
	}

	ll cm=0,cs=0;

	for(ll i=0;i<n;i++){
		if(a[i]==maxi) continue;
		if(a[i]>sm)	sm=a[i];
	}

	for(ll i=0;i<n;i++){
		if(a[i]==maxi) cm++;
		else if(a[i]==sm) cs++;
	}

	vector<ll>fact(n+1,1);
	for(ll i=2;i<=n;i++){
		fact[i]=((i%m)*(fact[i-1]%m))%m;
	}

	if(cm>1){
		cout<<fact[n];
		return;
	}
	else if(sm+1<maxi){
		cout<<0;
		return;
	}

	ll cr=n-cs-1;
	//if(cr==0){cout<<1;return;}

	ll ans=0,f=1;
	
	for(ll i=1;i<=cr;i++){
		f=(f*(cr+1-i))%m;

		ll calc = ((f%m)*(fact[cs+cr-i]%m))%m;
		//cout<<calc<<" ";
		ans = (ans%m + calc%m)%m;
		//cout<<ans<<" ";
	}

	//cout<<ans<<" ";
	ll res=(fact[n]%m-fact[n-1]%m-ans%m+2*m)%m;

	//while(res<0) res+=m;
	cout<<((res)%m);

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
	cin>>t;
	while(t--){
		//cout<<"Case #"<<x<<":"<<" ";x++;
		solve();
		cout<<"\n";
	}
}