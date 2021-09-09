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
	string s;
	cin>>s;

	for(ll i=0;i<n-1;i++){
		if((s[i]=='a'&&s[i+1]=='b') || (s[i]=='b' && s[i+1]=='a') ){
			cout<<i+1<<" "<<i+2;
			return;
		}
	}
	cout<<-1<<" "<<-1;
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