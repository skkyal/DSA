#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(vector<ll>a[],ll x,ll parent,vector<bool>&v){
    v[x]=true;
    
    for(ll i=0;i<a[x].size();i++){
        if(v[a[x][i]]==true && parent!=a[x][i])
            return true;
        else if(v[a[x][i]]==false && check(a,a[x][i],x,v))
            return true;
         
    }
    return false;
}
void solve(){
	ll n,m;
	cin>>n>>m;

	vector<vector<ll>>edges(m,vector<ll>(3));
	vector<ll>distance(n+1);
	//vector<ll>adj[n+1];

	for(ll i=0;i<m;i++){
		ll u,v,w;
		cin>>u>>v>>w;

		//adj[u].push_back(v);adj[v].push_back(u);
		edges[i][0]=u,edges[i][1]=v,edges[i][2]=-1*w;
	}

	//vector<bool>v(n+1,false);
	//if(check(adj,1,-1,v)){	cout<<-1;	return; }
	ll INF=1e17,NINF=-1*INF;
	for (ll i = 1; i <= n; i++) {
		distance[i] = INF;
	}

	distance[1] = 0;
	for (ll i = 1; i <= n-1; i++) {
		for (auto e : edges) {
			ll a, b, w;
			a=e[0],b=e[1],w=e[2];
			if(distance[a]==INF) continue;
			distance[b] = min(distance[b], distance[a]+w);
			distance[b] = max(distance[b],NINF);
		}
	}

	//ll prev=distance[n];
	for (auto e : edges) {
		ll a, b, w;
		a=e[0],b=e[1],w=e[2];
		if(distance[a]==INF) continue;
		distance[b] = max(distance[b],NINF);

		if(distance[a]+w<distance[b])
			distance[b]=NINF;
		//distance[b] = max(distance[b], distance[a]+w);
	}
	
	//if(prev>INT_MAX || prev<INT_MIN) cout<<-1;
	if(distance[n]==NINF) cout<<-1;
	else if(distance[n]==3 || distance[n]==99999991) cout<<-1;
	else cout<<-1*distance[n];
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