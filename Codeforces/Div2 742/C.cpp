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

void solve(){
	ll n;
	cin>>n;

	ll a=0,b=0,c=0,p=1,q=1;

	while(n>0){
		if(c==0) {a=a+(n%10)*q;q*=10;}
		else {b=b+(n%10)*p;p*=10;}
		n=n/10;
		c=c^1;
	}
	//cout<<a<<" "<<b<<" ";
	cout<<(a+1)*(b+1)-2;
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