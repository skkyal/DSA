#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	int n;
	cin>>n;

	vector<vector<ll>>a(n,vector<ll>(2));
	for(int i=0;i<n;i++) cin>>a[i][0]>>a[i][1];
	
	sort(a.begin(),a.end());

	priority_queue<ll,vector<ll>,greater<ll>>q;
	ll sum=0,ans=0;

	//for(int i=0;i<n;i++) cout<<a[i][0]<<" "<<a[i][1]<<"\n";

	for(int i=0;i<n;i++){
		q.push(a[i][1]);

		if(a[i][0]<=q.top()) {
			sum++;
			ans=max(ans,sum);
		}
		else {
			while(a[i][0]>q.top()){
				q.pop();
				sum--;
			}
			sum++;
		}
		//cout<<a[i][0]<<" "<<a[i][1]<<" "<<sum<<"\n";
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