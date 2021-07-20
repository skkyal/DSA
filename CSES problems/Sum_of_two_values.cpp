#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	int n,sum;cin>>n>>sum;

	vector<vector<int>>a(n,vector<int>(2));
	for(int i=0;i<n;i++){
		cin>>a[i][0];
		a[i][1]=i;
	}

	sort(a.begin(),a.end());
	int l=0,r=n-1;

	while(l<r){
		if(a[l][0]+a[r][0]==sum){
			cout<<a[l][1]+1<<" "<<a[r][1]+1;
			return;
		}
		else if(a[l][0]+a[r][0]>sum){
			r--;
		}
		else l++;
	}

	cout<<"IMPOSSIBLE";

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