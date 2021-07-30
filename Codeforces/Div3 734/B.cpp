#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	string s;
	cin>>s;

	ll n=s.size();

	vector<ll>f(26,0);
	for(ll i=0;i<n;i++) f[s[i]-'a']++;

	ll a=0,b=0,k=2;
	
	for(ll i=0;i<26;i++){
		if(f[i]==0) continue;
		if(f[i]>=2) b++;
		else{
			a+=f[i];
			if(a>=k){
				b+=a/k;
				a=a%k;
			}
		}
	}
	
	/*else{
		for(ll i=0;i<26;i++){
			if(f[i]==0) continue;
			ll flag=0;
			if(f[i]>=2) {
				a++,b++;
				//flag=1;
			}
			else{
				if(a>b) b++;
				else a++;
			}
		}
	}*/

	cout<<b<<"\n";
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