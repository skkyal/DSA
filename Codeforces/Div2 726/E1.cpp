#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	ll n,k;
	cin>>n>>k;

	string s;cin>>s;

	char c=s[0];
	ll i=1;
	for(;i<n;i++){
		if(s[i]<c)
			continue;
		else if(s[i]>c)
			break;
		
		else{
			ll p=i,f=0;
			for(ll j=0;j<i && p<n;j++){
				if(s[j]<s[p]){
					//cout<<j;
					f=1;
					break;
				}
				else if(s[p]<s[j]){
					break;
				}
				else p++;
			}
			if(p==n){f==1;break;}
			if(f==1) break;
			i=p-1;
		}

	}

	string a=s.substr(0,i);

	for(ll j=0;j<k;j++) cout<<s[j%i];cout<<"\n";
}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("op.txt","w",stdout);
	#endif

	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//ios_base::sync_with_stdio(false);cin.tie(NULL);
	
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}