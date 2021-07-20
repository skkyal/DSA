#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//applying simply the dijskra would work here.
//dijkstra's giving tle

/*void func(vector<int>adj[],int n){
	vector<bool>v(n+1,false);
	vector<int>p(n+1,-1),dis(n+1,0);

	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	q.push({0,1});
	//dis[1]=0;

	while(!q.empty()){
		int x=q.top().second,d=q.top().first;
		q.pop();

		if(dis[x]<d) continue;

		for(auto u:adj[x]){
			if(dis[u]>dis[x]-1){
				dis[u]=dis[x]-1;
				q.push({dis[u],u});
				p[u]=x;
			}
		}
	}

	if(dis[n]==0){cout<<"IMPOSSIBLE";return;}
	//for(int i=1;i<=n;i++) cout<<p[i]<<" ";
	//cout<<-1*dis[n]+1<<"\n";

	vector<int>ans;
	for(int i=n;;i=p[i]){
		if(i==-1) break;
		ans.push_back(i);
	}

	cout<<ans.size()<<"\n";
	for(int i=ans.size()-1;i>=0;i--) cout<<ans[i]<<" "; 

}*/
void bfs(vector<int>adj[],int n){
	vector<bool>vis(n+1,false);
	vector<int>parent(n+1,-1);
	vector<int>dist(n+1,0);
	queue<int>q;

	
	dist[0]=1;
	vis[1]=true;
	int c=1;

	q.push(1);

	while(!q.empty()){
		int m=q.size();
		c++;
		while(m--){
			int u=q.front();q.pop();
			for(auto v:adj[u]){
				if(!vis[v]){
					dist[v]=c;
					parent[v]=u;
					vis[v]=true;
					q.push(v);
				}
				else if(dist[v]<c){
					dist[v]=c;
					parent[v]=u;
				}
			}
		}
	}

	//for(int i=1;i<=n;i++) cout<<parent[i]<<" ";cout<<"\n";


	if(!vis[n]) {cout<<"IMPOSSIBLE";return;}

	cout<<dist[n]+1<<"\n";

	vector<int>arr;
	for(int i=n;i!=-1;i=parent[i])
		arr.push_back(i);

	for(int i=arr.size()-1;i>=0;i--)
		cout<<arr[i]<<" ";
	
}

void solve(){
	int n,m;
	cin>>n>>m;

	vector<int>adj[n+1];
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;

		adj[u].push_back(v);
		//cout<<u<<" "<<v<<"\n";
	}
	bfs(adj,n);
	//func(adj,n);
}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("op.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}