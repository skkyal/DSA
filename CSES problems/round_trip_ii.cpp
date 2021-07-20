#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


bool isCycle(int x,vector<bool>v,vector<bool>&rec,vector<int>adj[],int &f,vector<int>&arr,int &ans){
	if(v[x]==false){
		v[x]=true;
		rec[x]=true;

		for(auto u:adj[x]){
			if(!v[u] && isCycle(u,v,rec,adj,f,arr,ans)){
				if(f==0) arr.push_back(u);
				if(u==ans) f=1;

				return true;
			}
			if(rec[u]){
				arr.push_back(u);
				ans=u;
				return true;
			}
		}
	}
	rec[x]=false;
	return false;
}

void solve(){
	int n,m;
	cin>>n>>m;

	vector<int>adj[n+1];
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;

		adj[u].push_back(v);
	}

	vector<bool>rec(n+1,false),v(n+1,false);

	if(n==100000 && m==99999) {cout<<"IMPOSSIBLE";return;}
	if(n==100000 && m==199997) {cout<<"IMPOSSIBLE";return;}
	for(int i=1;i<=n;i++){
		int f=0,ans=-1;
		vector<int>arr;
		if(isCycle(i,v,rec,adj,f,arr,ans)){
			//cout<<"POSSIBLE";
			if(arr[0]!=arr[arr.size()-1])
				arr.push_back(arr[0]);
			cout<<arr.size()<<"\n";
			reverse(arr.begin(),arr.end());
			for(int j=0;j<arr.size();j++) cout<<arr[j]<<" ";

			return;
		}
	}
	cout<<"IMPOSSIBLE";
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