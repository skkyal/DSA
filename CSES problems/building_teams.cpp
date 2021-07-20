#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool bfs(vector<int>a[],vector<bool>&v,int x,vector<int>&ans){
	v[x]=true;
	ans[x]=1;
	int count=1;
	queue<int>q;
	q.push(x);

	while(!q.empty()){
		int n=q.size();

		if(count==1) count=2;
		else count=1;

		while(n--){
			int i=q.front();q.pop();
			for(int j=0;j<a[i].size();j++){
				if(v[a[i][j]]==true && ans[a[i][j]]!=count){
					return false;
				}
				else if(v[a[i][j]]==false){
					v[a[i][j]]=true;
					ans[a[i][j]]=count;

					q.push(a[i][j]);
				}
			}
		}
	}
	return true;
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

	vector<bool>v(n+1,false);
	vector<int>ans(n+1);
	
	for(int i=1;i<=n;i++){
		if(v[i]==false){
			if(bfs(a,v,i,ans)==false){
				cout<<"IMPOSSIBLE";
				return;
			}
		}
	}

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