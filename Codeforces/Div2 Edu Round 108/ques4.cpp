
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

ll check(vector<ll>&a, vector<ll>&b){
	ll n=a.size(),ans=0;
	for(ll i=0;i<n;i++) ans=ans+(a[i]*b[i]);
	return ans;
}

ll maxi(ll a,ll b){
	return a>b?a:b;
}

ll revcheck(vector<ll>a,vector<ll>&b,ll i,ll j){
	reverse(a.begin()+i,a.begin()+j+1);
	return check(a,b);
}	

void solve(){
	ll n;
	cin>>n;
	vector<ll>a(n),b(n),pr(n);

	for(ll i=0;i<n;i++) cin>>a[i];
	for(ll i=0;i<n;i++) cin>>b[i];

	for(ll i=0;i<n;i++){
		i==0?(pr[i]=a[i]*b[i]):(pr[i]=pr[i-1]+a[i]*b[i]);
	}

	ll  ans=pr[n-1];

	for(ll i=0;i<n;i++){
		ll c=a[i]*b[i];

		for(ll l=i-1,r=i+1; l>=0 && r<n; l--,r++){
			c+=a[l]*b[r]+a[r]*b[l];
			ll x=c+pr[n-1]-pr[r];
			x+=l-1>=0?pr[l-1]:0;

			ans=max(ans,x);
		}

		c=0;

		for(ll l=i,r=i+1;l>=0 && r<n;l--,r++){
			c+=a[l]*b[r]+a[r]*b[l];
			ll x=c+pr[n-1]-pr[r];
			x+=l-1>=0?pr[l-1]:0;

			ans=max(ans,x);
		}
	}


	cout<<ans<<"\n";
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