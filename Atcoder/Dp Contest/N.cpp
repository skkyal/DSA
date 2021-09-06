#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>>asd(2000,vector<int>(10000));

void ipop(){
	#ifndef ONLINE_JUDGE
		freopen("../input.txt","r",stdin);
		freopen("../op.txt","w",stdout);
	#endif
}

//map<vector<ll>,ll>m;

ll func(vector<ll>&a,ll n){
	if(n==1) return 0;

	ll ans=LLONG_MAX,idx=-1;

	for(ll i=0;i<n-1;i++){
		if(a[i]+a[i+1]<ans){
			ans=a[i]+a[i+1];
			idx=i;
		}
	}

	//for(ll i=0;i<n;i++) cout<<a[i]<<" ";cout<<"\n";

	a[idx+1]+=a[idx];
	for(ll i=idx+1;i<n;i++)
		swap(a[i-1],a[i]);

	return ans+func(a,n-1);
}

void solve(){
	ll n;cin>>n;
	vector<ll>a(n);
	for(ll i=0;i<n;i++) cin>>a[i];

	cout<<func(a,n);
}
 

int main() {
	ipop();

	int t=1,x=1;
	//cin>>t;
	while(t--){
		//cout<<"Case #"<<x<<":"<<" ";
		x++;
		solve();
	}
}