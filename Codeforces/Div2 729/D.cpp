#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod=998244353;
ll check(vector<ll>&s){
	ll n=s.size();
	priority_queue<ll,vector<ll>,greater<ll>>q;

	for(ll i=0;i<n;i++){
		if(s[i]==0){
			if(!q.empty())
				q.pop();
		}
		else{
			q.push(s[i]);
		}
	}

	ll sum=0;
	while(!q.empty()){
		sum=((sum%mod)+(q.top()%mod));
		q.pop();
	}

	return sum;
}

v

ll func(vector<ll>&a,vector<ll>&s,ll i,ll n,ll &sum){
	if(i==n){
		sum=((sum%mod)+check(s)%mod)%mod;
		return;
	}

	func(a,s,i+1,n,sum);
	s.push_back(a[i]);
	func(a,s,i+1,n,sum);
	s.pop_back();
}

void solve(){
	
	ll n;cin>>n;
	vector<ll>a(n);

	for(ll i=0;i<n;i++){
		char c;
		cin>>c;

		if(c=='-')  a[i]=0;
		else cin>>a[i];
	}

	ll sum=0;
	vector<ll>s;

	func(a,s,0,n,sum);
	cout<<sum;
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