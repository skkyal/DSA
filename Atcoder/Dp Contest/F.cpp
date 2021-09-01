#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void ipop(){
	#ifndef ONLINE_JUDGE
		freopen("../input.txt","r",stdin);
		freopen("../op.txt","w",stdout);
	#endif
}

/*ll func(string &a,string &b,ll n,ll m){
	if(n==0 || m==0) return 0;

	if(a[n-1]==b[m-1])
		return 1+func(a,b,n-1,m-1);
	return max(func(a,b,n-1,m),func(a,b,n,m-1));
}*/
void solve(){
	string a,b;
	cin>>a>>b;

	ll n=a.size(),m=b.size();
	vector<vector<ll>>dp(n+1,vector<ll>(m+1,0));

	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			if(a[i-1]==b[j-1])
				dp[i][j]=1+dp[i-1][j-1];
			else 
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}
	}

	//ll i=n,j=m;
	string ans;

	while(n>0 && m>0){
		if(a[n-1]==b[m-1]){
			ans+=a[n-1];
			n--;m--;
		}
		else{
			if(n-1>=0 && dp[n-1][m]==dp[n][m])
				n--;
			else if(m-1>=0 && dp[n][m-1]==dp[n][m])
				m--;
		}
	}
	reverse(ans.begin(),ans.end());
	cout<<ans;
}
 

int main() {
	ipop();

	int t=1,x=1;
	//cin>>t;
	while(t--){
		//cout<<"Case #"<<x<<":"<<" ";
		//x++;
		solve();
	}
}