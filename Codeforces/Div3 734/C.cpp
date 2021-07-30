#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// to do
ll func(vector<vector<ll>>&a,ll n,vector<ll>temp){
	if(n==0) return 0;

	if(check(temp,a[n])) 
		return max(1+func(a,n-1,temp))
}
void solve(){
	ll n;cin>>n;

	vector<string>a(n);
	for(ll i=0;i<n;i++)
		cin>>a[i];

	vector<vector<ll>>s(n,vector<ll>(5,0));
	for(ll i=0;i<n;i++){
		for(ll j=0;j<a[i].size();j++){
			s[i][a[i][j]-'a']++;
		}
	}

	vector<ll>temp(5,0);
	cout<< func(s,n,temp)<<"\n";
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