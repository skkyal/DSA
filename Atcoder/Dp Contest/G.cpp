#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void ipop(){
	#ifndef ONLINE_JUDGE
		freopen("../input.txt","r",stdin);
		freopen("../op.txt","w",stdout);
	#endif
}

/* This function gives TLE
void func1(vector<ll>adj[],vector<bool>&vis,vector<ll>&dis,ll s){
	queue<ll>q;
	q.push(s);
	vis[s]=true;

	while(!q.empty()){
		ll u=q.front();
		q.pop();

		for(auto v:adj[u]){
			if(dis[v]<dis[u]+1){
				dis[v]=dis[u]+1;
				vis[v]=true;
				q.push(v);
			}
		}
	}
}*/

ll func(vector<ll>adj[],vector<bool>&vis,vector<ll>&dis,ll u){
	vis[u]=true;
	ll ans=0;

	if(dis[u]!=-1) return dis[u];

	for(auto v:adj[u]){
		ans=max(ans,func(adj,vis,dis,v)+1);
	}

	return dis[u]=ans;
}

void solve(){
	ll n,m,u,v,ans=0;
	cin>>n>>m;

	vector<ll>adj[n+1];
	for(ll i=0;i<m;i++){
		cin>>u>>v;
		adj[u].push_back(v);
	}

	vector<bool>vis(n+1,false);
	vector<ll>dis(n+1,-1);

	for(ll i=1;i<=n;i++){
		if(!vis[i])
		ans=max(ans,func(adj,vis,dis,i));
	}

	//for(ll i=0;i<n;i++) cout<<dis[i+1]<<" ";cout<<"\n";

	cout<<*max_element(dis.begin(),dis.end());
}
 

int main() {
	ipop();

	int t=1,x=1;
	//cin>>t;
	while(t--){
		//cout<<"Case #"<<x<<":"<<" ";
		//x++;
		solve();
	}
}