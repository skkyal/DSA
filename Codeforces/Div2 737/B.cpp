#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

static bool comp(vector<ll>&a,vector<ll>&b)
{
	return a[0]<b[0];
}
void solve(){
	ll n,k;
	cin>>n>>k;

	vector<ll>a(n);
	//vector<int>f(1e5+1,0);
	//vector<vector<ll>>ans;
	map<ll,ll>f;
	for(ll i=0;i<n;i++) {
		cin>>a[i];
		f[a[i]]=1;
	}

	ll c=1;
	for(auto it=f.begin();it!=f.end();it++){
		it->second=c++;
		//cout<<it->first<<" "<<c<<"\n";
	}
	/*vector<ll>b;
	
	for(ll i=0;i<n;i++){
		if(i==0) b.push_back(a[i]);
		else if(a[i]>a[i-1]) b.push_back(a[i]);
		else{
			ans.push_back(b);
			b.clear();
			b.push_back(a[i]);
		}
	}
	ans.push_back(b);
	
	sort(ans.begin(),ans.end(),comp);

	for(ll i=0;i<ans.size();i++){
		for(ll j=0;j<ans[i].size();j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}

	ll prev;
	for(ll i=0;i<ans.size();i++){
		for(ll j=0;j<ans[i].size();j++){
			if(i==0 && j==0) prev=ans[i][j];
			else if(prev>ans[i][j]){
				cout<<"NO"<<"\n";
				return;
			}
			prev=ans[i][j];
		}
	}

	if(ans.size()>k){
		cout<<"NO"<<"\n";
		return;
	}

	cout<<"YES"<<"\n";*/
	ll x=1;
	for(ll i=1;i<n;i++){
		if(a[i-1]>a[i] || f[a[i]]-f[a[i-1]]>1)
			x++;
	}
	//cout<<x<<" ";
	cout<<(k>=x ? "YES" : "NO")<<"\n";
}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("op.txt","w",stdout);
	#endif
	
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
}