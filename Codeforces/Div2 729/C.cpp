#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll countDivisibles(ll A, ll B, ll M){
    if (A % M == 0)
        return (long long)((B / M) - (A / M) + 1);

    return (long long)((B / M) - (A / M));
}

void solve(){
	ll n,mod=1e9+7;
	cin>>n;
	ll ans=0;
	ll t=n,prev=n,d=1;

	for(ll i=2;;i++){
		d=d*i/gcd(i,d);
		//cout<<d<<" ";
		ll x=countDivisibles(1,n,d);
		
		ans=((ans%mod)+((prev-x)%mod)*(i)%mod)%mod;
		//cout<<ans<<" ";
		prev=x;
		if(prev==0) break;
	}

	cout<<ans%mod<<"\n";
}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("op.txt","w",stdout);
	#endif
	
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
}