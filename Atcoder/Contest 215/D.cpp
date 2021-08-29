#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}

void solve(){
	ll n,m,c=1;
	cin>>n>>m;

	vector<ll>a(n);
	for(ll i=0;i<n;i++){
		cin>>a[i];
		c=lcm(c,a[i]);
	}

	vector<ll>ans;
	for(ll i=1;i<=m;i++){
		if(gcd(c,i)==1) ans.push_back(i);
	}

	cout<<ans.size()<<"\n";
	for(ll i=0;i<ans.size();i++)
		cout<<ans[i]<<"\n";
}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("../input.txt","r",stdin);
		freopen("../op.txt","w",stdout);
	#endif
	
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}