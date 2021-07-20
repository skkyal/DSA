#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	ll n;
	cin>>n;
	vector<ll>a(n),b(n);

	ll sum1=0,sum2=0;
	vector<pair<ll,ll>>ans;

	for(ll i=0;i<n;i++) cin>>a[i];
	for(ll i=0;i<n;i++) cin>>b[i];

	for(ll i=0;i<n;i++) {
		sum1+=a[i];
		sum2+=b[i];
	}

	if(sum1!=sum2){
		cout<<-1<<"\n";
		return;
	}

	for(ll i=0;i<n;i++){
		if(a[i]==b[i])
			continue;

		if(b[i]>a[i]){
			for(ll j=i+1;j<n;j++){
				if(a[j]>b[j]){
					while(a[j]!=b[j] && b[i]!=a[i]){
						a[i]++;
						a[j]--;
						ans.push_back({j+1,i+1});
					}
					if(a[i]==b[i]) break;
				}
			}
		}
		else{
			for(ll j=i+1;j<n;j++){
				if(a[j]<b[j]){
					while(a[j]!=b[j] && b[i]!=a[i]){
						a[i]--;
						a[j]++;
						ans.push_back({i+1,j+1});
					}
					if(a[i]==b[i]) break;
				}
			}
		}
		if(a[i]!=b[i]){
			cout<<-1<<"\n";
			return;
		}
	}
	cout<<ans.size()<<"\n";
	for(ll i=0;i<ans.size();i++){
		cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	}

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