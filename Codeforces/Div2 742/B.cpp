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

ll computeXOR(ll n)
{
  // If n is a multiple of 4
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}

void solve(){
	ll a,b;
	cin>>a>>b;

	ll ans=computeXOR(a-1);
	//for(ll i=0;i<a;i++) ans=ans^i;

	if(ans==b){
		cout<<a;
		return;
	}
	ll x=ans^b;

	if(x==a) cout<<a+2;
	else cout<<a+1;
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