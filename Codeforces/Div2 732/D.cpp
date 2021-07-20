#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll power(ll x,ll y, ll p)
{
    ll res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0)
    {
     
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 
// Returns n^(-1) mod p
ll modInverse(ll n, ll p)
{
    return power(n, p - 2, p);
}
 
// Returns nCr % p using Fermat's little
// theorem.
ll nCrModPFermat(ll n,ll r, ll p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;
 
    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    ll fac[n + 1];
    fac[0] = 1;
    for (ll i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;
 
    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}

void solve(){
	ll n,mod=998244353;
	string s;
	cin>>n;
	cin>>s;

	ll a=0,b=0;
	for(ll i=0;i<n;i++){
		if(s[i]=='0') b++;
		else if(s[i]=='1'){
			if(i+1<n && s[i+1]=='1')
				a++,i++;
		}
	}

	cout<<nCrModPFermat(a+b,a,mod)<<"\n";
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