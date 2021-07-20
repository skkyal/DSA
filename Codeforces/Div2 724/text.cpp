#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	string b;
	for(ll j=1;j<=4;j++) b.push_back('a');
	int k=b.size()-1;
	for(int j=1;j<=pow(26,4);j++){
		cout<<b<<"\n";
		while(k>=0 && b[k]=='z'){
			b[k]='a';
			k--;
		}
		if(k<-1){
			break;
		}
		b[k]=b[k]+1;
		k=b.size()-1;
	}
}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("op.txt","w",stdout);
	#endif
	
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}