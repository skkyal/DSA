#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n;
	cin>>n;
	if(n%3==0){
		cout<<n/3<<" "<<n/3<<"\n"; 
	}
	else if(n%3==1){
		cout<<n/3+1<<" "<<n/3<<"\n"; 
	}
	else{
		cout<<n/3<<" "<<n/3+1<<"\n"; 
	}
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