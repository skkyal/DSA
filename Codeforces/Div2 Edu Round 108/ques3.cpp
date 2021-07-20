#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*bool prime[1000001];
void primeSieve(){ 
    memset(prime, true, sizeof(prime)); 
  	int n=100001;
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        {
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
} */

/*ll gcd(ll a,ll b){
	if (b == 0)
        return a;
    return gcd(b, a % b); 
}

ll lcm(ll a,ll b){
	return a*b/gcd(a,b);
}*/

/*void dijkstra(vector<pair<int,int> >adj[],int n,int x){
	vector<int>distance(n+1),processed(n+1);

	// 1-indexed
	for(int i=0;i<=n;i++){
		distance[i]=INT_MAX;
		processed[i]=0;
	}

	distance[x]=0;
	priority_queue<pair<int,int> >q;


	while(!q.empty()){
		int a=q.top().second; q.pop();

		if(processed[a]==1) continue;
		processed[a]=1;

		for(auto u: adj[a]){
			int b=u.first, w=u.second;

			if(distance[a]+w<distance[b]){
				distance[b]=distance[a]+w;
				q.push({-distance[b],b});
			}

		}

	}
}*/	


void solve(){
	ll n;
	cin>>n;
	vector<ll>s(n),u(n);

	for(ll i=0;i<n;i++) cin>>u[i];
	for(ll i=0;i<n;i++) cin>>s[i];

	vector<vector<ll>>a(n);

	for(ll i=0;i<n;i++){
		a[u[i]-1].push_back(s[i]);
	}
	

	for(ll i=0;i<n;i++){
		sort(a[i].begin(),a[i].end(),greater<ll>());
	}

	

	for(ll i=0;i<n;i++){
		if(a[i].size()<=1) continue;
		for(ll j=1;j<a[i].size();j++){
			a[i][j] += (ll)a[i][j-1];
		}
	}

	/*for(ll i=0;i<n;i++){
		for(ll j=0;j<a[i].size();j++){
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}*/

	
	vector<ll>ans(n,0);

	for(ll i=0;i<n;i++){
		for(ll j=1;j<=a[i].size();j++){
			ans[j-1]+=a[i][a[i].size()/j *j-1];
		}
	}

	for(ll i=0;i<n;i++) cout<<ans[i]<<" ";
	cout<<"\n";
}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("op.txt","w",stdout);
	#endif

	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//ios_base::sync_with_stdio(false);cin.tie(NULL);
	
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}