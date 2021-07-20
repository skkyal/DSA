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

	int a=0,b=0;
	if(n%2==0) a++,n=n/2;
	if(n%2==0) a++,n=n/2;

	if(n%5==0) b++,n=n/5;
	if(n%5==0) b++,n=n/5;

	int x=100/(pow(2,a)*pow(5,b));

	cout<<x<<"\n";
}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("op.txt","w",stdout);
	#endif

	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//ios_base::sync_with_stdio(false);cin.tie(NULL);
	
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
}