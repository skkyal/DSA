#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n,m,q;

	cin>>n>>m>>q;

	vector<vector<ll>>adj(n+1,vector<ll>(n+1,LLONG_MAX));
	vector<vector<ll>>dist(n+1,vector<ll>(n+1));

	for(ll i=0;i<m;i++){
		ll u,v,w;
		cin>>u>>v>>w;

		adj[u][v]=min(adj[u][v],w);
		adj[v][u]=min(adj[v][u],w);
	}

	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= n; j++) {
			if (i == j) dist[i][j] = 0;
			else if (adj[i][j]) dist[i][j] = adj[i][j];
			else dist[i][j] = LLONG_MAX;
		}
	}

	for (ll k = 1; k <= n; k++) {
		for (ll i = 1; i <= n; i++) {
			for (ll j = 1; j <= n; j++) {
				if(dist[i][k]!=LLONG_MAX && dist[k][j]!=LLONG_MAX)
				dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}

	for(ll i=0;i<q;i++){
		ll u,v;
		cin>>u>>v;

		ll ans=dist[u][v]==LLONG_MAX?-1:dist[u][v];
		cout<<ans<<"\n";
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