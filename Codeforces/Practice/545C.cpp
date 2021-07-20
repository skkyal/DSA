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
ll lcm(ll a,ll b){return a*b/gcd(a,b);}*/

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

ll func(vector<ll>&x,vector<ll>&h,ll n,ll a,vector<ll>&dp){
	//if(a<=x[n]) return 0;
	if(n==0) return 1;
	if(n<0) return 0;

	if(dp[n]!=-1) return dp[n];

	ll p=0,q=0,r=0;

	if(x[n]+h[n]<a) p=1+func(x,h,n-1,x[n],dp);
	if(x[n]-h[n]>x[n-1]) q=1+func(x,h,n-1,x[n]-h[n],dp);
	r=func(x,h,n-1,x[n],dp);

	return dp[n]=max(p,max(q,r));
}
void solve(){
	ll n;
	cin>>n;

	vector<ll>x(n),h(n),dp(n,-1);
	for(ll i=0;i<n;i++) cin>>x[i]>>h[i];

	ll a=x[n-1];
	cout<<1+func(x,h,n-2,a,dp);
}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("op.txt","w",stdout);
	#endif

	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//ios_base::sync_with_stdio(false);cin.tie(NULL);
	
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}