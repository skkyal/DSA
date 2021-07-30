#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n,k;
	cin>>n>>k;

	vector<ll>a(n);
	for(ll i=0;i<n;i++) cin>>a[i];

	unordered_map<ll,ll>f;
	for(ll i=0;i<n;i++) f[a[i]]++;

	
	/*for(ll i=0;i<N;i++){
		if(f[i]==0) continue;
		if(f[i]>=k) ans++;
		else{
			x+=f[i];
			if(x>=k) {
				ans+=x/k;
				x=x%k;
			}
		}
	}*/

	ll c=0;
	unordered_map<ll,pair<ll,ll>>m;
	for(auto it=f.begin();it!=f.end();it++){
		if(it->second==0) continue;
		if(it->second>=k) {
			//ans++;
			m[it->first]={1,k};
			c+=it->second;
			it->second=0;

			//cout<<i<<" ";
		}
	}

	ll y=(n-c)%k,x=(n-c)-y,st=1;

	for(auto it=f.begin();it!=f.end();it++){
		if(it->second==0) continue;

		if(it->second<=x){
			m[it->first]={st,it->second};
			x-=it->second;
			//cout<<st<<" "<<i<<" "<<it->second<<" | ";
			st=(st+it->second)%k;
			if(st==0) st=k;
			
		}
		else{
			m[it->first]={st,x};
			//cout<<st<<" "<<i<<" "<<x<<" | ";
			break;
		}

	}

	vector<ll>ans(n,0);

	for(ll i=0;i<n;i++){
		if(m.find(a[i])==m.end()){
			cout<<0<<" ";
		}
		else{
			if(m[a[i]].second>0){
				cout<<m[a[i]].first<<" ";

				if(m[a[i]].first==k)
					m[a[i]].first=0;
				m[a[i]].first++;
				m[a[i]].second--;
			}
			else cout<<0<<" ";
		}
	}
	cout<<"\n";
}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("op.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
}