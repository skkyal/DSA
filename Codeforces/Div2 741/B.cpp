#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void ipop(){
	#ifndef ONLINE_JUDGE
		freopen("../input.txt","r",stdin);
		freopen("../op.txt","w",stdout);
	#endif
}

bool isPrime(ll x){
	ll n=sqrt(x);
	for(ll i=2;i<=n;i++){
		if(x%i==0)
			return false;
	}

	return true;
}
void solve(){
	ll n;
	string s;
	cin>>n;cin>>s;

	for(ll i=0;i<n;i++){
		if(s[i]=='1' || s[i]=='4' || s[i]=='6' || s[i]=='8' || s[i]=='9'){
			cout<<1<<"\n"<<s[i]<<"\n";
			return;
		}
	}

	for(ll i=0;i<n;i++){
		for(ll j=i+1;j<n;j++){
			//if(i==j) continue;
			string c;
			c.push_back(s[i]);
			c.push_back(s[j]);

			ll num = stoi(c);
			if(!isPrime(num)){
				cout<<2<<"\n"<<c<<"\n";
				return;
			}
		}
	}
}
 

int main() {
	ipop();

	int t=1,x=1;
	cin>>t;
	while(t--){
		//cout<<"Case #"<<x<<":"<<" ";
		x++;
		solve();
	}
}