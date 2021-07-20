#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


bool dfs(vector<int>adj[],int x,stack<int>&s,vector<bool>&v,vector<bool>&rec){
	v[x]=true;
	rec[x]=true;

	for(auto u:adj[x]){
		if(!v[u])
			if(dfs(adj,u,s,v,rec)) return true;

		if(rec[u]){
			return true;
		}
	}

	rec[x]=false;
	s.push(x);

	return false;
}

void solve(){
	int n,m;
	cin>>n>>m;

	vector<int>adj[n+1];
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;

		adj[u].push_back(v);
	}

	stack<int>s;
	vector<bool>v(n+1,false);
	vector<bool>res(n+1,false);

	for(int i=1;i<=n;i++){
		if(!v[i]){
			if(dfs(adj,i,s,v,res)){
				cout<<"IMPOSSIBLE"<<"\n";
				return;
			}
		}
	}

	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
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