#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	int n,x;
	cin>>n>>x;
	vector<int>a(n);

	for(int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	
	int ans=0,l=0,r=n-1;
	//cout<<n<<" "<<x<<" ";
	while(l<r){
		if((a[l]+a[r])<=x){
			l++;r--;ans++;
		}
		else{
			r--;ans++;
		}
	}
	if(l==r){
		ans++;
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