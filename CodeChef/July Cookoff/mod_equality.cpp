#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	int n;
	cin>>n;

	vector<int>a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];

	sort(a.begin(),a.end());
	int x=a[0],i=1;

	for(;i<n;i++){
		if(a[i]!=x)
			break;
	}

	if(i==n){
		cout<<0<<"\n";
		return;
	}

	int ans=0;
	for(;i<n;i++){
		int y=(a[i]+1)/2-1;
		if(x>y){
			cout<<n<<"\n";
			return;
		}
		else ans++;
	}
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