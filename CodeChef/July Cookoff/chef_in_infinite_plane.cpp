#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	int n;
	cin>>n;

	vector<int>a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	
	int prev=a[0],c=1,ans=0;
	for(int i=1;i<n;i++){
		if(prev==a[i]){
			c++;
		}
		else{
			ans=ans+min(prev-1,c);
			prev=a[i];
			c=1;
		}
	}
	ans=ans+min(prev-1,c);
	cout<<ans<<"\n";

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