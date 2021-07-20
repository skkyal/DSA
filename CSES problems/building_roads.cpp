#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(vector<int>a[],vector<bool>&v,int x){
	v[x]=true;

	for(int i=0;i<a[x].size();i++){
		if(v[a[x][i]]==false)
			dfs(a,v,a[x][i]);
	}
}

void solve(){
	int n,m,ans=0,prev=0;
	cin>>n>>m;

	vector<int>a[n+1];
	for(int i=0;i<m;i++){
		int p,q;
		cin>>p>>q;
		a[p].push_back(q);
		a[q].push_back(p);
	}

	vector<bool>v(n+1,false);

	vector<pair<int,int>>b;
	for(int i=1;i<=n;i++){
		if(v[i]==false){
			b.push_back({prev,i});
			prev=i;
			ans++;
			dfs(a,v,i);
		}
	}
	cout<<ans-1<<"\n";

	for(int i=1;i<b.size();i++){
		cout<<b[i].first<<" "<<b[i].second<<"\n";
	}
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