#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void ipop(){
	#ifndef ONLINE_JUDGE
		freopen("../input.txt","r",stdin);
		freopen("../op.txt","w",stdout);
	#endif
}

ll mod=1e9+7;

void dfs(vector<ll>adj[],vector<bool>&vis,ll u,vector<bool>&curr){
	vis[u]=true;
	curr[u]=true;

	for(auto v:adj[u]){
		if(!vis[v])
			dfs(adj,vis,v,curr);
	}
}

ll check(vector<ll>&A,vector<bool>&curr){
	vector<ll>a;

	for(ll i=1;i<=curr.size();i++){
		if(curr[i])
			a.push_back(A[i]);
	}

	sort(a.begin(),a.end());

	
}

void solve(){
	ll n,u,v;
	cin>>n;

	vector<ll>adj[n+1];
	vector<ll>a(n+1);

	for(ll i=1;i<=n-1;i++){
		cin>>u;v=i+1;
		adj[u].push_back(v);
	}

	for(ll i=1;i<=n;i++)
		cin>>a[i];

	vector<bool>vis(n+1,false);

	for(ll i=1;i<=n;i++){
		if(!vis[i]){
			vector<bool>curr(n+1,false);
			dfs(adj,vis,i,curr);

			ans+=check(a,curr);
		}
	}
}
 

int main() {
	ipop();

	int t=1,x=1;
	cin>>t;
	while(t--){
		//cout<<"Case #"<<x<<":"<<" ";
		x++;
		solve();
	}
}