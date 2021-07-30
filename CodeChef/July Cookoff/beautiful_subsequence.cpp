#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int func(vector<int>&a,int i,int n,int k,int prev,vector<vector<vector<int>>>&dp){
	if(i==n) return 0;
	//if() return 0;
	if(dp[i][k][prev+1]!=-1) return dp[i][k][prev+1];
	//if(prev==-1) return max(1+func(a,i+1,n,k,a[i]),func(a,i+1,n,k,prev));
	if(a[i]==prev)
		return dp[i][k][prev+1]=1+func(a,i+1,n,k,prev,dp);
	if(k==0)
		return dp[i][k][prev+1]=func(a,i+1,n,k,prev,dp);
	else 
		return dp[i][k][prev+1]=max(1+func(a,i+1,n,k-1,a[i],dp),func(a,i+1,n,k,prev,dp));
}
void solve(){
	int n,k;
	cin>>n>>k;

	vector<int>a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];

	vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(k+2,vector<int>(n+2,-1)));
	cout<<func(a,0,n,k+1,-1,dp)<<"\n";
}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("op.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
}