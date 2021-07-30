#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	int n;
	cin>>n;

	vector<int>a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];

	int x=0;
	vector<int>b(32,1);
	for(int i=0;i<n;i++){
		for(int j=0;j<32;j++){
			b[j]=(b[j] & (a[i]>>j));
		}
		//cout<<"\n";
	}

	for(int i=0;i<32;i++) 
		x= (x | (b[i]<<i));
	//cout<<x<<"\n";
	int ans=0;
	for(int i=0;i<n;i++) 
		ans=ans|(a[i]^x);
	
	cout<<x<<" "<<ans<<"\n";
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