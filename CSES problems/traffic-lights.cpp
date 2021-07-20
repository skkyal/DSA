#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	int n,x,p;
	cin>>n>>p;

	set<int>s;
	multiset<int>m;

	s.insert(0);
	s.insert(n);

	m.insert(n);

	for(int i=0;i<p;i++){
		cin>>x;

		auto it1=s.upper_bound(x),it2=it1;it2--;
		m.erase(m.find(*it1-*it2));
		m.insert(x-*it2);m.insert(*it1-x);

		s.insert(x);

		
		cout<<*(m.rbegin())<<" ";
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