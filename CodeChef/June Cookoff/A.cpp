#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	int n,q;
	cin>>n>>q;

	vector<int>a(n);
	for(int i=0;i<n;i++) cin>>a[i];

	sort(a.begin(),a.end());
	
	for(int i=0;i<q;i++){
		int x;cin>>x;

		auto it=lower_bound(a.begin(),a.end(),x);
		if(it==a.end()){
			if(n%2==0) cout<<"POSITIVE"<<"\n";
			else cout<<"NEGATIVE"<<"\n";
			continue;
		}

		int index = it-a.begin();

		if(a[index]==x){
			cout<<0<<"\n";
			continue;
		}	

		if(index%2==0)
			cout<<"POSITIVE"<<"\n";
		else cout<<"NEGATIVE"<<"\n";

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