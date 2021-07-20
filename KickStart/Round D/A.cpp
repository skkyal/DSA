#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll check(vector<vector<int>>&a){
	ll ans=0;
	if(a[1][1]*2==(a[0][1]+a[2][1]))
		ans++;
	if(a[1][1]*2==(a[1][0]+a[1][2]))
		ans++;
	if(a[1][1]*2==(a[0][0]+a[2][2]))
		ans++;
	if(a[1][1]*2==(a[0][2]+a[2][0]))
		ans++;
	return ans;
}

void solve(){
	vector<vector<int>>a(3,vector<int>(3,0));
	cin>>a[0][0]>>a[0][1]>>a[0][2]>>a[1][0]>>a[1][2]>>a[2][0]>>a[2][1]>>a[2][2];

	ll ans=0;
	if((a[0][0]+a[0][2])==a[0][1]*2) ans++;
	if((a[2][0]+a[2][2])==a[2][1]*2) ans++;
	if((a[0][0]+a[2][0])==a[1][0]*2) ans++;
	if((a[0][2]+a[2][2])==a[1][2]*2) ans++;

	ll temp=0;

	a[1][1]=(a[0][1]+a[2][1])/2;
	temp=max(check(a),temp);

	a[1][1]=(a[1][0]+a[1][2])/2;
	temp=max(check(a),temp);

	a[1][1]=(a[0][0]+a[2][2])/2;
	temp=max(check(a),temp);

	a[1][1]=(a[0][2]+a[2][0])/2;
	temp=max(check(a),temp);

	cout<<ans+temp<<"\n";
}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("op.txt","w",stdout);
	#endif

	
	int t=1,x=1;
	cin>>t;
	
	while(t--){
		cout<<"Case #"<<x<<":"<<" ";
		x++;
		solve();
	}
}