#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++) 
		cin>>a[i];

	int m=n*1000;
	vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
	dp[0][0]=true;

	//for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cout<<dp[i][j]<<" ";
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			dp[i][j]=dp[i-1][j];
			if(j>=a[i-1] && dp[i-1][j-a[i-1]])
				dp[i][j]=true;
		}
	}	
	//cout<<n;
	vector<int>ans;

	for(int i=1;i<=m;i++) if(dp[n][i]) ans.push_back(i);

	sort(ans.begin(),ans.end());
	
	cout<<ans.size()<<"\n";
	for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
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