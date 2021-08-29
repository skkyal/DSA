#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	string s;ll x;
	cin>>s;cin>>x;

	sort(s.begin(),s.end());
	//ll i = 1;
    do {
        if (x==1) break;
        x--;
    } while (next_permutation(s.begin(), s.end()));

    cout<<s;
}
 

int main() {
	#ifndef ONLINE_JUDGE
		freopen("../input.txt","r",stdin);
		freopen("../op.txt","w",stdout);
	#endif
	
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}