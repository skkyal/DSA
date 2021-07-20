#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	int n,x;
	cin>>n;

	multiset<int>a;

	for(int i=0;i<n;i++){
		cin>>x;
		auto it=a.upper_bound(x);
		if(it==a.end()){
			a.insert(x);
		}
		else{
			a.erase(it);
			a.insert(x);
		}
	}

	cout<<a.size();
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