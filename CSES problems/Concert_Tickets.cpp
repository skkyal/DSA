#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



void solve(){
	int n,m;
	cin>>n>>m;

	multiset<int,greater<int> >a;
	vector<int>b(m);

	for(int i=0;i<n;i++) {
		int x;
		cin>>x;
		a.insert(x);
	}
	for(int j=0;j<m;j++) cin>>b[j];

	//sort(a.begin(),a.end(),greater<int>());

	for(int i=0;i<m;i++){
		auto it=a.lower_bound(b[i]);
		if(it==a.end()){
			cout<<-1<<"\n";
		}
		else{
			cout<<*it<<"\n";
			a.erase(it);
		}
	}
	
}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("op.txt","w",stdout);
	#endif
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}