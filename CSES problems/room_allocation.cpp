#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	int n;cin>>n;
	vector<vector<int>>a(n,vector<int>(3));
	for(int i=0;i<n;i++) {
		cin>>a[i][0]>>a[i][1];
		a[i][2]=i+1;
	}
	sort(a.begin(),a.end());

	int x=1;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q;
	vector<int>ans(n+1,0);

	q.push({a[0][1],1});
	ans[a[0][2]]=1;

	for(int i=1;i<n;i++){
		pair<int,int> p=q.top();
		if(a[i][0]>p.first){
			q.pop();
			ans[a[i][2]]=p.second;
			q.push({a[i][1],p.second});
		}
		else{
			x++;
			ans[a[i][2]]=x;
			q.push({a[i][1],x});
		}
	}
	
	cout<<*max_element(ans.begin(),ans.end())<<"\n";
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
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