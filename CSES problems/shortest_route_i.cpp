#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void dijkstra(vector<pair<ll,ll> >adj[],ll n,ll x){
	vector<ll>distance(n+1),processed(n+1);

	// 1-indexed
	for(ll i=0;i<=n;i++){
		distance[i]=LLONG_MAX;
		processed[i]=0;
	}

	distance[x]=0;
	priority_queue<pair<ll,ll> >q;
	q.push({0,x});

	while(!q.empty()){
		ll a=q.top().second; q.pop();

		if(processed[a]==1) continue;
		processed[a]=1;

		for(auto u: adj[a]){
			ll b=u.first, w=u.second;

			if(distance[a]+w<distance[b]){
				distance[b]=distance[a]+w;
				q.push({-distance[b],b});
			}

		}

	}
	for(ll i=1;i<=n;i++) cout<<distance[i]<<" ";
}
/*void dijkstra(vector<pair<int,int>>a[],vector<bool>&v,vector<int>&dis){
	dis[1]=0;
	//vis[1]=true;

	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;

	q.push({0,1});

	while(!q.empty()){
		int x=q.top().second;q.pop();
		if(v[x]) continue;
		v[x]=true;

		for(int i=0;i<a[x].size();i++){
			int v=a[x][i].first,w=a[x][i].second;
			if(dis[v]>dis[x]+w){
				dis[v]=dis[x]+w;
				q.push({dis[v],v});
			}
		}
	}
} */
void solve(){
	ll n,m;
	cin>>n>>m;

	vector<pair<ll,ll>>a[n+1];
	for(ll i=0;i<m;i++){
		ll u,v,w;
		cin>>u>>v>>w;

		a[u].push_back({v,w});
		//a[v].push_back({u,w});
	}

	//vector<bool>vis(n+1,false);
	//vector<int>dis(n+1,INT_MAX);

	dijkstra(a,n,1);

	//for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
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
