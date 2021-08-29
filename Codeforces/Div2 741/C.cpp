#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void ipop(){
	#ifndef ONLINE_JUDGE
		freopen("../input.txt","r",stdin);
		freopen("../op.txt","w",stdout);
	#endif
}

void solve(){
	ll n;string s;

	cin>>n;
	cin>>s;

	/*if(n==2){
		if(s[0]=='0'){
			cout<<1<<" "<<1<<" "<<1<<" "<<2<<"\n";
		}
		else if(s[1]=='0'){
			cout<<2<<" "<<2<<" "<<1<<" "<<2<<"\n";
		}
		else
			cout<<1<<" "<<1<<" "<<1<<" "<<2<<"\n";
		return;

	}*/
	for(ll i=0;i<n;i++){
		if(s[i]=='0'){
			if(i<n/2){
				cout<<i+1<<" "<<n<<" "<<i+2<<" "<<n<<"\n";
			}
			else{
				cout<<1<<" "<<i+1<<" "<<1<<" "<<i<<"\n";
			}
			return;
		}
	}

	cout<<1<<" "<<n-1<<" "<<2<<" "<<n<<"\n";
}
 

int main() {
	ipop();

	int t=1,x=1;
	cin>>t;
	while(t--){
		//cout<<"Case #"<<x<<":"<<" ";x++;
		solve();
	}
}