#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool comp(vector<int>&a,vector<int>&b){
	return a[1]<b[1];
}

void solve(){
	int n;cin>>n;

	vector<vector<int>>a(n,vector<int>(2));

	for(int i=0;i<n;i++){
		cin>>a[i][0]>>a[i][1];
	}

	sort(a.begin(),a.end(),comp);

	int ans=1,ed=a[0][1];

//	for(int i=0;i<n;i++) cout<<a[i][0]<<" "<<a[i][1]<<"\n";

	for(int i=1;i<n;i++){
		if(a[i][0]>=ed){
			ans++;
			ed=a[i][1];
		}
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