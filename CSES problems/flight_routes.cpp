#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void kthShotestPath(vector<pair<ll,ll>>adj[],ll n,ll k){
	ll INF=9e15;
	vector<vector<ll>>dist(n+1,vector<ll>(k,INF));
	dist[1][0]=0;
	priority_queue<pair<ll,ll>>q;

	q.push({0,1});

	while(!q.empty()){
		ll d=-1*q.top().first,u=q.top().second;
		q.pop();
		if(dist[u][k-1]<d) continue;

		for(auto e:adj[u]){
			ll v=e.first,w=e.second;

			if(dist[v][k-1]>d+w){
				dist[v][k-1]=d+w;
				q.push({-dist[v][k-1],v});
				sort(dist[v].begin(),dist[v].end());
			}
		}
	}

	for(ll i=0;i<k;i++) cout<<dist[n][i]<<" ";
}

void solve(){
	ll n,m,k;
	cin>>n>>m>>k;

	vector<pair<ll,ll>>adj[n+1];
	for(ll i=0;i<m;i++){
		ll u,v,w;
		cin>>u>>v>>w;

		adj[u].push_back({v,w});
	}

	kthShotestPath(adj,n,k);
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