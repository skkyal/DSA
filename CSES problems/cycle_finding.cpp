#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//give tle on large input
//should use belman ford algo


/*bool check(vector<pair<ll,ll>>&arr,int x){
	ll n=arr.size(),i=0;

	//for(int j=0;j<n;j++) cout<<arr[j].first<<" "<<arr[j].second<<"\n";

	while(i<n && arr[i].first!=x) i++;

	ll ans=0,j=i;
	while(i<n) {
		if(j!=i)
			ans+=arr[i].second;
		i++;
	}

	if(ans<0) {
		cout<<"YES"<<"\n";
		while(j<n) cout<<arr[j].first<<" ",j++;
		//cout<<x<<" "<<ans<<" ";
		return true;
	}
	return false;
}

bool func(vector<pair<ll,ll>>adj[],int n,int x,vector<bool>&v,vector<pair<ll,ll>>&arr){
	v[x]=true;

	int ans=false;
	for(int i=0;i<adj[x].size();i++){
		int a=adj[x][i].first,w=adj[x][i].second;

		arr.push_back({a,w});
		//if(v[a]) cout<<a<<" "<<"\n";
		if(v[a]){
			if(check(arr,a))
			return true;
		}
		else if(func(adj,n,a,v,arr)) return true;
		arr.pop_back();
		
	}

	v[x]=false;
	return false;
}

void solve(){
	int n,m;
	cin>>n>>m;

	vector<pair<ll,ll>>adj[n+1];
	for(int i=0;i<m;i++){
		ll u,v,w;cin>>u>>v>>w;
		adj[u].push_back({v,w});
	}
	vector<bool>v(n,false);
	

	for(ll i=1;i<=n;i++){
		vector<pair<ll,ll>>arr;
		arr.push_back({i,0});
		if(!v[i] && func(adj,n,i,v,arr))
			return;
	}

	cout<<"NO";
}*/

class Edge{
public:
	ll a,b,w;
};

void bellman_ford(vector<Edge>&edges,int n){
	vector<int>parent(n+1,-1);
	vector<ll>dist(n+1,0);

	int x;

	for(int i=1;i<=n;i++){
		x=-1;
		for(auto e:edges){
			ll u=e.a,v=e.b,d=e.w;

			if(dist[u]+d<dist[v]){
				dist[v]=dist[u]+d;
				parent[v]=u;
				x=v;
			}
		}
	}

	if(x==-1) cout<<"NO"<<"\n";
	else{
		//for(int i=1;i<=n;i++) x=parent[x];
		vector<int>ans;
		for(int v=x;;v=parent[v]){
			ans.push_back(v);
			if(v==x && ans.size()>1)
			break; 
		}
		reverse(ans.begin(),ans.end());

		cout<<"YES\n";
		for(int i=0;i<ans.size();i++)
			cout<<ans[i]<<" ";
	}
}

void solve(){
	int n,m;
	cin>>n>>m;

	vector<Edge>e(m);

	for(int i=0;i<m;i++){
		cin>>e[i].a>>e[i].b>>e[i].w;
	}
	bellman_ford(e,n);

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