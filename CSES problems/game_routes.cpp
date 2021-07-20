#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void topo(vector<int>adj[],int u,vector<bool>&vis,stack<int>&s){
	vis[u]=true;
	for(auto v:adj[u]){
		if(!vis[v])
			topo(adj,v,vis,s);
	}
	s.push(u);
}

void solve(){
	ll n,m,mod=1e9+7;
	cin>>n>>m;

	vector<int>adj[n+1];
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;

		adj[u].push_back(v);
	}

	stack<int>s;
	vector<bool>vis(n+1,false);

	topo(adj,1,vis,s);

	vector<int>ans(n+1,0);
	ans[1]=1;

	while(!s.empty()){
		int u=s.top();s.pop();
		//cout<<u<<" ";
		for(auto v:adj[u]){
			ans[v]=(ans[v]%mod+ans[u]%mod)%mod;
		}
	}
	//cout<<"\n";for(int i=1;i<=n;i++) cout<<ans[i]<<" ";cout<<"\n";
	cout<<ans[n];
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