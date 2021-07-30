#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
     
}

void solve(){
	int a,b;
	cin>>a>>b;

	if(gcd(a,b)!=1)
		cout<<0;
	else if((gcd(a+1,b)!=1)||(gcd(a,b+1)!=1))
		cout<<1;
	else cout<<2;

	cout<<"\n";
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