#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<int>a(n),b(m);

	for(int i=0;i<n;i++) cin>>a[i];
	for(int j=0;j<m;j++) cin>>b[j];

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	int i=0,j=0,ans=0;
	while(i<n && j<m){
		if(a[i]>=b[j]-k && a[i]<=b[j]+k) ans++,i++,j++;
		else if(a[i]<b[j]-k) i++;
		else if(a[i]>b[j]+k) j++;
	}
	
	cout<<ans;
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