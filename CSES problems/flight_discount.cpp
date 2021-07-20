#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//dijsktra here not semms to be a good option

void func(vector<pair<ll,ll>>adj[],ll n){
	vector<ll>d(n+1,LLONG_MAX);
	vector<ll>dis(n+1,LLONG_MAX);
	//vector<bool>v(n+1,0);

	priority_queue<vector<ll>>q;
	d[1]=0;
	dis[1]=0;

	q.push({0,1,0});

	while(!q.empty()){
		ll x=q.top()[1],y=-1*q.top()[0],f=q.top()[2];
		q.pop();

		if(((f==0) && (d[x]<y)) || ((f==1) && (dis[x]<y))) continue;
	
		for(ll i=0;i<adj[x].size();i++){
			ll u=adj[x][i].first,w=adj[x][i].second;

			if(f==0){
				if(d[u]>w+y){
					d[u]=w+y;
					q.push({-d[u],u,0});
				}
				if(dis[u]>w/2+y){
					dis[u]=w/2+y;
					q.push({-dis[u],u,1});
				}
			}
			else{
				if(dis[u]>w+y){
					dis[u]=w+y;
					q.push({-dis[u],u,1});
				}
			}
		}
	}
	cout<<dis[n];
}

void solve(){
	ll n,m;
	cin>>n>>m;

	vector<pair<ll,ll>>adj[n+1];

	for(ll i=0;i<m;i++){
		ll u,v,w;
		cin>>u>>v>>w;

		adj[u].push_back({v,w});
		//adj[v].push_back({u,w});
	}

	func(adj,n);
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