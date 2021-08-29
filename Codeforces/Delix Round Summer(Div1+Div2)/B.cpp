#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void ipop(){
	#ifndef ONLINE_JUDGE
		freopen("../input.txt","r",stdin);
		freopen("../op.txt","w",stdout);
	#endif
}

void solve(){
	ll n;
	cin>>n;

	vector<ll>a(n);
	for(ll i=0;i<n;i++) cin>>a[i];

	ll e=0,o=0;
	for(ll i=0;i<n;i++){
		if(a[i]%2==0) e++;
		else o++;
	}

	if(n%2==0 && e!=o){
		cout<<-1;
		return;
	}
	if(n%2==1 && abs(e-o)!=1){
		cout<<-1;
		return;
	}

	ll ans=0;
	vector<pair<ll,ll>>p,q;

	for(ll i=0;i<n;i++){
		if(a[i]%2==0) p.push_back({a[i],i});
		else q.push_back({a[i],i});
	}

	if(n%2==0){
		ll oi=0,ei=0,sum=0;
		for(ll i=0;i<n;i++){
			if(i%2==0){
				sum+=abs(p[ei].second-i);
				ei++;
			}
			else{
				sum+=abs(q[oi].second-i);
				oi++;
			}
		}
		ans=sum;
		oi=0,ei=0,sum=0;
		for(ll i=0;i<n;i++){
			if(i%2==1){
				sum+=abs(p[ei].second-i);
				ei++;
			}
			else{
				sum+=abs(q[oi].second-i);
				oi++;
			}
		}
		ans=min(ans,sum);

	}
	else{
		if(e>o){
			ll oi=0,ei=0;
			for(ll i=0;i<n;i++){
				if(i%2==0){
					ans+=abs(p[ei].second-i);
					ei++;
				}
				else{
					ans+=abs(q[oi].second-i);
					oi++;
				}
			}
		}else{
			ll oi=0,ei=0;
			for(ll i=0;i<n;i++){
				if(i%2==1){
					ans+=abs(p[ei].second-i);
					ei++;
				}
				else{
					ans+=abs(q[oi].second-i);
					oi++;
				}
			}
		}
	}

	cout<<ans/2;
}
 

int main() {
	ipop();

	int t=1,x=1;
	cin>>t;
	while(t--){
		//cout<<"Case #"<<x<<":"<<" ";x++;
		solve();
		cout<<"\n";
	}
}