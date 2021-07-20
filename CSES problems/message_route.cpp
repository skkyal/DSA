#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void bfs(vector<int>a[],int n){
	vector<int>v(n+1,-1);
	//vector<int>parent(n+1,0);
	queue<int>q;
	q.push(1);
	v[1]=0;

	while(!q.empty()){
		int x=q.size();
		while(x--){
			int p=q.front();
			q.pop();

			for(int i=0;i<a[p].size();i++){
				if(v[a[p][i]]==-1){
					v[a[p][i]]=p;
					q.push(a[p][i]);
				}
			}
		}
	}

	//for(int i=1;i<=n;i++) cout<<v[i]<<" ";cout<<"\n";


	if(v[n]==-1){
		cout<<"IMPOSSIBLE";
		return;
	}

	vector<int>ans;
	int x=n;
	//ans.push_back(x);
	while(x!=0){
		ans.push_back(x);
		x=v[x];
	}

	cout<<ans.size()<<"\n";
	for(int i=ans.size()-1;i>=0;i--)
		cout<<ans[i]<<" ";

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
	bfs(a,n);

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