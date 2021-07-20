#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool dfs(vector<int>a[],int x,vector<bool>&v,vector<int>&parent,int &s,int &e){
	v[x]=true;

	bool y=false;
	for(int i=0;i<a[x].size();i++){
		if(v[a[x][i]] && parent[x]!=a[x][i]){
			s=a[x][i];
			e=x;
			return true;
		}
		if(!v[a[x][i]]){
			parent[a[x][i]]=x;
			y=y||dfs(a,a[x][i],v,parent,s,e);
			if(y) return true;
		}
	}
	return false;
}

void solve(){
	int n,m;
	cin>>n>>m;

	vector<int>a[n+1];
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;

		a[u].push_back(v);
		a[v].push_back(u);
	}

	vector<bool>vis(n+1,false);
	vector<int>parent(n+1,0);
	int s,e;
	for(int i=1;i<=n;i++){
		if(!vis[i] && dfs(a,i,vis,parent,s,e)){
			//cout<<s<<" "<<e<<"\n";
			//for(int j=1;j<=n;j++) cout<<parent[j]<<" ";
			vector<int>ans;
			ans.push_back(s);
			while(e!=s){
				ans.push_back(e);
				e=parent[e];
			}
			ans.push_back(e);
			cout<<ans.size()<<"\n";
			for(int j=ans.size()-1;j>=0;j--) cout<<ans[j]<<" ";
			return;
		}
	}

	cout<<"IMPOSSIBLE";
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