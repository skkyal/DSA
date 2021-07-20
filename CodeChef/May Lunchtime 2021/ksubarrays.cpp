#include<bits/stdc++.h>
using namespace std;
//typedef long long ll;

int func(vector<int>a,int n,int k,bool f){
	if(k==0) return 0;
	if(n==0) return INT_MIN;
	if(f==0)
		return max(a[n-1]*k+func(a,n-1,k,0),func(a,n-1,k-1,1));
	else
		return max(a[n-1]*k+func(a,n-1,k,0),func(a,n-1,k,1));
}
void solve(){
	int n,k;
	cin>>n>>k;

	vector<int>a(n,0);
	for(int i=0;i<n;i++) cin>>a[i];

	cout<<func(a,n,k,1)<<"\n";

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