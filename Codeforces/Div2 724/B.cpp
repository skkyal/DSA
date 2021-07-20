#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n;cin>>n;
	string s;cin>>s;

	for(ll i=1;i<=n;i++){
		map<string,int>m;
		for(ll j=0;j<=n-i;j++)
			m[s.substr(j,i)]=1;

		/*for(auto it=m.begin();it!=m.end();it++)
			cout<<(it->first)<<" ";*/

		//if(m.size()==pow(26,i)) continue;
		string b;
		for(ll j=1;j<=i;j++) b.push_back('a');

		ll k=b.size()-1;
		for(auto it=m.begin();it!=m.end();it++){
			//cout<<b<<" ";
			if(b!=it->first){
				cout<<b<<"\n";
				return;
			}
			while(k>=0 && b[k]=='z'){
				b[k]='a';
				k--;
			}
			if(k<=-1){
				break;
			}
			b[k]=b[k]+1;
			k=b.size()-1;
		}
		if(k>=0) {cout<<b<<"\n";return;}
	}
	for(ll i=0;i<=n;i++) cout<<'a';
		cout<<"\n";
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